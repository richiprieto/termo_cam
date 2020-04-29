/****************************************************************************** 
Basado en:
MLX90614_Serial_Demo.ino
Serial output example for the MLX90614 Infrared Thermometer

This example reads from the MLX90614 and prints out ambient and object 
temperatures every half-second or so. Open the serial monitor and set the
baud rate to 9600.

Hardware Hookup (if you're not using the eval board):
MLX90614 ------------- Arduino
  VDD ------------------ 3.3V
  VSS ------------------ GND
  SDA ------------------ SDA (A4 on older boards)
  SCL ------------------ SCL (A5 on older boards)
  

Jim Lindblom @ SparkFun Electronics
October 23, 2015
https://github.com/sparkfun/SparkFun_MLX90614_Arduino_Library

Development environment specifics:
Arduino 1.6.5
SparkFun IR Thermometer Evaluation Board - MLX90614
******************************************************************************/

#include <Wire.h> // I2C library, required for MLX90614
#include <SparkFunMLX90614.h> // SparkFunMLX90614 Arduino library

IRTherm therm; // Create an IRTherm object to interact with throughout

void setup() 
{
  Serial.begin(9600); // Inicializamos Serial
  therm.begin(); // Inicializamos el sensor 
  therm.setUnit(TEMP_C); // Seteamos a Centigrados la temperatura
}

void loop() 
{
  // Llamamos a therm.read para leer el objeto.
  if (therm.read()) // Retorna 1 si es exitoso, caso contrario 0.
  {
    // Usamos las funciones objeto y ambiente para medir temperatura
    Serial.print("Object: " + String(therm.object(), 2));
    Serial.write('°');
    Serial.println("C");
    Serial.print("Ambient: " + String(therm.ambient(), 2));
    Serial.write('°');
    Serial.println("C");
    Serial.println();
  }
  delay(500); // Lectura cada medio segundo
}
