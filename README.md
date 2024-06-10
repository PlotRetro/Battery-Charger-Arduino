# Carregador de Bateria com Arduino e Tinkercad
Este é um projeto de um carregador de bateria de 9 volts utilizando Arduino e Tinkercad. O circuito controla a carga da bateria, interrompendo-a quando estiver totalmente carregada.


## Componentes Utilizados

### Arduino Uno R3

![Arduino Uno R3](https://github.com/PlotRetro/Battery-Charger-Arduino/blob/main/assets/images/Arduino_Uno_R3.PNG)

### Capacitor Polarizado

![Capacitor Polarizado](https://github.com/PlotRetro/Battery-Charger-Arduino/blob/main/assets/images/Capacitor_Polarizado.PNG)

### Multímetro (Modo Tensão)

![Multímetro](https://github.com/PlotRetro/Battery-Charger-Arduino/blob/main/assets/images/Multimetro.PNG)

### Resistor

![Resistor](https://github.com/PlotRetro/Battery-Charger-Arduino/blob/main/assets/images/Resistor.PNG)

### LEDs

![LEDs](https://github.com/PlotRetro/Battery-Charger-Arduino/blob/main/assets/images/LEDs.PNG)

### Interruptor

![Interruptor](https://github.com/PlotRetro/Battery-Charger-Arduino/blob/main/assets/images/Interruptor.jpg)

### Diodo Zener

![Diodo Zener](https://github.com/PlotRetro/Battery-Charger-Arduino/blob/main/assets/images/Diodo_Zener.PNG)

### Fonte de Energia

![Fonte de Energia](https://github.com/PlotRetro/Battery-Charger-Arduino/blob/main/assets/images/Fonte_Energia.PNG)

# O Circuito

![Circuito](https://github.com/PlotRetro/Battery-Charger-Arduino/blob/main/assets/images/Circuito.jpg)


# Funcionamento do Circuito
- **Fonte de Energia:** Fornece a corrente para carregar a bateria.
- **Arduino:** Controla o transistor e lê a tensão do multímetro.
- **Multímetro:** Monitora a tensão do capacitor (bateria).
- Interruptor
- **LEDs:** Indicam o estado da carga (Laranja para carregando, Verde para carregado).

## O Código no Arduíno

```cpp
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
```

# Colaboradores

- Pedro Gabriel ([PlotRetro](https://github.com/PlotRetro))
- Carlos Augusto ([carlosaugusto007](https://github.com/carlosaugusto007))

---
# Links do circuitos no TinkerCad 

https://www.tinkercad.com/things/8IQl2ACAptK-smashing-luulia/editel?sharecode=enSikqyTxTC13He-DLshAYLHZry3WM0tuvKwUMCJNb0

---

Obrigado por visualizar nosso projeto! Se tiver alguma dúvida ou sugestão, sinta-se à vontade para entrar em contato.

