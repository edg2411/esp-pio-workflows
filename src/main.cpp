#include <Arduino.h>
#include <WiFi.h>
#include "secrets.h"

// OTA Hub via GitHub
#define OTAGH_OWNER_NAME "edg2411"
#define OTAGH_REPO_NAME "esp-pio-workflows"
#include <OTA-Hub-diy.hpp>

// Networking
#include <WiFiClientSecure.h>
WiFiClientSecure wifi_client;

void setup()
{
    // Initialise our board
    Serial.begin(115200);
    Serial.println("Started...");

    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
    Serial.print("Connecting to WiFi");
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        Serial.print(".");
    }
    Serial.println();
    Serial.print("Connected! IP address: ");
    Serial.println(WiFi.localIP());

    // Initialise OTA
    wifi_client.setCACert(OTAGH_CA_CERT); // Set the api.github.cm SSL cert on the WiFi Client
    OTA::init(wifi_client);

    // Check OTA for updates
    OTA::UpdateObject details = OTA::isUpdateAvailable();
    details.print(); // Super useful for debugging!
    if (OTA::NO_UPDATE != details.condition)
    {
        // Perform OTA update
        OTA::InstallCondition result = OTA::performUpdate(&details);
        // GitHub hosts files on different server, so we have to follow the redirect, unfortunately.
        if (result == OTA::REDIRECT_REQUIRED)
        {
            wifi_client.setCACert(OTAGH_REDIRECT_CA_CERT); // Set the objects.githubusercontent.com SSL cert
            OTA::continueRedirect(&details);
        }
    }
    else
    {
        Serial.println("No new update available. Continuing...");
    }
    Serial.print("Loop");
}

void loop()
{
    delay(5000);
    Serial.print("edy loop");
}