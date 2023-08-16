#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
String msg;
int length;
int VR = 6;
int LED = 7;
char c; 

void LedOn(){
  digitalWrite (LED, HIGH); 
  delay(100);
  digitalWrite (LED,LOW);
  delay(100); 
}
void  VrOn(){
  digitalWrite (VR, HIGH);
  delay(5000);
  digitalWrite (VR, LOW); 
}
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(VR, OUTPUT);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Smart Speech");
  lcd.setCursor(0, 1);
  lcd.print("  Recognition  ");
  delay(3000);
  lcd.clear();
  lcd.print("Welcome!");
}

void loop() {
  // put your main code here, to run repeatedly:
  while(Serial.available()){
    delay(10);
    char c = Serial.read();
    if(c =='#')
    {break;}
    msg+= c;
  
  }
   if(msg.length() >0) {
     if  (msg == "on" || "alert")
    {
      LedOn(); 
    }
    else if (msg == "on" )
    {
      VrOn();
    }
    lcd.clear();
    
    lcd.print(msg);
  }
  
  msg = "";
 for (int positionCounter = 0; positionCounter < 20; positionCounter++) {
   // scroll one position left:
   lcd.scrollDisplayLeft();
   delay(200);
   // wait a bit:
   }

  // delay at the end of the full loop:
  delay(50);
 
}
