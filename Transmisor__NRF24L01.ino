//Transmisor
#include <SPI.h>
#include <RF24.h>

#define CE_PIN 4
#define CSN_PIN 5

RF24 radio(CE_PIN, CSN_PIN);

const byte direccion[6] = "00011";
const char mensaje[] = "Comunicacion establecida";

void setup() {
  Serial.begin(115200);

  if (!radio.begin()) {
    Serial.println("NRF24L01 no detectado");
    while (1);
  }

  radio.openWritingPipe(direccion);
  radio.setPALevel(RF24_PA_LOW);
  radio.stopListening();

  Serial.println("Transmisor listo...");
}

void loop() {
  bool enviado = radio.write(&mensaje, sizeof(mensaje));

  if (enviado) {
    Serial.println("Mensaje enviado");
  } else {
    Serial.println("Error al enviar");
  }

  delay(2000);
}