//Range finder hardware control code
//Code modified from: http://www.instructables.com/id/Simple-Arduino-and-HC-SR04-Example/?ALLSTEPS
//User: jsvester

void setup()
{
  pinMode(2, INPUT);//ECHO
  pinMode(4, OUTPUT);//TRIG
  Serial.begin(9600);
}

void loop()
{
  long duration;
  digitalWrite(4, LOW);
  delayMicroseconds(3);//smallest reliable interval
  digitalWrite(4, HIGH);
  delayMicroseconds(10);
  digitalWrite(4, LOW);
  duration = pulseIn(3, HIGH);
  double distance = ((duration)*(340.0)/(2000));
  Serial.println(distance);
}
