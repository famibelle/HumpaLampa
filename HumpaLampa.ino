void setup() {
  // put your setup code here, to run once:

  // activation des pinoches 9, 10, 11 
  
  pinMode(9 ,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  digitalWrite(9 ,LOW); // pinoche 9  connecté à la LED ?
  digitalWrite(10,LOW); // pinoche 10 connecté à la LED Rouge
  digitalWrite(11,LOW); // pinoche 11 connecté à la LED ?

  // On fait une boucle "for" pour envoyer le signal d'intensité "i" sur la pinoche 10
  // le signal d'intensité "i" commence à 0 pour augmenter de +1 dans la boucle "for"
  // la valeur maximale est "255"
  for (int i= 0; i <= 255; i++) {
      analogWrite(10,i);
      delay(10);
  }
      
  for (int i=255; i >= 0; i--) {
      analogWrite(10,i);
      delay(10);
  }
}
