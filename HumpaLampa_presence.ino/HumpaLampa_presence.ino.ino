#define ROUGE 9
#define BLEU  10
#define VERT  11

void setup() {
  // put your setup code here, to run once:

  // activation des pinoches 9, 10, 11 
  
  pinMode(9 ,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(5,INPUT);
  Serial.println("Esprit es tu la ?");
}

void loop() {
  // put your main code here, to run repeatedly:

  digitalWrite(ROUGE ,HIGH); // pinoche 9  connecté à la LED Rouge
//  digitalWrite(VERT,HIGH); // pinoche 10 connecté à la LED Vert
  digitalWrite(BLEU,HIGH); // pinoche 11 connecté à la LED Bleue

  if(digitalRead(5) == HIGH) {
    digitalWrite (VERT,LOW);
    Serial.println("je sens ta présence");
  }; // pinoche 5 connecté led Bleue

 if(digitalRead(5) == LOW){
  digitalWrite (VERT,HIGH);
  }

  // On fait une boucle "for" pour envoyer le signal d'intensité "i" sur la pinoche 10
  // le signal d'intensité "i" commence à 0 pour augmenter de +1 dans la boucle "for"
  // la valeur maximale est "255"
  for (int i= 0; i <= 255; i++) {
      analogWrite(ROUGE,i);
    //  delay(10);
  }
      
  for (int i=255; i >= 0; i--) {
      analogWrite(ROUGE,i);
      //delay(10);
  }
}
