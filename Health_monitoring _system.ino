#include <LiquidCrystal.h> 
LiquidCrystal lcd(12,11,5,4,3,2); 
int Contrast=80; 
const int buz = 7; 
int pulse=A0; 
int temp=A1; 
int xpin=A2; 
int ypin=A3; 
int zpin=A4; 
//int buz=9; 
void setup(){ 
 Serial.begin(9600); 
 pinMode (buz, OUTPUT); 
 analogWrite(6, Contrast); 
 lcd.begin(16,2); 
 lcd.clear(); 
 delay(1000); 
} 
void loop(){ 
 int p,pulse,t,tem,f; 
 p=analogRead(pulse); 
 Serial.println(p); 
 lcd.clear(); 
 lcd.setCursor(0,0); 
 lcd.print("Pulse="); 
 lcd.print(p/6); 
 tem=analogRead(temp); 
 t=tem*0.48828125; 
 f=t*1.8+32; 
 lcd.setCursor(0,1); 
 lcd.print("Temp="); 
 lcd.print(f); 
 lcd.print("F"); 
 delay(2000); 
 Serial.println(f); 
 int x,y,z; 
 x=analogRead(xpin); 
 delay(1); 
 y=analogRead(ypin); 
 delay(1); 
 z=analogRead(zpin); 
 delay(1); 
 Serial.print(x); 
 Serial.print("\t"); 
 Serial.print(y); 
 Serial.print("\t"); 
 Serial.print(z); 
 Serial.print("\n"); 
 if (z < 350) { 
 digitalWrite(buz, HIGH); 
 delay(1000); 
 } else 
 digitalWrite(buz, LOW); 
 delay(1000); 
 if(z > 402){ 
 Serial.println("Fall detected"); 
 lcd.println("Fall Detected");
 delay(1000); 
 } 
}
