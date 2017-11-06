#include "p9813.h"
// Define the writeColor method.
void p9813::writeColor(uint8_t r,uint8_t g,uint8_t b){
    uint32_t Data_byte=0;        // prepare the 32bit array.
    uint8_t i;
    //Clear the Register
    digitalWrite(sda,0);
    for(i=0;i<32;i++){
        digitalWrite(scl,0);
        digitalWrite(scl,1);

    }
    Data_byte|=0xc0000000;                           //set the first and second bit as 1
    Data_byte|=((uint32_t)((~b)&0xc0))<<22;
    Data_byte|=((uint32_t)((~g)&0xc0))<<20;
    Data_byte|=((uint32_t)((~r)&0xc0))<<18;
    Data_byte|=((uint32_t)b)<<16;
    Data_byte|=((uint32_t)g)<<8;
    Data_byte|=((uint32_t)r);
    for(i=0;i<32;i++){
        digitalWrite(sda,((Data_byte>>(31-i))&0x1)); // Prepare the data before scl
        digitalWrite(scl,0);
	delay(10);                                   // The p9813 IC is slowly, so must delay to wait to write the data.
        digitalWrite(scl,1);
	delay(10);
    }
    
}

void p9813::init(){
    pinMode(scl,OUTPUT);
    pinMode(sda,OUTPUT);
}
