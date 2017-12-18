#include <Wire.h>
#include <L3G.h>

L3G gyro;

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define PIN            6
#define NUMPIXELS      1
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int red = 0;
int green = 0;
int blue = 0;

int r;
int g;
int b;

int zaxis;

long xcal = 0;
long ycal = 0;
long zcal = 0;

long xavg, yavg, zavg;

long counter = 0;

void setup() {

  pixels.begin(); 

  Serial.begin(9600);
  Wire.begin();

  if (!gyro.init())
  {
    Serial.println("Failed to autodetect gyro type!");
    while (1);
  }

  gyro.enableDefault();

  int numberofreads = 100;
  Serial.println("Initialising calibration");
  while(counter < numberofreads){

    xcal += (int)gyro.g.x;
    ycal += (int)gyro.g.y;
    zcal += (int)gyro.g.z;
    counter ++;
    delay(10);
  }

 xavg = xcal / numberofreads;
 yavg = ycal / numberofreads;
 zavg = zcal / numberofreads;

 
}

void loop() {

  gyro.read();
//
//  Serial.print("G ");
//  Serial.print("X: ");
//  Serial.print(xavg - (int)gyro.g.x / 100);
//  Serial.print(" Y: ");
//  Serial.print(yavg - (int)gyro.g.y / 100);
//  Serial.print(" Z: ");
//  Serial.println(zavg - (int)gyro.g.z / 100);
  delay(30);


  int zaxis = (zavg - (int)gyro.g.z) / 100;

  g = map(constrain(zaxis, -327, 0), -327, 0, 255, 0);
  b = map(constrain(zaxis, 0, 327), 0, 327, 0, 255);
  r = map(constrain(zaxis, -327, 0), -327, 0, 255, 0);
  



  Serial.print(zaxis);
  Serial.print(" :: ");
  Serial.println(r);
  
 pixels.setPixelColor(0, pixels.Color(g,g,b)); 
 pixels.show();

}
