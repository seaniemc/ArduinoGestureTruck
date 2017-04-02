
//int xPin=0;//Connect x pin of adxl335 to pin A0
//int yPin=1;//Connect y pin of adxl335 to pin A1
int slm=6;
//int srm=5;

int lm=9;
int lmr=8;
int rm=10;
int rmr=7;
//int rled=5;
int ledPin=13;//led on pin 13 is ON except when bot is stationary

void setup()
{
 Serial.begin(9600);//Initialise the serial connection debugging

 pinMode(ledPin,OUTPUT);
 pinMode(lm,OUTPUT);
 pinMode(lmr,OUTPUT);
 pinMode(rm,OUTPUT);
 pinMode(rmr,OUTPUT);
//pinMode(rled,OUTPUT);
pinMode(slm,OUTPUT);
//pinMode(srm,OUTPUT);
}
void loop()
{
  int xval=analogRead(A0);
  int yval=analogRead(A1);

  Serial.print("xval=");
  Serial.println(xval);//Use xval to determine threshold for different directions
  
  Serial.print("yval=");
  Serial.println(yval); //Use yval to determine threshold for different directions

  //delay(1000); //used to display values after 2s delay
  Serial.print("\n");//print after 2s in a new line
    if (xval > 325 && xval < 345)//Stationary
    {
      stationary();
    }
    if(xval > 345 && xval < 360)//Forward
      {
        slowForward();
      }
      if(xval > 360)//Forward
      {
        forward();
      }
    
      if(xval < 305)//Backward
      {
       back();
      }
    
      if(yval > 360)//Left 
      {
        left();
      }
    
      if(yval < 305)//Right 
      {
        right();
      }
      
//    Serial.print("\n");// debugging
        delay(1000);
}

/////////////////////////////////////////////////

void forward()
{
  digitalWrite(lm,LOW);  
  digitalWrite(lmr,HIGH);
  digitalWrite(rm,HIGH);
  digitalWrite(rmr,LOW);
  
  digitalWrite(slm,HIGH);
  Serial.print("FORWARD  ");
  
  digitalWrite(ledPin,HIGH);
}
void slowForward()
{
  digitalWrite(lm,LOW);  
  digitalWrite(lmr,HIGH);
  digitalWrite(rm,HIGH);
  digitalWrite(rmr,LOW);
  Serial.print("FORWARD  ");
  digitalWrite(slm,LOW);
  
}
void back()
{
   digitalWrite(lm,HIGH);  
    digitalWrite(lmr,LOW);
    digitalWrite(rm,LOW);
    digitalWrite(rmr,HIGH);
    digitalWrite(slm,LOW);
    digitalWrite(ledPin,HIGH);
}

void left(){

  digitalWrite(lm,HIGH);  
  digitalWrite(lmr,LOW);
  digitalWrite(rm,LOW);
  digitalWrite(rmr,LOW);
  digitalWrite(slm,LOW);
  digitalWrite(ledPin,HIGH);
}

void right()
{
  digitalWrite(lm,LOW);  
  digitalWrite(lmr,LOW);
  digitalWrite(rm,HIGH);
  digitalWrite(rmr,LOW);
  digitalWrite(slm,LOW);
  Serial.print("RIGHT");
}

void stationary(){
  digitalWrite(lm,LOW);  
  digitalWrite(lmr,LOW);
  digitalWrite(rm,LOW);
  digitalWrite(rmr,LOW);
  digitalWrite(slm,LOW);
}

