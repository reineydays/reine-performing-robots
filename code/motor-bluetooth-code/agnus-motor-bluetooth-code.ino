#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"

Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 
Adafruit_DCMotor *motor1 = AFMS.getMotor(1);
Adafruit_DCMotor *center = AFMS.getMotor(2);
Adafruit_DCMotor *motor3 = AFMS.getMotor(4);

#include <string.h>
#include <Arduino.h>
#include <SPI.h>
#if not defined (_VARIANT_ARDUINO_DUE_X_) && not defined (_VARIANT_ARDUINO_ZERO_)
  #include <SoftwareSerial.h>
#endif


#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define PIN            3
#define NUMPIXELS      1


Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
//int delayval = 500;


#include "Adafruit_BLE.h"
#include "Adafruit_BluefruitLE_SPI.h"
#include "Adafruit_BluefruitLE_UART.h"
#include "BluefruitConfig.h"


    #define FACTORYRESET_ENABLE         0
    #define MINIMUM_FIRMWARE_VERSION    "0.6.6"
    #define MODE_LED_BEHAVIOUR          "MODE"


Adafruit_BluefruitLE_SPI ble(BLUEFRUIT_SPI_CS, BLUEFRUIT_SPI_IRQ, BLUEFRUIT_SPI_RST);


void error(const __FlashStringHelper*err) {
  Serial.println(err);
  while (1);
}

uint8_t readPacket(Adafruit_BLE *ble, uint16_t timeout);
float parsefloat(uint8_t *buffer);
void printHex(const uint8_t * data, const uint32_t numBytes);
extern uint8_t packetbuffer[];


void setup(void){

  pixels.begin(); 
  pixels.setPixelColor(0, pixels.Color(0,255,0)); 
  pixels.show();
  
  while (!Serial);
  delay(500);
  Serial.begin(115200);
  if ( !ble.begin(VERBOSE_MODE) )
  {
    error(F("Couldn't find Bluefruit, make sure it's in CoMmanD mode & check wiring?"));
  }
  if ( FACTORYRESET_ENABLE )
  {
    if ( ! ble.factoryReset() ){
      error(F("Couldn't factory reset"));
    }
  }
  ble.echo(false);
  ble.info();


  ble.verbose(false);  
  while (! ble.isConnected()) {
      delay(500);
  }
 
  if ( ble.isVersionAtLeast(MINIMUM_FIRMWARE_VERSION) )
  {  
    ble.sendCommandCheckOK("AT+HWModeLED=" MODE_LED_BEHAVIOUR);
  } 
  ble.setMode(BLUEFRUIT_MODE_DATA);

AFMS.begin();

motor1->setSpeed(100);
motor1->run(FORWARD);
motor1->run(RELEASE);


center->setSpeed(100);
center->run(FORWARD);
center->run(RELEASE);

motor3->setSpeed(100);
motor3->run(FORWARD);
motor3->run(RELEASE);


}

void loop(void){

uint8_t len = readPacket(&ble, BLE_READPACKET_TIMEOUT);
 uint8_t i;
  
  if (packetbuffer[1] == 'B') {
    uint8_t buttnum = packetbuffer[2] - '0';
    boolean pressed = packetbuffer[3] - '0';
    Serial.print ("Button "); Serial.print(buttnum);
    if (pressed) {
      Serial.println(" pressed");
    } else {
      Serial.println(" released");
    }

    if (pressed) {
      
      if (buttnum == 1) {
        motor1->setSpeed(100);
        motor1->run(FORWARD);

        center->setSpeed(200);
        center->run(FORWARD);
        
        motor3->setSpeed(100);
        motor3->run(BACKWARD);
           pixels.setPixelColor(0, pixels.Color(0,0,255)); 
            pixels.show();
        
      }
      if (buttnum == 2) {
        motor1->setSpeed(125);
        motor1->run(FORWARD);

        center->setSpeed(200);
        center->run(FORWARD);
        
        motor3->setSpeed(125);
        motor3->run(BACKWARD);
        pixels.setPixelColor(0, pixels.Color(0,0,255)); 
        pixels.show();
      
      }
      if (buttnum == 3) {
        motor1->setSpeed(200);
        motor1->run(FORWARD);

        center->setSpeed(200);
        center->run(FORWARD);
        
        motor3->setSpeed(200);
        motor3->run(BACKWARD);

        pixels.setPixelColor(0, pixels.Color(0,0,255)); 
        pixels.show();
  }

      if (buttnum == 4) {
        motor1->setSpeed(125);
        motor1->run(BACKWARD);

        center->setSpeed(200);
        center->run(FORWARD);
        
        motor3->setSpeed(125);
        motor3->run(FORWARD);

        pixels.setPixelColor(0, pixels.Color(0,0,255)); 
        pixels.show();
      }
      
      if (buttnum == 5) {
        motor1->setSpeed(125);
        motor1->run(RELEASE);

        center->setSpeed(200);
        center->run(FORWARD);
        
        motor3->setSpeed(125);
        motor3->run(RELEASE);

        pixels.setPixelColor(0, pixels.Color(0,0,255)); 
        pixels.show();
      }

      if (buttnum == 6) {
        motor1->setSpeed(125);
        motor1->run(RELEASE);

        center->setSpeed(200);
        center->run(RELEASE);
        
        motor3->setSpeed(125);
        motor3->run(BACKWARD);
      }

      if (buttnum == 7) {
        motor1->setSpeed(125);
        motor1->run(FORWARD);

        center->setSpeed(200);
        center->run(RELEASE);
        
        motor3->setSpeed(125);
        motor3->run(RELEASE);
      }

      if (buttnum == 8) {
        motor1->setSpeed(125);
        motor1->run(FORWARD);

        center->setSpeed(200);
        center->run(RELEASE);
        
        motor3->setSpeed(125);
        motor3->run(BACKWARD);
      }
      
    } else {
        motor1->setSpeed(125);
        motor1->run(RELEASE);

        center->setSpeed(200);
        center->run(FORWARD);
        
        motor3->setSpeed(125);
        motor3->run(RELEASE);
        pixels.setPixelColor(0, pixels.Color(0,0,0)); 
        pixels.show();
    }
  } 

}
