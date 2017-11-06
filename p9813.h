#ifndef p9813_h
#define p9813_h
#include <Arduino.h>
class p9813{
public:
    p9813(int CIN,int DIN):scl(CIN),sda(DIN){
        // Constructor.
    }
    void writeColor(uint8_t r,uint8_t g,uint8_t b);  // Write color the the device.
    void init();  // Initial the pinMode
private:
    int scl,sda;   // cin din
};


#endif



