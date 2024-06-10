const int ledVerde = 9; // Pino do LED vermelho
const int ledLaranja = 10; // Pino do LED verde

void setup() {
  pinMode(ledVerde, OUTPUT); // Define o pino do LED vermelho como saída
  pinMode(ledLaranja, OUTPUT); // Define o pino do LED verde como saída
}

void loop() {
  int leituraSensor = analogRead(A0); // Lê a tensão do voltímetro
  float voltagem = leituraSensor * (5.0 / 1023.0); // Converte a leitura para volts

  if (voltagem < 5.0) { // Se a voltagem for menor que 5 volts
    digitalWrite(ledVerde, HIGH); // Acende o LED vermelho
    digitalWrite(ledLaranja, LOW); // Apaga o LED verde
  } else { // Se a voltagem for maior ou igual a 5 volts
    digitalWrite(ledVerde, LOW); // Apaga o LED vermelho
    digitalWrite(ledLaranja, HIGH); // Acende o LED verde
  }
}
