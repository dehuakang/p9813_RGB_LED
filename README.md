This program is used for light the RGB led breakout drived by p9813 IC.
The breakout has only one RGB led.
The breakout has 4 pins: + - cin din. And this breakout communicates with arduino 
using IIC bus. 
The circuit:
  cin is the scl should be connected to the digital pin on Arduino.
  din is the sda should be connected to the digital pin on Arduino.
Example: cin->D8
         din->D9
         +  ->VCC 5.0V
         -  ->GND
Example code:
        #include <p9813.h>
        p9813 p=p9813(8,9);
        void setup(){
	   p.init();
        }
	void loop(){
	   p.writeColor(255,0,0)  //red    [0 255]
	   delay(1000);
        }

Create Oct 24 2017 by Kang Dehua.
