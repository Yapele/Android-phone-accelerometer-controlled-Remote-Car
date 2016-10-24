int x,y,z,tempX,tempY,tempZ;
int x1,y1,z1,x2,y2,z2;


void setup() 
{
  Serial.begin(9600);
  pinMode(13,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
 
}

void loop() 
{
 while(Serial.available()>0)
  {
   x= Serial.parseInt();
   y= Serial.parseInt();
   z= Serial.parseInt();
   
   tempX = map(x,-100,100,0,200);
   tempY = map(y,-100,100,0,200);
   tempZ = map(z,-100,100,0,200);
   
   x1= map(x,-100,0,255,0);
   y1= map(y,-100,0,0,255);
   z1= map(z,-100,0,0,255);
   
   x2= map(x,0,100,0,255);
   y2= map(y,0,100,255,0);
   z2= map(z,0,100,255,0);
   if(Serial.read()=='\n')
   {
     Serial.print("X:");
     Serial.print(x);
     Serial.print("  Y:");
     Serial.print(y);
     Serial.print("  Z:");
     Serial.println(z);
  //   Serial.print("X1:");
  //   Serial.print(x1);
  //   Serial.print("  Y1:");
  //   Serial.print(y2);
  //   Serial.print("  Z1:");
  //   Serial.println(z2);
     Serial.println("=========================");
   }
   if(tempX>100)
   {
    if (tempY<110)
    {
     if(tempY>90)
     {
       foward(x2);
       Serial.println("Foward");
     }
    } 
   }
   
   if(tempX<100)
   {
    if (tempY<110)
    {
     if(tempY>90)
     {
       reverse(x1);
       Serial.println("Reverse");
     }
    } 
   }
   
   if(tempX>100)
   {
    if (tempY>110)
    {
      fowardLeft(x2,y2);
      Serial.println("FowardLeft");
    } 
    else if (tempY<90)
    {
     fowardRight(x2,y1) ;
     Serial.println("FowardRight");
    }
   }
   
   if(tempX<100)
   {
    if (tempY>110)
    {
      reverseLeft(x1,y2);
      Serial.println("ReverseLeft");
    } 
    else if (tempY<90)
    {
     reverseRight(x1,y1) ;
     Serial.println("ReverseRight");
    }
   }
   
  }
}


void foward (int XVal)
{
 digitalWrite(13,HIGH); 
 digitalWrite(12,LOW);
 digitalWrite(8,HIGH); 
 digitalWrite(7,LOW);
 analogWrite(10,XVal);
 analogWrite(11,XVal);
}

void reverse(int XVal)
{
 digitalWrite(12,HIGH); 
 digitalWrite(13,LOW);
 digitalWrite(7,HIGH); 
 digitalWrite(8,LOW);
 analogWrite(10,XVal);
 analogWrite(11,XVal);
}

void reverseRight(int XVal, int YVal)
{
 digitalWrite(12,HIGH); 
 digitalWrite(13,LOW);
 digitalWrite(7,HIGH); 
 digitalWrite(8,LOW);
 analogWrite(10,XVal);
 analogWrite(11,YVal);
}

void reverseLeft(int XVal, int YVal)
{
 digitalWrite(12,HIGH); 
 digitalWrite(13,LOW);
 digitalWrite(7,HIGH); 
 digitalWrite(8,LOW);
 analogWrite(10,YVal);
 analogWrite(11,XVal);
}
void fowardLeft(int XVal, int YVal)
{
 digitalWrite(13,HIGH); 
 digitalWrite(12,LOW);
 digitalWrite(8,HIGH); 
 digitalWrite(7,LOW);
 analogWrite(10,YVal);
 analogWrite(11,XVal);
}

void fowardRight(int XVal, int YVal)
{
 digitalWrite(13,HIGH); 
 digitalWrite(12,LOW);
 digitalWrite(8,HIGH); 
 digitalWrite(7,LOW);
 analogWrite(10,XVal);
 analogWrite(11,YVal);
}
