#include<Keypad.h>
#include<LiquidCrystal.h>
#define ROWS 4
#define COLS 4
const char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte RowPin[ROWS]={9,8,7,6};
byte ColPin[COLS]={5,4,3,2};
Keypad keypad = Keypad(makeKeymap(keys),RowPin,ColPin,ROWS,COLS);
byte x;
//for lcd
LiquidCrystal lcd(A5,A4,A3,A2,A1,A0);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(12,OUTPUT);
   pinMode(13,OUTPUT);
   pinMode(11,OUTPUT);
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  lcd.print("Password");
  delay(1000);
  lcd.setCursor(6,1);
  lcd.print("System ^_^");
  delay(2000);
 entr();
}

void loop() {
 
  // put your main code here, to run repeatedly:
    char key = keypad.getKey();
    if(key != NO_KEY)
    {
      
    	x = password(key);
      //Serial.println(key);
      if(x==0)
        wrong();
      else if(x==1)
        correct();

	}
//سيستم باسورد بال keypad
  //عملت الباسورد رقم فوني برضو :D 
}


char pass[]={'0','1','1','2','7','2','7','1','0','7','8'};
byte i=0;
bool acc=1;

int password(char key)
{  
   if(key=='C')
  {
     entr();
     Serial.println();
     acc=1;
     i=0;
     return 4;
  }
  lcd.setCursor(i,0);
  lcd.print(key);
  Serial.print(key);
  if(pass[i]==key)
  {
    i++;
  }
  else
  {
    i++;
    acc=0;
  }
    
/////    
  if(i==sizeof(pass))
  {
      i=0;
    Serial.println();
    bool bol=acc;
    acc=1;
    if(bol)
      return 1;
    else
       return 0 ;
  }
 
  return 2;
}

void entr()
{ lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Enter");
  delay(200);
  lcd.setCursor(6,1);
  lcd.print("Password");
  delay(2000);
  lcd.clear();
}

void wrong()
{ lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Wrong");
  delay(200);
  lcd.setCursor(6,1);
  lcd.print("Password");
  delay(2000);
  lcd.clear();
}
void correct()
{
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Correct");
  delay(200);
  lcd.setCursor(6,1);
  lcd.print("Password");
  delay(2000);
  lcd.clear();
  ////  
  for(int l =0 ; l<=16 ; l++)
  {
  lcd.setCursor(0,1);
  lcd.print("Ahmed OThman ^_^");
    digitalWrite(12,HIGH);
    digitalWrite(13,LOW);
    delay(1000);
    digitalWrite(11,HIGH);
    delay(1000);
    digitalWrite(11,LOW);
  delay(100);
  lcd.setCursor(l,0);
  lcd.print("Welcome");
  delay(100);
  lcd.clear();
  }
  
}
