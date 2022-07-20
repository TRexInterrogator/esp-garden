#include "./MoistureData.h"


MoistureData::MoistureData() { }

MoistureData::MoistureData(int sensor_pin, String sensor_name) {
    this->_sensor_pin = sensor_pin;
    this->_sensor_name = sensor_name;
}


void MoistureData::Read(bool verbose) {
    this->_raw_value = analogRead(this->_sensor_pin);

    if (this->_raw_value >= MAX_WET && this->_raw_value <= MAX_DRY) {
        float calc_sensor = (100.0f / (float)(MAX_DRY - MAX_WET)) * (float)(MAX_DRY - this->_raw_value);
        this->_sensor_value = String(calc_sensor);
    }
    else {
        this->_sensor_value = "0";
    }

    if (verbose) {
        Serial.println("PLANT: " + this->_sensor_name + " - " + this->_sensor_value + "%");
    }
}


void MoistureData::Post() {
    HTTPClient http;
    String url = ENV::ENVVars::WEBHOOK + "/?accessoryId=" + this->_sensor_name + "&value=" + this->_sensor_value;

    http.begin(url);
    http.GET();
    http.end();
}