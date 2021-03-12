#include <IRremote.h>

//void SelecSpeed(char vitesse);

const int RECV_PIN = 7;
IRrecv irrecv(RECV_PIN);
decode_results results;

const int D5 = 5;


/*int ledPin = 9;     // On renomme la broche 9 en "ledPin"
int analogPin = 0;  // Le potentiomètre est connecté à la broche analogue 0
int val = 0;        // la variable qui stocke la valeur lue est mise à 0*/

void setup()
{
    Serial.begin(9600);
    pinMode(D5, OUTPUT);

    irrecv.enableIRIn();
    irrecv.blink13(true);
}

void loop()
{
    //val = analogRead(analogPin);  //lecture de la valeur analogue (potentiomètre)
    //analogWrite(ledPin, val/4);  // valeur analogue lue (0 à 1023) divisée par 4 (0 à 255)
   // Serial.println(val);

    if (irrecv.decode(&results)){
        //SelecSpeed(results.value);
        switch(results.value)
  {
    case 0xFF4AB5 :
      analogWrite(D5, LOW);
      Serial.println("vitesse 0");
     break;
    case 0xFF6897 :
      analogWrite(D5, 114.9);
      Serial.println("vitesse 1");
      break;
    case 0xFF9867 :
      analogWrite(D5, 184.95);
      Serial.println("vitesse 2");
     break;
    case 0xFFB04F :
      analogWrite(D5, 255);
      Serial.println("vitesse 3");
      break;
    
    }
        Serial.println(results.value, HEX);
        irrecv.resume();}
    
}


/*void SelecSpeed(char vitesse){
  
  switch(vitesse)
  {
    case 0xFF4AB5 :
      //analogWrite(D9, LOW);
      Serial.println("vitesse 0");
     break;
    case 0xFF6897 :
      //analogWrite(D9, 60);
      Serial.println("vitesse 1");
      break;
    case 0xFF9867 :
      //analogWrite(D9, 100);
      Serial.println("vitesse 2");
     break;
    case 0xFFB04F :
      //analogWrite(D9, HIGH);
      Serial.println("vitesse 3");
      break;
    
    }
  
  
  }*/
