/*
  Analog input, analog output, serial output

 Reads an analog input pin, maps the result to a range from 0 to 255
 and uses the result to set the pulsewidth modulation (PWM) of an output pin.
 Also prints the results to the serial monitor.

 The circuit:
 * potentiometer connected to analog pin 0.
   Center pin of the potentiometer goes to the analog pin.
   side pins of the potentiometer go to +5V and ground
 * LED connected from digital pin 9 to ground

 created 29 Dec. 2008
 modified 9 Apr 2012
 by Tom Igoe

 This example code is in the public domain.

 */

// These constants won't change.  They're used to give names
// to the pins used:
const int Pin0 = A0;  // Analog input pin that the potentiometer is attached to
const int Pin1 = A1;
const int Pin2 = A2;
const int Pin3 = A3;
const int input1 = 3;
const int input2 = 4;
const int input3 = 5;

int input1state, input2state, input3state;

int value0 = 0; 
int value1 = 0; 
int value2 = 0; 
int value3 = 0; // value read from the pot
int b0=0, b1=0, b2=0, b3=0;
int b = 0;
int a0=0, a1=0, a2=0;
int a=0;

void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
  pinMode (input1, INPUT);
  pinMode (input2, INPUT);
  pinMode (input3, INPUT);
  
}

void loop() {
  // read the analog in value:
  value0 = analogRead(Pin0);
  value1 = analogRead(Pin1);
  value2 = analogRead(Pin2);
  value3 = analogRead(Pin3);
 
    if (value0 > 400 ){
      b0 = 1;
    }
    else { b0 =0; }
    if (value1 > 400 ){
      b1 = 1;
    }
    else { b1 =0; }
    if (value2 > 400 ){
      b2 = 1;
    }
    else { b2 =0; }
    if (value3 > 400 ){
      b3 = 1;
    }
    else { b3 = 0; }

  b = b0 + 2*b1 +4*b2 + 8*b3;

  input1state = digitalRead(input1);
  input2state = digitalRead(input2);
  input3state = digitalRead(input3);

    if ( input1state == HIGH ){
      a0 = 1;
    }
    else { a0 = 0; }
     if ( input2state == HIGH ){
      a1 = 1;
    }
    else { a1 = 0; }
    if ( input3state == HIGH ){
      a2 = 1;
    }
    else { a2 = 0; }
  a = a0 + 2*a1 + 4*a2;  

  // print the results to the serial monitor:
  //Serial.print("val0 = ");
  //Serial.print(value0);
  //Serial.print("\t val1 = ");
  //Serial.print(value1);
  //Serial.print("\t val2 = ");
  //Serial.print(value2);
  //Serial.print("\t val3 = ");
  //Serial.print(value3);
  //Serial.print("\t number = ");
  //Serial.println(b);

  
  //int val0 = map(analogRead(Pin0),0, 1023, 0, 255);
  int x = 10*b + a;
  
  Serial.println(b); 
  delay(100);
  
}
