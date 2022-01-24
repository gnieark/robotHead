#ifndef MOVINGTFMINI_H
#define MOVINGTFMINI_H

#include <TFMini.h>
#include <Servo.h>
#include <SoftwareSerial.h>
#include "MovingTFMiniMeasure.h"

class MovingTFMini{
public:
	MovingTFMini(uint8_t servoPin, uint8_t lidarUartTxPin, uint8_t lidarUartRxPin){
		this->servoPin = servoPin;
		this->lidarUartTxPin = lidarUartTxPin;
		this->lidarUartRxPin = lidarUartRxPin;
		init();
	}
	void init(){
		this->serialTFMini = new SoftwareSerial (this->lidarUartRxPin, this->lidarUartTxPin); 
		this->servo.attach( this->servoPin ); 
		
		this->serialTFMini->begin(TFMINI_BAUDRATE);    //Initialize the data rate for the SoftwareSerial port
    this->tfmini.begin(this->serialTFMini);            //Initialize the TF Mini sensor
	}
	MovingTFMiniMeasure getMeasure(int angle){

		this->set_angle(angle);
		delay(25);
  		uint16_t dist = tfmini.getDistance();
  		uint16_t strength = tfmini.getRecentSignalStrength();
     MovingTFMiniMeasure movingTFMiniMeasure( angle, dist, strength );
		return movingTFMiniMeasure;

	}
private:
	int angle;
	int servoPin;
	Servo servo;
	int lidarUartTxPin;
	int lidarUartRxPin;
	SoftwareSerial *serialTFMini; 
	TFMini tfmini;

	void set_angle(int angle){
		this->angle = angle;
		servo.write(angle);
	}
};

#endif
