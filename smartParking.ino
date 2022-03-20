

#include <LiquidCrystal.h> //Header file for LCD from https://www.arduino.cc/en/Reference/LiquidCrystal
#include <Keypad.h> //Header file for Keypad from https://github.com/Chris--A/Keypad
#include <Wire.h>
#include <SoftwareSerial.h>
#include <Servo.h>

struct User{
   int username;
   int pass;
   int enterTime;
};
Servo myservo;  // create servo object to control a servo
const byte ROWS = 4; // Four rows
const byte COLS = 4; // Three columns
const int userNum=1;
const int costPerMili=1;
User user={1,1,0};
User users[userNum]={user};
int Num1,Num2,Number;
char key,action;
const byte rs = 35, en = 34, d4 = 33, d5 = 32, d6 = 31, d7 = 30; //Pins to which LCD is connected
const byte maxCapacity=9;
byte sumCapacity=0;
const byte floors=3;
const byte pirInputs[maxCapacity]={36,37,38,39,40,41,42,43,44};
const byte ledOutputs[maxCapacity]={45,46,47,48,50,51,52,53,54};
byte capacityPerFloor[floors]={0,0,0};
byte rowPins[ROWS] = { 22, 23, 24, 25 };// Connect keypad ROW0, ROW1, ROW2 and ROW3 to these Arduino pins.
byte colPins[COLS] = { 26, 27, 28, 29 }; // Connect keypad COL0, COL1 and COL2 to these Arduino pins.
boolean result = false;
// Define the Keymap
char keys[ROWS][COLS] = {

  {'7','8','9','D'},

  {'4','5','6','C'},

  {'1','2','3','B'},

  {'*','0','#','A'}

};

SoftwareSerial mySerial(18,19);

Keypad kpd = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS ); //  Create the Keypad

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
 
void setup() {
  myservo.attach(14);
  myservo.write(0);
  //myservo.writeMicroseconds(1000);    
  mySerial.begin(9600);
  Serial1.begin(9600);
  Wire.begin();
  mySerial.println("test"); //We are using a 16*2 LCD display
  pinIoDefiner(ledOutputs,false);
  pinIoDefiner(pirInputs,true);
  pinLowHighWriter(ledOutputs,true);
  lcd.begin(16, 4);
  printOnLcd(1,"smart parking"); //Display a intro message
  mySerial.println("start up");
  delay(10); //Wait for display to show info
  lcd.clear();
  
}
void loop() {
  
key = kpd.getKey(); //storing pressed key value in a char

if (key!=NO_KEY)
DetectButtons();

if (result==true)
CalculateResult();

DisplayResult();   
}

void DetectButtons()
{ 
     lcd.clear(); //Then clean it
    if (key=='*') //If cancel Button is pressed
    {mySerial.println ("Button Cancel"); Number=Num1=Num2=0; result=false;}
    
     if (key == '1') //If Button 1 is pressed
    {mySerial.println ("Button 1"); 
    if (Number==0)
    Number=1;
    else{
    long temp=Number;
    Number = (Number*10) + 1; //Pressed twice
    if (String(temp,DEC ).length()>=4){
      String temp1=String(temp,DEC);
      temp1 = temp1.substring(1, (temp1.length()))+String(1,DEC);
      Number=atol(temp1.c_str());
    }
    }
    }
    
     if (key == '4') //If Button 4 is pressed
    {mySerial.println ("Button 4"); 
    if (Number==0)
    Number=4;
    else{
    long temp=Number;
    Number = (Number*10) + 4; //Pressed twice
    if (String(temp,DEC ).length()>=4 ){
      String temp1=String(temp,DEC);
      temp1 = temp1.substring(1, (temp1.length()))+String(4,DEC);
      Number=atol(temp1.c_str());
    }
    }
    }
    
     if (key == '7') //If Button 7 is pressed
    {mySerial.println ("Button 7");
    if (Number==0)
    Number=7;
    else{
    long temp=Number;
    Number = (Number*10) + 7; //Pressed twice
    if (String(temp,DEC ).length()>=4 ){
      String temp1=String(temp,DEC);
      temp1 = temp1.substring(1, (temp1.length()))+String(7,DEC);
      Number=atol(temp1.c_str());
    }
    }
    }
  

    if (key == '0')
    {mySerial.println ("Button 0"); //Button 0 is Pressed
    if (Number==0)
    Number=0;
    else{
      
    long temp=Number;
    Number = (Number*10) + 0; //Pressed twice
    if (String(temp,DEC ).length()>=4 ){
      String temp1=String(temp,DEC);
      temp1 = temp1.substring(1, (temp1.length()))+String(0,DEC);
      Number=atol(temp1.c_str());
    }
    }
    }
    
     if (key == '2') //Button 2 is Pressed
    {mySerial.println ("Button 2"); 
     if (Number==0)
    Number=2;
    else{
    long temp=Number;
    
    Number = (Number*10) + 2; //Pressed twice
    if (String(temp,DEC ).length()>=4 ){
      String temp1=String(temp,DEC);
      temp1 = temp1.substring(1, (temp1.length()))+String(2,DEC);
      Number=atol(temp1.c_str());
    }
    }
    }
    
     if (key == '5')
    {mySerial.println ("Button 5"); 
     if (Number==0)
    Number=5;
    else{
    long temp=Number;
    
    Number = (Number*10) + 5; //Pressed twice
    if (String(temp,DEC ).length()>=4 ){
      String temp1=String(temp,DEC);
      temp1 = temp1.substring(1, (temp1.length()))+String(5,DEC);
      Number=atol(temp1.c_str());
    }
    }
    }
    
     if (key == '8')
    {mySerial.println ("Button 8"); 
     if (Number==0)
    Number=8;
    else{
    long temp=Number;
    Number = (Number*10) + 8; //Pressed twice
    if (String(temp,DEC ).length()>=4 ){
      String temp1=String(temp,DEC);
      temp1 = temp1.substring(1, (temp1.length()))+String(8,DEC);
      Number=atol(temp1.c_str());
    }
    }
    }   
  

    if (key == '#')
    {mySerial.println ("Button Equal"); 
    Num2=Number;
    result = true;
    }
    
     if (key == '3')
    {mySerial.println ("Button 3"); 
     if (Number==0)
    Number=3;
    else
    {
    long temp=Number;
    
    Number = (Number*10) + 3; //Pressed twice
    if (String(temp,DEC ).length()>=4 ){
      String temp1=String(temp,DEC);
      temp1 = temp1.substring(1, (temp1.length()))+String(3,DEC);
      Number=atol(temp1.c_str());
    }
    }
    }
    
     if (key == '6')
    {mySerial.println ("Button 6"); 
    if (Number==0)
    Number=6;
    else{
    long temp=Number;
    
    Number = (Number*10) + 6; //Pressed twice
    if (String(temp,DEC ).length()>=4 ){
      String temp1=String(temp,DEC);
      temp1 = temp1.substring(1, (temp1.length()))+String(6,DEC);
      Number=atol(temp1.c_str());
    }
    }
    }
    
     if (key == '9')
    {mySerial.println ("Button 9");
    if (Number==0)
    Number=9;
    else{
    long temp=Number;
    
    Number = (Number*10) + 9; //Pressed twice
    if (String(temp,DEC ).length()>=4 ){
      String temp1=String(temp,DEC);
      temp1 = temp1.substring(1, (temp1.length()))+String(9,DEC);
      Number=atol(temp1.c_str());
    }
    }
    }  

  if (key == 'D') //Detecting Buttons on Column 4
  {
    Num1 = Number;    
    Number =0;
    mySerial.println ("Devesion");
    action = '/';  
    delay(10);
  }
  
}

