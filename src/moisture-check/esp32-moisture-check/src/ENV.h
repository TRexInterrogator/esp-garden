#include <Arduino.h>

#ifndef ENV_H
#define ENV_H

namespace ENV {
    class ENVVars {
        public:
            static String WEBHOOK;
            static String PLANT_NAME_01;
            static String PLANT_NAME_02;
            static char* SSID;
            static char* NET_PASSWD;
    };
}

#endif