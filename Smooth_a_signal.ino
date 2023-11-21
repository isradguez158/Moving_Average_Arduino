 #include "MovingAverage.h" //MovingAverager
  MovingAverage filter(12);

double filteredOutput;
long randomNumber;


long t = 0;
float r = 0;
float avg = 0;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  t = micros();
  r = 1.0 * sin(6.0 * t / 1000000.0)+0.50*(random(0, 100)/100.0);
  avg= mAvg(r);
  Serial.print("result: ");
  Serial.print(r);
  Serial.print(" result: ");
  Serial.println(5+avg);
  delay(10);

}

float mAvg(float x){
  
  /* Begin
  #include "MovingAverage.h"
  MovingAverage filter(12);
  */
  
  float avg=filter.addSample(x);
  return avg;
  }
