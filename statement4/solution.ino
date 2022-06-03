#include <Keypad.h>
#include <Servo.h>

#define codeLength 4
Servo myservo;

char Code[codeLength];
char PassW[codeLength]="984";
byte keycount=0;

const byte ROWS = 3; 
const byte COLS = 3;
const int buzzer = 11;

char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'}
};

byte rowPins[ROWS] = {9, 8, 7}; 
byte colPins[COLS] = {5, 4, 3}; 

Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 

void setup(){
  Serial.begin(9600);
  myservo.attach(10); //pin 10
  pinMode(buzzer, OUTPUT);
  
}
  
void loop(){
  char customKey = customKeypad.getKey();
  if(customKey){
    Code[keycount]=customKey;
    Serial.print(Code[keycount]);
    keycount++;
  }
  if(keycount==codeLength-1){
    Serial.println(" ");
    
    if(!strcmp(Code,PassW)){
      Serial.println("Correct");
      myservo.write(40); //unlock
      delay(4000);
      
    }
       else{
         Serial.println("Incorrect");
         myservo.write(180); //lock
         tone(buzzer, 500); // Send 1KHz sound signal...
       delay(1000);        
       noTone(buzzer);     
         delay(1000);
       }
    
    deleteCount();
  }
}
  
void deleteCount(){
  while(keycount !=0){
    Code[keycount--]=0;
  }
  return;
}
