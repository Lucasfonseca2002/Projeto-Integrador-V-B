# Projeto-Integrador-V-B

Sistema de Monitoramento Ambiental para Casa Inteligente

# Descrição

Este projeto implementa um sistema de monitoramento ambiental para uma casa inteligente, utilizando sensores para medir temperatura, umidade e luminosidade. Os dados são exibidos em um display LCD e, caso a temperatura ultrapasse um limite crítico, um LED de alerta é acionado. O sistema também pode ser expandido para integração com outros dispositivos de automação residencial.

### Funcionalidades

Monitoramento em tempo real de:

- Temperatura (°C),
- Umidade relativa (%),
- Luminosidade (lux).
  
Exibição dos dados em um display LCD 16x2.

Alerta visual (LED) quando a temperatura ultrapassa o limite configurado.

Comunicação via monitor serial para depuração ou coleta de dados.

### Aplicações

Controle ambiental em casas inteligentes.


Integração com sistemas de automação, como:
- Controle de ar-condicionado,
- Ajuste automático de iluminação,
- Monitoramento remoto via IoT.
  
### Componentes Utilizados

#### Hardware
- Arduino Uno (ou similar).
- LM35: Sensor de temperatura analógico.
- Sensor de Umidade: Sensor analógico para medir a umidade relativa.
- LDR: Sensor de luminosidade.
- Display LCD 16x2: Para exibição dos dados.
- LED: Indicador visual de alerta.
- Resistores, fios de conexão e protoboard.
  
### Software
- IDE Arduino: Para desenvolvimento e upload do código.
- Biblioteca LiquidCrystal: Para controle do display LCD.
 
