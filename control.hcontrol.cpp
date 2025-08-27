#include <Arduino.h>
#include "control.h"

int ledPin;
int botonPin;
int estado = 0;          
bool ultimoBoton = HIGH; 
unsigned long ultimoTiempo = 0;

void inicializar(int pinLed, int pinBoton) {
  ledPin = pinLed;
  botonPin = pinBoton;
  pinMode(ledPin, OUTPUT);
  pinMode(botonPin, INPUT_PULLUP);  // usamos la resistencia interna
}

void actualizar() {
  bool lectura = digitalRead(botonPin);

  if (ultimoBoton == HIGH && lectura == LOW) {
    estado++;
    if (estado > 2) estado = 0; // ciclo 0-1-2
    delay(200); // anti-rebote básico
  }
  ultimoBoton = lectura;

  // Control del LED
  if (estado == 0) {
    digitalWrite(ledPin, LOW); // Apagado
  } 
  else if (estado == 1) {
    unsigned long ahora = millis();
    if (ahora - ultimoTiempo >= 500) { // parpadeo cada 0.5 s
      digitalWrite(ledPin, !digitalRead(ledPin));
      ultimoTiempo = ahora;
    }
  } 
  else if (estado == 2) {
    digitalWrite(ledPin, HIGH); // Encendido fijo
  }
}
