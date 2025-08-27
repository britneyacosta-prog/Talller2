#include <Arduino.h>
#include "control.h"

const int pinLed = 4;     // LED en GPIO5
const int pinBoton = 0;  // Botón en GPIO18 (a GND)

void setup() {
  inicializar(pinLed, pinBoton);
  Serial.begin(115200);
  Serial.println("Sistema iniciado. Oprime el botón para cambiar el estado del LED.");
}

void loop() {
  actualizar();
  

}
