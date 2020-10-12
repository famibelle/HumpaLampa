#include <avr/interrupt.h>
#include <avr/sleep.h>

/*
Ce programme est une adaptation de l'Arduino Starter Kit example Project 13 - Touch Sensor Lamp
Les composants 
  - 1 megohm resistance
  - du papier d'aluminium
  - un système d'éclaireage à LED

  Library utilisée:
  - CapacitiveSensor library par Paul Badger
    http://www.arduino.cc/playground/Main/CapacitiveSensor
*/

#include <CapacitiveSensor.h>
#include <SandTimer.h>

#define HEURE 1
#define MINUTE 1
#define SECONDE 1
#define VEILLE 1

SandTimer TouchInterval;
SandTimer PowerOff;

// create an instance of the library
// pinoche 4 envoie le signal électrique
// pinoche 2 détecte une variation

CapacitiveSensor capSensor = CapacitiveSensor(4, 2);

// Seuil qui déclenche l'allumage de la lampe, mon conseil est de faire des test pour déterminer le bon niveau.
// avec un seuil très faible, on peut allumer la lampe en passant la main au dessus du capteur dans un mouvement très Jedi :-)
int threshold = 30;

bool contact = false; // La variable contact change d'état à chaque franchissement du seuil.

// pinoche à laquelle la LED is connected
const int ledPin = 12;


void setup() {
  // Ouverture d'une connextion série
  Serial.begin(9600);

  // Configuration de la pinoche LED en mode sortie d'information
  pinMode(ledPin, OUTPUT);

  pinMode(13, OUTPUT);
}

void loop() {

  // On introduit un delai de quelques secondes pour eviter que le bagotement entre deeux contacts
  TouchInterval.start(1000);

  PowerOff.start(1000*SECONDE*MINUTE*HEURE * VEILLE); // Au bout de 3h on éteint tout
  
  // détection de la valeur de la pinoche connectée à la feuille d'aluminium
  long sensorValue = capSensor.capacitiveSensor(30);

  // print out the sensor value
  Serial.println(sensorValue);
  digitalWrite(13,LOW);

  // if the value is greater than the threshold
  if (sensorValue > threshold) {
    // turn the LED on
    // digitalWrite(ledPin, HIGH);
    if (TouchInterval.finished()) {
      contact = !contact;
      } 
    PowerOff.startOver();
    Serial.println("Contact");
  }
  // if it's lower than the threshold
  else {
    // turn the LED off
    // digitalWrite(ledPin, LOW);
  }

  if (contact == true) {
    digitalWrite(ledPin, HIGH);
 
  } else {
    digitalWrite(ledPin, LOW);
  }
    
  delay(10);
  if (PowerOff.finished()) {
    set_sleep_mode(SLEEP_MODE_PWR_DOWN);   // sleep mode is set here
    sleep_enable();              // enables the sleep bit in the mcucr register
 }
}
