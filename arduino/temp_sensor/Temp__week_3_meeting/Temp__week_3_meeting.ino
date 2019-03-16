#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS_A 2
#define ONE_WIRE_BUS_B 3
#define ONE_WIRE_BUS_C 4
#define ONE_WIRE_BUS_D 5
#define ONE_WIRE_BUS_E 6
#define ONE_WIRE_BUS_F 7

OneWire oneWire1(ONE_WIRE_BUS_A);
OneWire oneWire2(ONE_WIRE_BUS_B);
OneWire oneWire3(ONE_WIRE_BUS_C);
OneWire oneWire4(ONE_WIRE_BUS_D);
OneWire oneWire5(ONE_WIRE_BUS_E);
OneWire oneWire6(ONE_WIRE_BUS_F);

DallasTemperature sensors1(&oneWire1);
DallasTemperature sensors2(&oneWire2);
DallasTemperature sensors3(&oneWire3);
DallasTemperature sensors4(&oneWire4);
DallasTemperature sensors5(&oneWire5);
DallasTemperature sensors6(&oneWire6);

float Celcius1 = 0;
float Celcius2 = 0;
float Celcius3 = 0;
float Celcius4 = 0;
float Celcius5 = 0;
float Celcius6 = 0;
float Fahrenheit1 = 0;
float Fahrenheit2 = 0;
float Fahrenheit3 = 0;
float Fahrenheit4 = 0;
float Fahrenheit5 = 0;
float Fahrenheit6 = 0;
void setup(void)
{

  Serial.begin(9600);
  sensors1.begin();
  sensors2.begin();
  sensors3.begin();
  sensors4.begin();
  sensors5.begin();
  sensors6.begin();
}

void loop(void)
{
  sensors1.requestTemperatures();
  sensors2.requestTemperatures();
  sensors3.requestTemperatures();
  sensors4.requestTemperatures();
  sensors5.requestTemperatures();
  sensors6.requestTemperatures();
  Celcius1 = sensors1.getTempCByIndex(0);
  Celcius2 = sensors2.getTempCByIndex(0);
  Celcius3 = sensors3.getTempCByIndex(0);
  Celcius4 = sensors4.getTempCByIndex(0);
  Celcius5 = sensors5.getTempCByIndex(0);
  Celcius6 = sensors6.getTempCByIndex(0);
  /*  Fahrenheit1 = sensors1.toFahrenheit(Celcius);
  Fahrenheit2 = sensors2.toFahrenheit(Celcius);
  Fahrenheit3 = sensors3.toFahrenheit(Celcius);
  Fahrenheit4 = sensors4.toFahrenheit(Celcius);
  Fahrenheit5 = sensors5.toFahrenheit(Celcius);
  Fahrenheit6 = sensors6.toFahrenheit(Celcius); */
  Serial.print(" C  ");
  Serial.print(Celcius1);
  Serial.print(" C  ");
  Serial.print(Celcius2);
  Serial.print(" C  ");
  Serial.print(Celcius3);
  Serial.print(" C  ");
  Serial.print(Celcius4);
  Serial.print(" C  ");
  Serial.print(Celcius5);
  Serial.print(" C  ");
  Serial.println(Celcius6);
  /*Serial.print(" F  ");
  Serial.println(Fahrenheit); */
  delay(1000);
}
