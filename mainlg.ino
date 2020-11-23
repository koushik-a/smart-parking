#include <Wire.h>  
#include <LiquidCrystal_I2C.h>
#include <Servo.h>

// servo object1
Servo servo1;
// servo object2
Servo servo2;

//entry gate sensor
const int servo_sensor1 = A4;
//exit gate sensor
const int servo_sensor2 = A5;

//servo1 connection 
const int servo_1 =2;
//servo2 connection
const int servo_2 =3;

//object for servo1 positon
int value_1 =0;
//object for servo2 positon
int value_2 =0;


//buttons
const int micro=10;
const int sedan=11;
const int suv=12;

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);

//micro sensors
const int s1=4;
const int s2=7;

//sedan sensors
const int s3=5;
const int s4=8;

//suv sensors
const int s5=6;
const int s6=9;

// objects
int a,b,c;
int p,q,r,s,t,u;
 
void setup()
{
  //initializing serial communication
  Serial.begin(9600);
  
  // initialize the LCD
  lcd.begin();
  // Turn on the blacklight and print a message.
  lcd.backlight();
  
  // setting sensors as input
  pinMode(servo_sensor1,INPUT);
  pinMode(servo_sensor2,INPUT);

  //attaching servos
  servo1.attach(servo_1);
  servo2.attach(servo_2);

  //setting buttons as input
  pinMode(micro,INPUT);
  pinMode(sedan,INPUT);   
  pinMode(suv,INPUT); 

  //setting sensors as input
  //micro
  pinMode(s1,INPUT);
  pinMode(s2,INPUT);
  //sedan
  pinMode(s3,INPUT);
  pinMode(s4,INPUT);
  //suv
  pinMode(s5,INPUT);
  pinMode(s6,INPUT);    
}

void loop()
{
  //reading value from entry sensor 
  value_1 = analogRead(servo_sensor1);
  //reading value from exit sensor
  value_2 = analogRead(servo_sensor2);

  // entry gate(servo) code 

  // moving up  
  {
    if (analogRead(A4)<500)
      {
        servo1.write(90);
        delay(5000);
      }
  }
  //moving down
  if (analogRead(A4)>500)
      {
        servo1.write(0);
        delay(60);
      }

  // exit gate(servo) code 

  // moving up 
  {
    if (analogRead(A5)<500)
      {
        servo2.write(90);
        delay(5000);
      }    
  }
  //moving down
  if (analogRead(A5)>500)
      {
        servo2.write(0);
        delay(60);
      }

  //main logic
  
  //reading button values
  a=digitalRead(micro);
  b=digitalRead(sedan);
  c=digitalRead(suv);

  //reading sensor values
  //micro
  p=digitalRead(s1);
  q=digitalRead(s2);
  //sedan
  r=digitalRead(s3);
  s=digitalRead(s4);
  //sedan
  t=digitalRead(s5);
  u=digitalRead(s6);
      
//micro
  if(a == 0 && p ==  1)
  {
    lcd.print("goto slot 1");
    delay(2000);
    lcd.clear();
  }
  else if(a == 0 && p == 0 && q==1)
  {
    lcd.print("goto slot 2");
    delay(2000);
    lcd.clear();
  }
  else if(a == 0 && p == 0 && q==0 && r==1)
  {
    lcd.print("goto slot 3");
    delay(2000);
    lcd.clear();
  } 
  else if(a == 0 && p == 0 && q==0 && r==0)
  {
    lcd.print("sorry parking full");
    delay(2000);
    lcd.clear();
  }
  
// sedan
  if(b == 0 && r ==  1)
  {
    lcd.print("goto slot 3");
    delay(2000);
    lcd.clear();
  }
  else if(b == 0 && r == 0 && s==1)
  {
    lcd.print("goto slot 4");
    delay(2000);
    lcd.clear();
  }
  else if(b == 0 && r == 0 && s==0 && t==1)
  {
    lcd.print("goto slot 5");
    delay(2000);
    lcd.clear();
  }  
  else if(b == 0 && r == 0 && s==0 && t==0)
  {
    lcd.print("sorry parking full");
    delay(2000);
    lcd.clear();
  }

// suv

  if(c == 0 && t ==  1)
  {
    lcd.print("goto slot 5");
    delay(2000);
    lcd.clear();
  }
  else if(c == 0 && t == 0 && u==1)
  {
    lcd.print("goto slot 6");
    delay(2000);
    lcd.clear();
  }
 else if(c == 0 && t == 0 && u==0)
  {
    lcd.print("sorry parking full");
    delay(2000);
    lcd.clear();
  } 
}
