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
float CurrentTime;
float PrintTime=0;
float DataPointTime;

void setup(void)
{
                                           // start serial port
  Serial.begin(9600);
  Serial.println("Begin Data Acquisition");
                                           // Start up the library
  sensors.begin();

 Serial.print("Time");
  Serial.print(", ");  
  Serial.print("Temp1");
  Serial.print(", ");                           
  Serial.print("Temp2");
  Serial.print(", ");    
  Serial.println("Temp3");
  
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
  //Request Temperatures
  sensors.requestTemperatures();
  //Assign temperatures and convert to fahrenheit
  Temp1 = sensors.getTempCByIndex(0)*(9/5)+32;
  Temp2 = sensors.getTempCByIndex(1)*(9/5)+32;
  Temp3 = sensors.getTempCByIndex(2)*(9/5)+32;
  
  //Convert Data point time into seconds
  DataPointTime = PrintTime/1000+10;     

  //Print Data
  Serial.print(DataPointTime,2);
  Serial.print(", ");  
  Serial.print(Temp1,2);
  Serial.print(", ");                           
  Serial.print(Temp2,2);
  Serial.print(", ");    
  Serial.println(Temp3, 2);
  
  PrintTime = millis();
  }
                                           
}





