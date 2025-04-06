#include <LiquidCrystal.h>

// Definição de pinos
#define SENSOR_TEMP A1
#define SENSOR_UMI  A0
#define SENSOR_LDR  A2
#define LED_ALERTA  10  // Pino para o LED de alerta, ajustado para o pino 10

// Configuração do LCD (pinos RS, E, D4, D5, D6, D7)
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// Limites de operação
const float LIMITE_TEMPERATURA = 40.0; // Limite para acender o LED de alerta

void setup() {
  lcd.begin(16, 2);  // Inicializa o LCD
  pinMode(LED_ALERTA, OUTPUT);
  pinMode(SENSOR_TEMP, INPUT);
  pinMode(SENSOR_UMI, INPUT);
  pinMode(SENSOR_LDR, INPUT);

  Serial.begin(9600); // Inicia comunicação serial
}

void loop() {
  // Leitura dos sensores
  int leituraTemp = analogRead(SENSOR_TEMP);
  int leituraUmi  = analogRead(SENSOR_UMI);
  int leituraLuz  = analogRead(SENSOR_LDR);

  // Conversão da temperatura (LM35)
  float temperatura = (leituraTemp * (5.0 / 1023.0)) * 100.0;

  // Conversão da umidade para porcentagem (ajustando valores reais)
  const int VALOR_MINIMO = 300; // Valor mínimo obtido no monitor serial
  const int VALOR_MAXIMO = 700; // Valor máximo obtido no monitor serial
  int umidade = map(leituraUmi, VALOR_MINIMO, VALOR_MAXIMO, 0, 100);
  umidade = constrain(umidade, 0, 100); // Garante que o valor esteja entre 0 e 100%

  // Conversão da luminosidade para lux
  float luminosidadeLux = (1023.0 - leituraLuz) * (500.0 / 1023.0);

  // Atualiza o Monitor Serial
  Serial.print("Temperatura: "); Serial.print(temperatura, 1); Serial.println(" °C");
  Serial.print("Umidade: "); Serial.print(umidade); Serial.println(" %");
  Serial.print("Luminosidade: "); Serial.print(luminosidadeLux, 0); Serial.println(" lux");

  // Atualiza o LCD
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("T:"); lcd.print(temperatura, 1); lcd.print("C ");
  lcd.print("U:"); lcd.print(umidade); lcd.print("%");

  lcd.setCursor(0, 1);
  lcd.print("Luz: "); lcd.print(luminosidadeLux, 0); lcd.print("lux");

  // Verifica a temperatura e acende o LED de alerta se necessário
  if (temperatura > LIMITE_TEMPERATURA) {
    digitalWrite(LED_ALERTA, HIGH); // Acende o LED
  } else {
    digitalWrite(LED_ALERTA, LOW);  // Apaga o LED
  }

  delay(500); // Aguarda 0,5 segundos para a próxima leitura
}
