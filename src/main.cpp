#include <Arduino.h>

                    // A, B, C, D, E, F, G, DT
const int segPins[] = {3, 4, 5, 6, 7, 8, 9, 10};

const bool number[10][7] = {
//  A, B, C, D, E, F, G
  { 1, 1, 1, 1, 1, 1, 0 },  //  0
  { 0, 1, 1, 0, 0, 0, 0 },  //  1
  { 1, 1, 0, 1, 1, 0, 1 },  //  2
  { 1, 1, 1, 1, 0, 0, 1 },  //  3
  { 0, 1, 1, 0, 0, 1, 1 },  //  4
  { 1, 0, 1, 1, 0, 1, 1 },  //  5
  { 1, 0, 1, 1, 1, 1, 1 },  //  6
  { 1, 1, 1, 0, 0, 0, 0 },  //  7
  { 1, 1, 1, 1, 1, 1, 1 },  //  8
  { 1, 1, 1, 1, 0, 1, 1 }   //  9
};

void dispNumber(int n)
{
  for (int i = 0; i <= 6; i++) {
    digitalWrite(segPins[i], !number[n][i]);
  }
}

void setup()
{
  for (int i = 0; i <= 7; i++) {
    pinMode(segPins[i], OUTPUT);
    digitalWrite(segPins[i], HIGH);
  }
}

void loop()
{
  for (int n = 0; n <= 9; n++) {
    dispNumber(n);
    digitalWrite(segPins[7], HIGH);
    delay(500);
  }
  
  for (int n = 0; n <= 9; n++) {
    dispNumber(n);
    digitalWrite(segPins[7], LOW);
    delay(500);
  }
}