void CalculateResult()
{
 if (action=='/'){
  User chosenUser;
  for (int i = 0; i < userNum; i++) {
    mySerial.println ("username is");
    mySerial.println (users[i].username );
    mySerial.println ("pass is");
    mySerial.println (users[i].pass);
    mySerial.println ("enterTime is");
    mySerial.println (users[i].enterTime);
 
    if (Num1==users[i].username and Num2==users[i].pass and sumCapacity<9){
       mySerial.println ("sumCapacity is");
       mySerial.println (sumCapacity);
       mySerial.println ("servo is moved");
       myservo.write(180);                      
       printOnLcd(0,"door opened");
       int Time=millis();
       mySerial.println ("time is");
       mySerial.println (Time);
       int cost=0;
       if(users[i].enterTime==0)users[i].enterTime=Time;
       else{
        cost=(Time-users[i].enterTime)*costPerMili;
        users[i].enterTime=0;
        printOnLcd(1,"cost: "+String(cost));
       }
       delay(100);
       lcd.clear(); 
       myservo.write(0);
    }
  }
  Num1=Num2=Number=0;
  result=false;  
}
}

void DisplayResult()
{
     // set the cursor to column 0, line 1
  sumCapacity=0;
  for (int i = 0; i < floors; i++) {
    capacityPerFloor[i]=0;
    for (int j = i*3; j <(i+1)*3; j++) {
    if (digitalRead(int(pirInputs[j])) == HIGH) {
      digitalWrite(int(ledOutputs[j]), HIGH);
      capacityPerFloor[i]=capacityPerFloor[i]+1;
      sumCapacity+=1;
    }
    else digitalWrite(ledOutputs[j], LOW);
  }
  }
  String line="A: "+String(capacityPerFloor[0])+" "+"b: "+String(capacityPerFloor[1]);
  printOnLcd(0,line);
  line="c: "+String(capacityPerFloor[2])+" "+"t: "+String(sumCapacity);
  printOnLcd(1,line);
  line="username: "+String(Num1);
  printOnLcd(2,line);
  line="password: "+String(Num2)+" "+"input: "+String(Number);
  printOnLcd(3,line);
  delay(10); //Wait for display to show info
  lcd.clear();
 
}

void pinIoDefiner(byte arr[],bool input)
{
  int l=sizeof(arr);
  for (int i = 0; i <= l; i++) {
    int pin=int(arr[i]);
    if(input)pinMode(pin, INPUT);
    else pinMode(pin, OUTPUT);
  } 
}

void pinLowHighWriter(byte arr[],bool low)
{
  int l=sizeof(arr);
  for (int i = 0; i <= l; i++) {
    if(low)digitalWrite(arr[i], LOW);
    else digitalWrite(arr[i], HIGH);

  }
}

void printOnLcd(int lineNumber, String message) {
  lcd.setCursor(0, lineNumber);
  lcd.print(message);
}




    
 
