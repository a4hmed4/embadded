#include <LiquidCrystal.h>
#include <Keypad.h> 

const int rs = A0, en = A1, d4 = A2, d5 = A3, d6 = A4, d7 = A5;

const byte ROWS = 4;
const byte COLS = 4;

char keys[ROWS][COLS] = {
  {'1','2','3','/'},
  {'4','5','6','*'},
  {'7','8','9','-'},
  {'C','0','=','+'}
};

byte rowPins[ROWS] = {5, 4, 3, 2};
byte colPins[COLS] = {9, 8, 7, 6};

Keypad kpd = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

long Num1, Num2, Number;
char key, action;
boolean result = false;

void setup() {
  lcd.begin(16, 2);
  lcd.print("Sneed's Calculator");
  lcd.setCursor(0, 1);
  lcd.print("-CirsuitDigest");

  delay(1000);

  lcd.clear();
}



void loop() {

key = kpd.getKey();

if (key != NO_KEY)
DetectButtons();

if (result == true)
CalculateResult();

DisplayResult();

}


void DetectButtons()
{ 
     lcd.clear(); //Then clean it
    if (key=='C') //If cancel Button is pressed
    {Serial.println ("Button Cancel"); Number=Num1=Num2=0; result=false;}
    
     if (key == '1') //If Button 1 is pressed
    {Serial.println ("Button 1"); 
    if (Number==0)
    Number=1;
    else
    Number = (Number*10) + 1; //Pressed twice
    }
    
     if (key == '4') //If Button 4 is pressed
    {Serial.println ("Button 4"); 
    if (Number==0)
    Number=4;
    else
    Number = (Number*10) + 4; //Pressed twice
    }
    
     if (key == '7') //If Button 7 is pressed
    {Serial.println ("Button 7");
    if (Number==0)
    Number=7;
    else
    Number = (Number*10) + 7; //Pressed twice
    } 
  

    if (key == '0')
    {Serial.println ("Button 0"); //Button 0 is Pressed
    if (Number==0)
    Number=0;
    else
    Number = (Number*10) + 0; //Pressed twice
    }
    
     if (key == '2') //Button 2 is Pressed
    {Serial.println ("Button 2"); 
     if (Number==0)
    Number=2;
    else
    Number = (Number*10) + 2; //Pressed twice
    }
    
     if (key == '5')
    {Serial.println ("Button 5"); 
     if (Number==0)
    Number=5;
    else
    Number = (Number*10) + 5; //Pressed twice
    }
    
     if (key == '8')
    {Serial.println ("Button 8"); 
     if (Number==0)
    Number=8;
    else
    Number = (Number*10) + 8; //Pressed twice
    }   
  

    if (key == '=')
    {Serial.println ("Button Equal"); 
    Num2=Number;
    result = true;
    }
    
     if (key == '3')
    {Serial.println ("Button 3"); 
     if (Number==0)
    Number=3;
    else
    Number = (Number*10) + 3; //Pressed twice
    }
    
     if (key == '6')
    {Serial.println ("Button 6"); 
    if (Number==0)
    Number=6;
    else
    Number = (Number*10) + 6; //Pressed twice
    }
    
     if (key == '9')
    {Serial.println ("Button 9");
    if (Number==0)
    Number=9;
    else
    Number = (Number*10) + 9; //Pressed twice
    }  

      if (key == '+' || key == '-' || key == '*' || key == '/') //Detecting Buttons on Column 4
  {
    Num1 = Number;    
    Number =0;
    if (key == '+')
    {Serial.println ("Addition"); action = '+';}
     if (key == '-')
    {Serial.println ("Subtraction"); action = '-'; }
     if (key == '*')
    {Serial.println ("Multiplication"); action = '*';}
     if (key == '/')
    {Serial.println ("Devesion"); action = '/';}  

    delay(100);
  }
  
}



void CalculateResult()
{
  if (action=='+')
    Number = Num1+Num2;

  if (action=='-')
    Number = Num1-Num2;

  if (action=='*')
    Number = Num1*Num2;

  if (action=='/')
    Number = Num1/Num2; 
}

void DisplayResult() {
  lcd.setCursor(0, 0);
  lcd.print(Num1);
  lcd.print(action);
  lcd.print(Num2);

  if (result == true) {
    lcd.print(" =");
    lcd.print(Number);
  }

  lcd.setCursor(0, 1);
  lcd.print(Number);
}

