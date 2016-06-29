
const int Pin3=3;
const int Pin4=4;
const int Pin5=5;
const int Pin0=A0;
const int Pin1=A1;
const int Pin2=A2;

int Pin3state = LOW;
int Pin4state = LOW;
int Pin5state = LOW;


int value0 = 0; 
int value1 = 0; 
int value2 = 0; 


void setup() {
 Serial.begin(9600);
 pinMode ( Pin3, OUTPUT);
 pinMode ( Pin4, OUTPUT);
 pinMode ( Pin5, OUTPUT);
 
}

void loop() {
 value0 = analogRead(Pin0);
  value1 = analogRead(Pin1);
  value2 = analogRead(Pin2);

 if (value0 > 400 ){
      
      Pin3state = HIGH;
    }
    else {  
      Pin3state = LOW;
    }
    if (value1 > 400 ){
      
      Pin4state = HIGH;
    }
    else {  
      Pin4state = LOW;
    }
    if (value2 > 400 ){
      
      Pin5state = HIGH;
    }
    else {  
      Pin5state = LOW;
    }
  digitalWrite(Pin3, Pin3state);
  digitalWrite(Pin4, Pin4state);
  digitalWrite(Pin5, Pin5state);

  Serial.println(value1);
  
  delay(100);
 }

 
