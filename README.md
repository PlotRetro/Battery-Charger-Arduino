# Carregador de Bateria com Arduino e Tinkercad
Este é um projeto de um carregador de bateria de 9 volts utilizando Arduino e Tinkercad. O circuito controla a carga da bateria, interrompendo-a quando estiver totalmente carregada.


## Componentes Utilizados

Aqui estão os componentes utilizados para montar o carregador de bateria de 9 volts:

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

### Transistor PNP (BJT)

![Transistor PNP](https://github.com/PlotRetro/Battery-Charger-Arduino/blob/main/assets/images/Transistor_PNP.PNG)

### Diodo Zener

![Diodo Zener](https://github.com/PlotRetro/Battery-Charger-Arduino/blob/main/assets/images/Diodo_Zener.PNG)

### Fonte de Energia

![Fonte de Energia](https://github.com/PlotRetro/Battery-Charger-Arduino/blob/main/assets/images/Fonte_Energia.PNG)

# O Circuito

![Circuito](https://github.com/PlotRetro/Battery-Charger-Arduino/blob/main/assets/images/Circuito.png)


# Funcionamento do Circuito
- **Fonte de Energia:** Fornece a corrente para carregar a bateria.
- **Arduino:** Controla o transistor e lê a tensão do multímetro.
- **Multímetro:** Monitora a tensão do capacitor (bateria).
- **Transistor PNP:** Controla a passagem de corrente para a bateria.
- **LEDs:** Indicam o estado da carga (Laranja para carregando, Verde para carregado).

## O Código no Arduíno

```cpp
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
```

# Montagem do Circuito

Para montar o circuito do carregador de bateria de 9 volts utilizando Arduino e Tinkercad, siga estas etapas cuidadosamente:

1. **Preparação dos Componentes**:
   - Reúna todos os componentes necessários listados na seção "Componentes Utilizados".
   - Certifique-se de ter acesso a um computador com conexão à internet para acessar o Tinkercad e realizar a simulação do circuito.

2. **Acesso ao Tinkercad**:
   - Acesse o site do [Tinkercad](https://www.tinkercad.com/) e faça login na sua conta (ou crie uma nova conta, se necessário).

3. **Criar Novo Projeto**:
   - Crie um novo projeto e selecione a categoria "Circuitos Eletrônicos".

4. **Adicionar Componentes**:
   - Arraste os componentes necessários da biblioteca do Tinkercad para a área de trabalho, incluindo o Arduino Uno R3, o capacitor polarizado, o multímetro, resistores, LEDs, transistor PNP e o diodo Zener.

5. **Incluir o Código do Arduino**:
   - Clique no botão "Código" para abrir a seção do editor de código no Tinkercad.
   - Copie e cole o código do Arduino fornecido na seção "O Código no Arduíno" deste documento.
   - Verifique o código para garantir que não haja erros e clique em "Simular" para iniciar a simulação.

6. **Conectar os Componentes**:
   - Conecte os componentes conforme as conexões descritas na seção "Conexões e Esquema". Certifique-se de seguir as conexões com precisão para garantir o funcionamento correto do circuito.

7. **Verificar as Conexões**:
   - Antes de prosseguir, verifique novamente todas as conexões para garantir que não haja erros ou conexões soltas.

8. **Teste Inicial**:
   - Antes de iniciar a simulação, verifique se todos os componentes estão configurados corretamente e se o circuito está montado conforme as especificações.

9. **Iniciar a Simulação**:
   - Inicie a simulação no Tinkercad para testar o funcionamento do circuito.
   - Observe atentamente o comportamento do circuito durante a simulação para garantir que todos os componentes estejam funcionando conforme o esperado.

10. **Ajustes e Correções**:
   - Se necessário, faça ajustes no circuito e corrija quaisquer problemas encontrados durante a simulação.

11. **Finalização**:
   - Após concluir com sucesso a simulação e verificar o funcionamento adequado do circuito, salve o projeto no Tinkercad.

Parabéns! Você montou com sucesso o carregador de bateria utilizando Arduino e Tinkercad. Agora você está pronto para explorar e experimentar diferentes cenários de carga de bateria com o seu circuito.

# Colaboradores

- Pedro Gabriel ([PlotRetro](https://github.com/PlotRetro))
- Carlos Augusto ([carlosaugusto007](https://github.com/carlosaugusto007))

---

Obrigado por visualizar nosso projeto! Esperamos que tenha encontrado todas as informações necessárias para entender e reproduzir o carregador de bateria de 9 volts utilizando Arduino e Tinkercad. Se tiver alguma dúvida ou sugestão, sinta-se à vontade para entrar em contato.

