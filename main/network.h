/**
 * @file network.h
 * @author Sergey Gavrilov (who.just.the.doctor@gmail.com)
 * @version 1.0
 * @date 2021-11-21
 * 
 * Network API
 */
#pragma once
#include <stdbool.h>
#include <esp_netif.h>
#include "nvs-config.h"

extern esp_netif_t* sta_netif;
extern esp_netif_t* ap_netif;

/**
 * Init network module
 * @return WiFiMode
 */
WiFiMode network_init(void);

/**
 * Returns current WIFI mode
 * @return WiFiMode 
 */
WiFiMode network_get_mode(void);

/**
 * Get current IP address
 * @return uint32_t 
 */
uint32_t network_get_ip(void);

/**
 * Get pointer to netif structure
 * @return esp_netif_t*
 */
esp_netif_t* network_get_netif(void);

