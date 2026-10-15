// Aula 01 - Desafio: padrão de alerta sem delay().
// Dois pulsos curtos + pausa. O loop nunca trava, então na Aula 02
// o rastreador consegue ler o lacre enquanto o LED pisca.
const int PINO_LED = 8;

// Duração de cada fase: aceso, apagado, aceso, pausa longa
const unsigned long FASES_MS[] = {200, 200, 200, 1400};
const int NUM_FASES = 4;

int fase = 0;
unsigned long inicioFase = 0;

void setup() {
  pinMode(PINO_LED, OUTPUT);
  digitalWrite(PINO_LED, HIGH);   // fase 0 começa acesa
  inicioFase = millis();
}

void loop() {
  if (millis() - inicioFase >= FASES_MS[fase]) {
    inicioFase += FASES_MS[fase];          // soma o tempo exato, sem acumular atraso
    fase = (fase + 1) % NUM_FASES;          // avança e volta ao 0 depois da última
    digitalWrite(PINO_LED, (fase % 2 == 0) ? HIGH : LOW);  // fases pares = aceso
  }
  // aqui entra a leitura do lacre na Aula 02
}
