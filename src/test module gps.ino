#include "TinyGPS++.h"
#include "SoftwareSerial.h"

SoftwareSerial serial_connection(16,-1); 
TinyGPSPlus gps;//This is the GPS object that will pretty much do all the grunt work with the NMEA data
void setup()
{
  Serial.begin(115200);//This opens up communications to the Serial monitor in the Arduino IDE
  serial_connection.begin(9600);//This opens up communications to the GPS
  Serial.println("GPS Start");//Just show to the monitor that the sketch has started
  
}

void loop()
{
  boolean newData = false;
  //if(serial_connection.available())//While there are characters to come from the GPS
  //{
    /*Serial.println("y'a quelque chose qui marche");
    //gps.encode(serial_connection.read());//This feeds the serial NMEA data into the library one char at a time
    //Serial.println("Et alors ? Mais qu'est-ce que ça fait !");*/
    for (unsigned long start = millis(); millis() - start < 1000;)
      {
        while (serial_connection.available())
        {
          Serial.println("y'a quelque chose qui marche");
          char c = serial_connection.read();
          Serial.write(c); // uncomment this line if you want to see the GPS data flowing
          if (gps.encode(c)) // Did a new valid sentence come in?
            newData = true;
        }
      }    
    /*char c = serial_connection.read();
    Serial.write(c);
    /*Serial.print("On a recupere : ");
    Serial.println(c);/*
    if(c != -1)
    {*/
    /*  
    if(gps.encode(c) == true)
    {
      newData = true;
    }*/
      /*else
      {
        Serial.println("Encodage rate");
      }
      
    }
    else
    {
      Serial.println("La lecture a echoue");
    }
    
  }
  if(gps.location.isUpdated() == true)//This will pretty much be fired all the time anyway but will at least reduce it to only after a package of NMEA data comes in
  {*/
  //}
  if(newData)
  {
    newData = false;
    //Get the latest info from the gps object which it derived from the data sent by the GPS unit
    Serial.println("Satellite Count:");
    Serial.println(gps.satellites.value());
    Serial.println("Latitude:");
    Serial.println(gps.location.lat(), 6);
    Serial.println("Longitude:");
    Serial.println(gps.location.lng(), 6);
    Serial.println("Speed MPH:");
    Serial.println(gps.speed.mph());
    Serial.println("Altitude Feet:");
    Serial.println(gps.altitude.feet());
    Serial.println("");
    delay(10000);
  }
  
}