#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

int trigPin = 2;
int echoPin = 4;
#define LED 13
#define LED2 12
//12가 초록색 13이 노란색

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(LED, OUTPUT);
  pinMode(LED2, OUTPUT);
  lcd.begin();
  lcd.backlight();
}

void loop() {
  // put your main code here, to run repeatedly:
  long duration, distance;
  digitalWrite(trigPin, HIGH);
  delay(10);
  digitalWrite(trigPin,LOW);
  duration = pulseIn(echoPin,HIGH);
  distance = ((float)(340 * duration) / 10000) /2;
  Serial.print("Duration:");
  Serial.print(duration);
  Serial.print("\nDistance:");
  Serial.print(distance);
  Serial.println("cm\n");
  
  Serial.write(0xff) ;
  Serial.write(distance & 0xff) ;
    
    if(distance <30 ){ //가까우면 조심하라그러고 이미지 띄우고 노란불
      lcd.setCursor(0,0);
      lcd.print("Be careful !!");
      lcd.setCursor(0,1);
      lcd.print(distance);
      lcd.print(" cm ");
      digitalWrite(LED2, LOW);
      digitalWrite(LED, HIGH);
         
    }
    else{ //멀면 이미지 안띄우고 초록불 거리도 표시없음

      digitalWrite(LED, LOW);
      digitalWrite(LED2, HIGH);
      lcd.clear();
    }
      

  
  delay(500);
}
