#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS_2 2
#define ONE_WIRE_BUS_3 3
#define ONE_WIRE_BUS_4 4
#define ONE_WIRE_BUS_5 5
#define ONE_WIRE_BUS_6 6
#define ONE_WIRE_BUS_7 7


OneWire oneWire2(ONE_WIRE_BUS_2);
OneWire oneWire3(ONE_WIRE_BUS_3);
OneWire oneWire4(ONE_WIRE_BUS_4);
OneWire oneWire5(ONE_WIRE_BUS_5);
OneWire oneWire6(ONE_WIRE_BUS_6);
OneWire oneWire7(ONE_WIRE_BUS_7);

OneWire wires[6] = {oneWire2, oneWire3, oneWire4, oneWire5, oneWire6, oneWire7};

DallasTemperature sensors(wires);

float Celcius = 0;
float Fahrenheit = 0;
void setup(void)
{

  Serial.begin(9600);
  sensors.begin();
}

void loop(void)
{
  sensors.requestTemperatures();
  Celcius = sensors.getTempCByIndex(0);
  Fahrenheit = sensors.toFahrenheit(Celcius);
  Serial.print(" C  ");
  Serial.print(Celcius);
  Serial.print(" F  ");
  Serial.println(Fahrenheit);
  delay(1000);
}
