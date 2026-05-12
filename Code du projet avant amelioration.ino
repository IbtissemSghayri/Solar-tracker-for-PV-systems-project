#include <Servo.h>

const int ldrgauche= A0;  
const int ldrdroite=A1;
const int servo=2;    
int toler=15;         
int vitessedelai= 100;     
float angleActuel= 90;
Servo monServo;

void setup() {
  monServo.attach(servo);
  monServo.write(angleActuel); 
  Serial.begin(9600);
  delay(1000);
}
void loop() {
  int valGauche = analogRead(ldrgauche);
  int valDroite = analogRead(ldrdroite);
  Serial.print("G:"); 
  Serial.print(valGauche);
  Serial.print("D:"); 
  Serial.println(valDroite);

  if (valGauche> (valDroite+toler)) {
    if (angleActuel<180) {
      angleActuel +=0.5;
      monServo.write(angleActuel);
      delay(vitessedelai);
    }
  }
   else if (valDroite >(valGauche +toler)) {
    if (angleActuel> 0) {
      angleActuel -=0.5;
      monServo.write(angleActuel);
      delay(vitessedelai); 
    }
  }
}
