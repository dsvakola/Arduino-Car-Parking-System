

  #include <Servo.h> 
  
  Servo i;
  int EntrySensor=1;
  int ExitSensor=2;
  int flag1=0;
  int flag2=0;

  void setup() 
  {
    pinMode(EntrySensor,INPUT);
    pinMode(ExitSensor,INPUT);
    i.attach(11);
    i.write(0); // gate is closed
  }

  void loop()
  { 
    if(digitalRead(EntrySensor)==LOW && flag1==0)
    {
      flag1=1;
        if(flag2==0)
        {
          i.write(100); 
        }
    }
  
  if(digitalRead(ExitSensor)==LOW && flag2==0)
  {
     flag2=1;
       if(flag1==0)
       {
         i.write(100); 
       }
    }
  
  if(flag1==1 && flag2==1) // here the condition should have been || instead of &&
    // but still its working
    // check the issue raised on this repository
  {
    delay (1000);
    i.write(0);
    delay(100);
    flag1=0, flag2=0;
  }
  }
