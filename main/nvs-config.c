#include <m-string.h>
#include "nvs.h"
#include "nvs-config.h"

#define WIFI_MODE_KEY "wifi_mode"
#define WIFI_AP_SSID_KEY "wifi_ap_ssid"
#define WIFI_AP_PASS_KEY "wifi_ap_pass"
#define WIFI_STA_SSID_KEY "wifi_sta_ssid"
#define WIFI_STA_PASS_KEY "wifi_sta_pass"
#define WIFI_HOSTNAME "wifi_hostname"

#define ESP_WIFI_DEFAULT_SSID "blackmagic"
#define ESP_WIFI_DEFAULT_PASS "iamwitcher"
#define ESP_WIFI_DEFAULT_HOSTNAME "blackmagic"

esp_err_t nvs_config_set_wifi_mode(WiFiMode value) {
    mstring_t* mode = mstring_alloc();

    switch(value) {
    case WiFiModeAP:
        mstring_set(mode, CFG_WIFI_MODE_AP);
        break;
    case WiFiModeSTA:
        mstring_set(mode, CFG_WIFI_MODE_STA);
        break;
    case WiFiModeDisabled:
        mstring_set(mode, CFG_WIFI_MODE_DISABLED);
        break;
    }

    esp_err_t err = nvs_save_string(WIFI_MODE_KEY, mode);

    mstring_free(mode);
    return err;
}

esp_err_t nvs_config_set_ap_ssid(const mstring_t* ssid) {
    esp_err_t err = ESP_FAIL;

    if(mstring_size(ssid) > 0 && mstring_size(ssid) <= 32) {
        err = nvs_save_string(WIFI_AP_SSID_KEY, ssid);
    }

    return err;
}

esp_err_t nvs_config_set_ap_pass(const mstring_t* pass) {
    esp_err_t err = ESP_FAIL;

    if(mstring_size(pass) == 0 || (mstring_size(pass) >= 8 && mstring_size(pass) <= 64)) {
        err = nvs_save_string(WIFI_AP_PASS_KEY, pass);
    }

    return err;
}

esp_err_t nvs_config_set_sta_ssid(const mstring_t* ssid) {
    esp_err_t err = ESP_FAIL;

    if(mstring_size(ssid) > 0 && mstring_size(ssid) <= 32) {
        err = nvs_save_string(WIFI_STA_SSID_KEY, ssid);
    }

    return err;
}

esp_err_t nvs_config_set_sta_pass(const mstring_t* pass) {
    esp_err_t err = ESP_FAIL;

    if(mstring_size(pass) == 0 || (mstring_size(pass) >= 8 && mstring_size(pass) <= 64)) {
        err = nvs_save_string(WIFI_STA_PASS_KEY, pass);
    }

    return err;
}

esp_err_t nvs_config_set_hostname(const mstring_t* hostname) {
    esp_err_t err = ESP_FAIL;

    if(mstring_size(hostname) > 0 && mstring_size(hostname) <= 32) {
        err = nvs_save_string(WIFI_HOSTNAME, hostname);
    }

    return err;
}

esp_err_t nvs_config_get_wifi_mode(WiFiMode* value) {
    mstring_t* mode = mstring_alloc();
    esp_err_t err = nvs_load_string(WIFI_MODE_KEY, mode);

    if(err == ESP_OK && mstring_cmp_cstr(mode, CFG_WIFI_MODE_STA) == 0) {
        *value = WiFiModeSTA;
    } else if(err == ESP_OK && mstring_cmp_cstr(mode, CFG_WIFI_MODE_DISABLED) == 0) {
        *value = WiFiModeDisabled;
    } else {
        // AP mode by default
        *value = WiFiModeAP;
    }

    mstring_free(mode);
    return err;
}

esp_err_t nvs_config_get_ap_ssid(mstring_t* ssid) {
    esp_err_t err = nvs_load_string(WIFI_AP_SSID_KEY, ssid);

    if(err != ESP_OK) {
        mstring_set(ssid, ESP_WIFI_DEFAULT_SSID);
    }

    return err;
}

esp_err_t nvs_config_get_ap_pass(mstring_t* pass) {
    esp_err_t err = nvs_load_string(WIFI_AP_PASS_KEY, pass);

    if(err != ESP_OK) {
        mstring_set(pass, ESP_WIFI_DEFAULT_PASS);
    }

    return err;
}

esp_err_t nvs_config_get_sta_ssid(mstring_t* ssid) {
    esp_err_t err = nvs_load_string(WIFI_STA_SSID_KEY, ssid);

    if(err != ESP_OK) {
        mstring_set(ssid, ESP_WIFI_DEFAULT_SSID);
    }

    return err;
}

esp_err_t nvs_config_get_sta_pass(mstring_t* pass) {
    esp_err_t err = nvs_load_string(WIFI_STA_PASS_KEY, pass);

    if(err != ESP_OK) {
        mstring_set(pass, ESP_WIFI_DEFAULT_PASS);
    }

    return err;
}

esp_err_t nvs_config_get_hostname(mstring_t* hostname) {
    esp_err_t err = nvs_load_string(WIFI_HOSTNAME, hostname);

    if(err != ESP_OK) {
        mstring_set(hostname, ESP_WIFI_DEFAULT_HOSTNAME);
    }

    return err;
}
