#include <Wire.h>
#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS 5

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

float Celcius = 0;
float Fahrenheit = 0;

int ldrA = 0;
int ldrB = 0;
int ldrC = 0;
int aDelay = 0;
int bDelay = 0;
int cDelay = 0;
int selsius = 0;
int pecahan = 0;
bool adaCangkang = false;

String dataKirim = " ";

void setup() {
 Wire.begin(8);                /* join i2c bus with address 8 */
 Wire.onReceive(receiveEvent); /* register receive event */
 Wire.onRequest(requestEvent); /* register request event */
 Serial.begin(9600);           /* start serial for debug */
 sensors.begin();
}

void loop() 
{
  ldrA = analogRead(A1);
  delay(100);
  ldrB = analogRead(A2);
  delay(100);
  ldrC = analogRead(A3);
  
  sensors.requestTemperatures(); 
  delay(1000);

  if(ldrA > 700)
  {
    aDelay++;
  }
  else
  {
    aDelay = 0;    
    adaCangkang = false;
  }

  if(ldrB > 700)
  {
    bDelay++;
  }
  else
  {
    bDelay = 0;
    adaCangkang = false;
  }

  if(ldrC > 700)
  {
    cDelay++;
  }
  else
  {
    cDelay = 0;
    adaCangkang = false;
  }

  if(bDelay > 10 || cDelay > 10)
  {
    adaCangkang = true;
    Serial.println("Ada cangkang woi");
  }

  Celcius = sensors.getTempCByIndex(0);
  Fahrenheit = sensors.toFahrenheit(Celcius);
  Serial.print(" C  ");
  Serial.print(Celcius);
  Serial.print(" F  ");
  Serial.print(Fahrenheit);

  Serial.print("   A  ");
  Serial.print(ldrA);
  Serial.print(" B  ");
  Serial.print(ldrB);
  Serial.print(" C  ");
  Serial.print(ldrC);

  selsius = (int)Celcius;
  pecahan = (Celcius - selsius) * 10;
  if(pecahan == 0)
  {
    pecahan = 1;
  }

  Serial.print("  ");
  Serial.print(selsius);
  Serial.print(".");
  Serial.print(pecahan);
  if(adaCangkang == true)
  {
    Serial.print("   Ada");
  }
  Serial.println(" |");

//  if(adaCangkang == true)
//  {
//    dataKirim = String("S" + (int)Celcius + "T" + "Y");  
//  }
//  else
//  {
//    dataKirim = String("S" + (int)Celcius + "T" + "N");
//  }
//
//  Serial.println(dataKirim);
}

// function that executes whenever data is received from master
void receiveEvent(int howMany) 
{
 while (0 <Wire.available()) {
    char c = Wire.read();      /* receive byte as a character */
    Serial.print(c);           /* print the character */
  }
 Serial.println();             /* to newline */
}

// function that executes whenever data is requested from master
void requestEvent() 
{
//  int hehe = (int)pecahan;
  Wire.write('S');
  Wire.print(selsius);
//  Wire.print(hehe);
  Wire.write('T');
  if(adaCangkang == true)
  {
    Wire.write('Y');
//    adaCangkang = false;
  }
  else
    Wire.write('N');

//  Wire.write("Hello NodeMCU");  /*send string on request */
}
