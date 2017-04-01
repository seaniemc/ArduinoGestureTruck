
int xPin=0;//Connect x pin of adxl335 to pin A0
int yPin=1;//Connect y pin of adxl335 to pin A1

int lm=9;
int lmr=8;
int rm=10;
int rmr=7;
int ledPin=13;//led on pin 13 is ON except when bot is stationary

void setup()
{
 Serial.begin(9600);//Initialise the serial connection debugging

 pinMode(ledPin,OUTPUT);
 pinMode(lm,OUTPUT);
 pinMode(lmr,OUTPUT);
 pinMode(rm,OUTPUT);
 pinMode(rmr,OUTPUT);

}
void loop()
{
   int xval=analogRead(xPin);
  int yval=analogRead(yPin);
  
    if (xval > 305 && xval < 360)//Stationary
    {
      digitalWrite(lm,LOW);  
      digitalWrite(lmr,LOW);
      digitalWrite(rm,LOW);
      digitalWrite(rmr,LOW);
    
      digitalWrite(ledPin,LOW);
    }
    else
    {
      if(xval > 360)//Forward
      {
        digitalWrite(lm,LOW);  
        digitalWrite(lmr,HIGH);
        digitalWrite(rm,HIGH);
        digitalWrite(rmr,LOW);
        
        digitalWrite(ledPin,HIGH);
      }
    
      if(xval < 305)//Backward
      {
        digitalWrite(lm,HIGH);  
        digitalWrite(lmr,LOW);
        digitalWrite(rm,LOW);
        digitalWrite(rmr,HIGH);
        
        digitalWrite(ledPin,HIGH);
      }
    /*
      if (buf[i]==0x72)//Left 
      {
        digitalWrite(lm,LOW);  
        digitalWrite(lmr,LOW);
        digitalWrite(rm,HIGH);
        digitalWrite(rmr,LOW);
        digitalWrite(ledPin,HIGH);
      }
    
      if (buf[i]==0x6C)//Right 
      {
        digitalWrite(lm,LOW);  
        digitalWrite(lmr,HIGH);
        digitalWrite(rm,LOW);
        digitalWrite(rmr,LOW);
        digitalWrite(ledPin,HIGH);
      }
      */
    
    Serial.print("\n");// debugging
        }
        delay(1000);
}
