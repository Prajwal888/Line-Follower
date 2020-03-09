//  Sketch for a Basic Line Follower Bot
//  Motor Control - DIGITAL
//  2 Motors and 2 Sensors are used
//  White - 1  &  Black - 0
//  By - Prajwal Jena

#define leftmotor 10  //D10
#define rightmotor 9  //D9

int s1, s2;   //Sensors

void setup()    // put your setup code here, to run once: 
{  
  Serial.begin(9600);
  pinMode(leftmotor,OUTPUT);
  pinMode(rightmotor,OUTPUT);
  pinMode(4,INPUT);   //D4
  pinMode(5,INPUT);   //D5
  delay(500);
}

void loop()     // put your main code here, to run repeatedly:
{ 
  sensor_white()      //For WHITE LINE
  //sensor_black()    //For BLACK LINE
  
  lfr();
}

void sensor_white()
{
  s1 = digitalRead(4);  //  left sensor
  s2 = digitalRead(5);  //  right sensor
  Serial.print(S1);
  Serial.print("\t");
  Serial.println(S2);
}

void sensor_black()
{ //Inverted Reading
  s1 = !digitalRead(4);  //  left sensor
  s2 = !digitalRead(5);  //  right sensor
  Serial.print(S1);
  Serial.print("\t");
  Serial.println(S2);
}

void lfr()
{
  if(s1==0 && s2==0)            // s1 & s2 on black
  {
    digitalWrite(leftmotor,HIGH);
    digitalWrite(rightmotor,HIGH);
  }

  else if(s1==1 && s2==0)            // s1 on white & s2 on black
  {
    digitalWrite(leftmotor,LOW);
    digitalWrite(rightmotor,HIGH);
  }

  else if(s1==0 && s2==1)            // s1 on black & s2 on white
  {
    digitalWrite(leftmotor,HIGH);
    digitalWrite(rightmotor,LOW);
  }

  else       // STOP
  {
    digitalWrite(leftmotor,LOW);
    digitalWrite(rightmotor,LOW);
  }
}
