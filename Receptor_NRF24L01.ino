//Receptor
#include <SPI.h>
#include <RF24.h>

#define CE_PIN 4
#define CSN_PIN 5

RF24 radio(CE_PIN, CSN_PIN);

const byte direccion[6] = "00011";
char mensajeRecibido[32] = "";

void setup() {
  Serial.begin(115200);

  if (!radio.begin()) {
    Serial.println("NRF24L01 no detectado");
    while (1);
  }

  radio.openReadingPipe(0, direccion);
  radio.setPALevel(RF24_PA_LOW);
  radio.startListening();

  Serial.println("Receptor listo...");
}

void loop() {
  if (radio.available()) {
    radio.read(&mensajeRecibido, sizeof(mensajeRecibido));

    Serial.print("Mensaje recibido: ");
    Serial.println(mensajeRecibido);
  }
}