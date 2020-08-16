

#include <SoftwareSerial.h>

SoftwareSerial mySerial(7, 8); 

String BT_input;                      
int LED = 13;                             

// Define Motor Pin
const int Motor_L_F = 2;
const int Motor_L_B = 3;
const int Motor_R_F = 4;
const int Motor_R_B = 5;

void setup()  
{  
  Serial.begin(9600);            
  mySerial.begin(9600);
  pinMode(LED, OUTPUT);
  while (!Serial) 
  {
 //stall
  }
}

void loop() 

 { 
  if (mySerial.available())
    {   
        BT_input = mySerial.read();   
        Serial.println(BT_input);
        if (BT_input=="1")                
        {
          Forward();
        }
        if (BT_input=="2")                
        {
          Right();
        }
        if (BT_input=="3")                
        {
          Left();
        }
        if (BT_input=="4")                
        {
          Back();
        }
        
        if (BT_input=="5")                
        {
          Stop();
        }
        

    }
 
}


void Forward(){

  digitalWrite(Motor_L_F, HIGH);
  digitalWrite(Motor_L_B, LOW);


  digitalWrite(Motor_R_F, HIGH);
  digitalWrite(Motor_R_B, LOW);
  
  }

void Right(){

  digitalWrite(Motor_R_F, LOW);
  digitalWrite(Motor_R_B, HIGH);


  digitalWrite(Motor_L_F, HIGH);
  digitalWrite(Motor_L_B, LOW);
  
  }

void Left(){

  digitalWrite(Motor_L_F, LOW);
  digitalWrite(Motor_L_B, HIGH);


  digitalWrite(Motor_R_F, HIGH);
  digitalWrite(Motor_R_B, LOW);
  
  }

void Back(){
  digitalWrite(Motor_L_F, LOW);
  digitalWrite(Motor_L_B, HIGH);

  digitalWrite(Motor_R_F, LOW);
  digitalWrite(Motor_R_B, HIGH);
  
  }


void Stop(){

  digitalWrite(Motor_L_F, LOW);
  digitalWrite(Motor_L_B, LOW);


  digitalWrite(Motor_R_F, LOW);
  digitalWrite(Motor_R_B, LOW);
  
  }
