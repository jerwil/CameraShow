#include <math.h>

int latchPin = 1;
int clockPin = 2;
int dataPin = 0;
float delay_int = 100;
int bit_shift_values[8] = {1,128,64,32,16,2,4,8};


void setup() {                
  //set pins to output so you can control the shift register
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);

}


void loop() {   

for (int LED = 0; LED < 8; LED++) {
shiftValue(bit_shift_values[LED]);
delay(delay_int);
} 

}


void shiftValue(int value) {
  // take the latchPin low so
  // the LEDs don't change while you're sending in bits:
  digitalWrite(latchPin, LOW);
  // shift out the bits:
  shiftOut(dataPin, clockPin, MSBFIRST, value);
  //take the latch pin high so the LEDs will light up:
  digitalWrite(latchPin, HIGH);
}

