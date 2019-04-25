/*
 * WATER LEVEL SENSOR CODE
 * Written by: Elliott "pun-isher" Lao
 */


// ============================================================================
// DEFINES: constant values used in the code
// ============================================================================
#define RESISTOR 510 // the value of the series resistor   
#define SENSOR_PIN A0 // What pin to connect the sensor to
#define NUMBER_OF_WATER_LEVEL_SENSOR_READINGS 15 // number of water level sensor readings to take 
//WATER LEVEL EQUATION: cm_depth = (-0.497*Sensor_Val) + 457
#define LINEAR_MAPPING_MULTIPLIER -0.497 // multiplier for mapping sensor output to a water level
#define LINEAR_MAPPING_CONSTANT 457
// ****************************************************************************
// GLOBAL VARIABLES
// ****************************************************************************
float sensorReading[NUMBER_OF_WATER_LEVEL_SENSOR_READINGS] = {0};


// ****************************************************************************
// MAIN PROGRAM
// ****************************************************************************
void setup(void) {
  Serial.begin(9600);
}
 
void loop(void) {
  float reading;
  float waterLevel;

  reading = sensorRead();
 
  Serial.print("Analog reading "); 
  Serial.println(reading);

  waterLevel = valueMapping(reading);
  
  Serial.print("Actual water level "); 
  Serial.println(waterLevel);
  delay(500);
}

// ============================================================================
// sensorRead
//  - returns average value of sensor outputs 
// ============================================================================
float sensorRead(void){
  unsigned char i;
  float sum = 0; 
  for(i=0; i < NUMBER_OF_WATER_LEVEL_SENSOR_READINGS; i++){
      sensorReading[i] = analogRead(SENSOR_PIN);
      sum += sensorReading[i];
  }
  return(sum/NUMBER_OF_WATER_LEVEL_SENSOR_READINGS);
}

// ============================================================================
// valueMapping
//  - maps raw sensor data to usuable depth value in cm
// ============================================================================
float valueMapping(float rawData) {
  float mappedVal;

  mappedVal = rawData*LINEAR_MAPPING_MULTIPLIER+LINEAR_MAPPING_CONSTANT;
  return(mappedVal);
}