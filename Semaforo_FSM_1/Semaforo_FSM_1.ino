#define ledRojo 8
#define ledAmarillo 9
#define ledVerde 10

#define tiempoRojo 3000
#define tiempoAmarillo 2000
#define tiempoVerde 4000

unsigned long tiempoAnterior;

enum estado {
  ROJO,
  AMARILLO,
  VERDE
};

estado Estado;

void setup() {
  pinMode(ledRojo, OUTPUT);
  pinMode(ledAmarillo, OUTPUT);
  pinMode(ledVerde, OUTPUT);
  Serial.begin(9600);
  Estado = ROJO;
  tiempoAnterior = millis();
}

void loop() {
  switch (Estado)
  {
    case ROJO:
      if (millis() - tiempoAnterior >= tiempoRojo)
      {
        Serial.println("Pasamos a amarillo...");
        tiempoAnterior = millis();
        Estado = AMARILLO;
      }
      break;

    case AMARILLO:
      if (millis() - tiempoAnterior >= tiempoAmarillo)
      {
        Serial.println("Pasamos a verde...");
        tiempoAnterior = millis();
        Estado = VERDE;
      }
      break;

    case VERDE:
      if (millis() - tiempoAnterior >= tiempoVerde)
      {
        Serial.println("Pasamos a rojo...");
        tiempoAnterior = millis();
        Estado = ROJO;
      }
      break;
  }
}

void prenderRojo()
{
  digitalWrite(ledRojo, HIGH);
  digitalWrite(ledAmarillo, LOW);
  digitalWrite(ledVerde, LOW);
}

void prenderAmarillo()
{
  digitalWrite(ledRojo, LOW);
  digitalWrite(ledAmarillo, HIGH);
  digitalWrite(ledVerde, LOW);
}

void prenderVerde()
{
  digitalWrite(ledRojo, LOW);
  digitalWrite(ledAmarillo, LOW);
  digitalWrite(ledVerde, HIGH);
}
