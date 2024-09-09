#pragma once

#include "Arduino.h"

class Altimeter
{
public:
    Altimeter(uint8_t Pin1, uint8_t Pin2);
    void begin();
    void attach(uint16_t Pin3, char *init);
    void detach();
    void set(int16_t messageID, char *setPoint);
    void update();

private:
    bool    _initialised;
    uint8_t _pin1, _pin2, _pin3;
    float altitude = 0;         // altitude value from the simulator
    float baro = 29.92;             // barometric pressure value from the simulator
    int tenThousand = 0;        // ten thousands value
    int thousand = 0;           // thousands value
    int hundred = 0;            // hundreds value
    float angleTenThousand = 0; // angle for the 10,000 pointer
    float angleThousand = 0;    // angle for the 1,000 needle
    float angleHundred = 0;     // angle for the 100 needle
    float angleBaro = 0;        // angle of the of the baro indicator base on the baro value
    int baroMode = 0;     //baro mode, 0 = inHG, 1 = hpa, others default to inHG
    int prevBaroMode = 0;
    int instrumentBrightness = 255;            // instrument brightness based on ratio. Value between 0 - 255
    float instrumentBrightnessRatio = 0; // previous value of instrument brightness. If no change do not set instrument brightness to avoid flickers
    bool powerSaveFlag = false;
    int screenRotation = 3;
    int prevScreenRotation = 3;

    // Function declarations
    void drawAll();
    float scaleValue(float x, float in_min, float in_max, float out_min, float out_max);
    void setAltitude(float value);
    void setBaro(float value);
    void setInstrumentBrightnessRatio(float ratio);
    void setBaroMode(int mode);
    void setPowerSave(bool enabled);
    void setScreenRotation(int rotation);

};