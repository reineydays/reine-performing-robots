/* DC Motor Code */

#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"

Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 
Adafruit_DCMotor *motor1 = AFMS.getMotor(1);
Adafruit_DCMotor *motor2= AFMS.getMotor(4);


/* Bluefruit Code */

#include <string.h>
#include <Arduino.h>
#include <SPI.h>
#if not defined (_VARIANT_ARDUINO_DUE_X_) && not defined (_VARIANT_ARDUINO_ZERO_)
  #include <SoftwareSerial.h>
#endif

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
  while (!Serial);
  delay(500);
  Serial.begin(115200);
  Serial.println(F("Adafruit Bluefruit App Controller Example"));
  Serial.println(F("-----------------------------------------"));
  Serial.print(F("Initialising the Bluefruit LE module: "));
  if ( !ble.begin(VERBOSE_MODE) )
  {
    error(F("Couldn't find Bluefruit, make sure it's in CoMmanD mode & check wiring?"));
  }
  Serial.println( F("OK!") );
  if ( FACTORYRESET_ENABLE )
  {
    Serial.println(F("Performing a factory reset: "));
    if ( ! ble.factoryReset() ){
      error(F("Couldn't factory reset"));
    }
  }
  ble.echo(false);

  Serial.println("Requesting Bluefruit info:");
  /* Print Bluefruit information */
  ble.info();

  Serial.println(F("Please use Adafruit Bluefruit LE app to connect in Controller mode"));
  Serial.println(F("Then activate/use the sensors, color picker, game controller, etc!"));
  Serial.println();
  ble.verbose(false);  
  while (! ble.isConnected()) {
      delay(500);
  }
  Serial.println(F("******************************"));
  if ( ble.isVersionAtLeast(MINIMUM_FIRMWARE_VERSION) )
  {
    Serial.println(F("Change LED activity to " MODE_LED_BEHAVIOUR));
    ble.sendCommandCheckOK("AT+HWModeLED=" MODE_LED_BEHAVIOUR);
  }
  Serial.println( F("Switching to DATA mode!") );
  ble.setMode(BLUEFRUIT_MODE_DATA);
  Serial.println(F("******************************"));


/* Motor Setup Code */

AFMS.begin();

motor1->setSpeed(150);
motor1->run(FORWARD);
motor1->run(RELEASE);

motor2->setSpeed(150);
motor2->run(FORWARD);
motor2->run(RELEASE);

}


void loop(void)
{

  /* Wait for new data to arrive */
uint8_t len = readPacket(&ble, BLE_READPACKET_TIMEOUT);
  /* Got a packet! */
  // printHex(packetbuffer, len);

 uint8_t i;
  

  // Buttons
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
        motor1->setSpeed(150);
        motor1->run(BACKWARD);
        motor2->setSpeed(50);
        motor2->run(BACKWARD);
      }
      
      if (buttnum == 2) {
        motor1->setSpeed(150);
        motor1->run(FORWARD);
        motor2->setSpeed(50);
        motor2->run(FORWARD);
      }
      
      if (buttnum == 3) {
        motor1->setSpeed(200);
        motor1->run(BACKWARD);
        motor2->setSpeed(100);
        motor2->run(BACKWARD);
  }

      if (buttnum == 4) {
        
        motor1->setSpeed(200);
        motor1->run(FORWARD);
        motor2->setSpeed(150);
        motor2->run(FORWARD);
        
      }
      
      if (buttnum == 5) {
        motor1->setSpeed(150);
        motor1->run(FORWARD);
        motor2->setSpeed(150);
        motor2->run(FORWARD);

      }

      if (buttnum == 6) {

      }

      
      if (buttnum == 7) {

      }

      
      
      
    } else {
      motor1->run(RELEASE);
      motor2->run(RELEASE);
    }
  } 
}
