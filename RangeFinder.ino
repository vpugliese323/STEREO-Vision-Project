//Range finder hardware control code
//#include <Time.h>

void setup()
{
  pinMode(2, INPUT);//ECHO
  pinMode(4, OUTPUT);//TRIG
  Serial.begin(9600);
}

void loop()
{
  /*
  //int hightime = digitalRead(2);//signal bouncing off object
  //float distance = ((hightime)*(340))/2;//conversion to distance
  //the below is something general to test the sensor
  int hightime = pulseIn(2, HIGH);
  //digitalWrite(4, HIGH);
  delay(10);
  Serial.println(hightime);
  */
  
  long int instructions = 0;

  //time_t secs1 = now();
  //time_t secs2;
  
  //while (!digitalRead(2))//if pin 2 is not HIGH...
 /* while(1)
  {
    digitalWrite(4, HIGH);
    delay(1);
    instructions++;
    //if (instructions >= 16000000)
    if (instructions >= 16000000)
    {
      break;
    }
    if (digitalRead(2))
    {
      break;
    }
  }*/
    //should yeild error of less than (+/-) 100 instructions/clock cycle
    
  int duration = pulseIn(2, HIGH);
  digitalWrite(4, HIGH); 
  delay(500);
  //double milliseconds = instructions*(0.016);
  double distance = ((duration)*(340.0)/(2000));
  Serial.println(distance);
}
