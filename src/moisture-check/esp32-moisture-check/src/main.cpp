#include <Arduino.h>
#include <WiFi.h>
#include "ENV.h"
#include "./MoistureData/MoistureData.h"

using namespace ENV;

#define SENSOR_01 33
#define SENSOR_02 32
#define REFRESH_RATE 60000



void setup() {
    Serial.println("");
    Serial.begin(9600);
    Serial.println("Connecting to wifi network ..");

    WiFi.begin(ENVVars::SSID, ENVVars::NET_PASSWD);

    while (WiFi.status() != WL_CONNECTED) {
        delay(600);
    }

    Serial.println("Connected to network.");
    Serial.println("IP: " + WiFi.localIP().toString());
}


void loop() {
    if (WiFi.status() == WL_CONNECTED) {
        MoistureData sensor_01(SENSOR_01, ENVVars::PLANT_NAME_01);
        MoistureData sensor_02(SENSOR_02, ENVVars::PLANT_NAME_02);

        sensor_01.Read(true);
        sensor_02.Read(true);

        sensor_01.Post();
        sensor_02.Post();
    }

    delay(REFRESH_RATE);
}