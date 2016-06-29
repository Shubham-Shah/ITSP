import processing.serial.*;

Serial port;
float x=0;
float b = 0;
float a = 0;
float right, bottom;
float y1, y2, x1, x2;
boolean start=true;

void setup(){
  size(1000, 500);
  //frameRate(10);
  background(0);
  port = new Serial(this,"COM3", 9600);  
  port.bufferUntil('\n');
}

void draw() {
 // background(255);
  //stroke(0);
  //rect(110,250,100,200);

  //if (0<port.available()){
   // b =float( port.readStringUntil('\n'));
  
  //rect(400,250,b*10,b+10);
  
  right = x%10;
  bottom = (x - x%10)/10;
  if(right > 0 & bottom > 0){
  a = 500 - (x%10)*50 ;
  b= ((x-x%10)/10)*50;
  x1=b;
  y1=a;
  
  if(start){
    x2=x1;
    y2=y1;
    start=false;
  }
  else{
    stroke(255);
    // rect ( 40*b,250,5, 5);
    //rect ( b,a,5, 5);
    line( x1, y1, x2, y2);
    x2=x1;
    y2=y1;
    }
  }
 }
 
 void serialEvent (Serial port)
 {
  if (0<port.available()){
  x = float(port.readStringUntil('\n'));
  }
 }