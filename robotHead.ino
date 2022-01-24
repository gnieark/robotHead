#include "MovingTFMiniMeasure.h"
#include "MovingTFMini.h"


uint8_t servoPin = 3;
uint8_t lidarUartTxPin = 4;
uint8_t lidarUartRxPin = 5;

int angle = 0;




void setup() {
  Serial.begin(115200); 
  Serial.println("begin...");
}


void loop() {
  MovingTFMini movingTFMini(servoPin, lidarUartTxPin, lidarUartRxPin);
  MovingTFMiniMeasure measure = movingTFMini.getMeasure(angle);
  int distance = measure.get_distance();
  Serial.println( distance );
  if( angle == 179 ){
   angle = 0;
 }
 angle++;
 delay(100);
}
