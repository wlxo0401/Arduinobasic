import processing.serial.*;
Serial myPort;
PImage myImage1;
PImage myImage2;
long val = 0;
void setup(){
  //println(Serial.list());
  myPort = new Serial(this, "COM3", 9600);
  size(1920 ,1080);
  myImage1 = loadImage("navi1.png");
  myImage2 = loadImage("navi2.png");


}



void draw(){
  while(myPort.available() >= 2){
   if(myPort.read() == 0xff)
   {
     if(myPort.read() > 30)
     {
       print("30UP");
       image(myImage1, 0, 0, width, height);//3)
     }
     else
     {
       print("30DOWN");
       image(myImage2
       , 0, 0, width, height);//3)
     }
   }

  }
}
