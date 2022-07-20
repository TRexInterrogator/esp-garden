#include <Arduino.h>
#include <HTTPClient.h>
#include "../env.h"


#ifndef MOISTUREDATA_H
#define MOISTUREDATA_H
#define MAX_DRY 2850
#define MAX_WET 940

class MoistureData {
    private:
        int _sensor_pin;
        int _raw_value;
        String _sensor_name;
        String _sensor_value;

    public:
        MoistureData();
        MoistureData(int sensor_pin, String sensor_name);
        void Read(bool verbose = false);
        void Post();
};

#endif