#include <OneWire.h>
#include <DallasTemperature.h>
 
                                            // Data wire is plugged into pin 2 on the Arduino
#define ONE_WIRE_BUS 2
 
                                             // Setup a oneWire instance to communicate with any OneWire devices 
                                             // (not just Maxim/Dallas temperature ICs)
OneWire oneWire(ONE_WIRE_BUS);
                                             // Pass our oneWire reference to Dallas Temperature.
DallasTemperature sensors(&oneWire);
//Create necessary variables

float Temp1;
float Temp2;
float Temp3;
long CurrentTime;
float PrintTime=0;
float DataPointTime;

void setup(void)
{
                                           // start serial port
  Serial.begin(9600);
  Serial.println("Begin Data Aquisition");
                                           // Start up the library
  sensors.begin();
  
  sensors.requestTemperatures();
  Temp1 = sensors.getTempCByIndex(0)*(9/5)+32;
  Temp2 = sensors.getTempCByIndex(1)*(9/5)+32;
  Temp3 = sensors.getTempCByIndex(2)*(9/5)+32;  
  Serial.print(DataPointTime,2);
  Serial.print(", ");  
  Serial.print(Temp1,2);
  Serial.print(", ");                           
  Serial.print(Temp2,2);
  Serial.print(", ");    
  Serial.println(Temp3, 2);
}
 
 
void loop(void)
{
CurrentTime = millis();
                                           // call sensors.requestTemperatures() to issue a global temperature
                                          // Send the command to get temperatures
if(CurrentTime - PrintTime >= 10000 ){
  sensors.requestTemperatures();
  Temp1 = sensors.getTempCByIndex(0)*(9/5)+32;
  Temp2 = sensors.getTempCByIndex(1)*(9/5)+32;
  Temp3 = sensors.getTempCByIndex(2)*(9/5)+32;
  
  DataPointTime = PrintTime/1000+10;
  
  Serial.print(DataPointTime,2);
  Serial.print(", ");  
  Serial.print(Temp1,2);
  Serial.print(", ");                           
  Serial.print(Temp2,2);
  Serial.print(", ");    
  Serial.println(Temp3, 2);
  
  PrintTime = millis();
  }
                                            // You can have more than one IC on the same bus. 
                                            // 0 refers to the first IC on the wire
}





