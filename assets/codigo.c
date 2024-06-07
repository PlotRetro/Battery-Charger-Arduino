const int ledVerde = 10;      // Pino do LED verde
const int ledLaranja = 9;     // Pino do LED laranja
const int transistorPin = 7;  // Pino digital para controle do transistor PNP
const unsigned long intervaloLeitura = 1000;  // Intervalo de leitura em milissegundos
unsigned long ultimaLeitura = 0;  // Armazena o tempo da última leitura

void setup() {
  pinMode(ledVerde, OUTPUT);     // Define o pino do LED verde como saída
  pinMode(ledLaranja, OUTPUT);   // Define o pino do LED laranja como saída
  pinMode(transistorPin, OUTPUT); // Define o pino do transistor como saída
  digitalWrite(transistorPin, HIGH); // Desativa a carga inicialmente
}

void loop() {
  unsigned long tempoAtual = millis(); // Obtém o tempo atual em milissegundos

  // Realiza a leitura do sensor de voltagem em intervalos regulares
  if (tempoAtual - ultimaLeitura >= intervaloLeitura) {
    ultimaLeitura = tempoAtual; // Atualiza o tempo da última leitura
    
    int leituraSensor = analogRead(A0); // Lê a tensão do voltímetro
    float voltagem = leituraSensor * (9.0 / 1023.0); // Converte a leitura para volts (assumindo 9 volts)

    // Controle do carregamento e dos LEDs baseado na voltagem
    if (voltagem < 5.0) {
      digitalWrite(ledLaranja, HIGH);  // Acende o LED laranja se a voltagem estiver abaixo de 5V
      digitalWrite(ledVerde, LOW);     // Apaga o LED verde
      digitalWrite(transistorPin, LOW); // Ativa o transistor PNP (para a carga)
    } else {
      digitalWrite(ledLaranja, LOW);   // Apaga o LED laranja
      digitalWrite(ledVerde, HIGH);    // Acende o LED verde se a voltagem for maior ou igual a 5V
      digitalWrite(transistorPin, HIGH); // Desativa o transistor PNP (interrompe a carga)
    }
  }
}
