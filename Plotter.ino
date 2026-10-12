void setup() {
  // Настройка аналоговых пинов для чтения сигналов с ATtiny13
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  // Инициализируем последовательный порт на высокой скорости (115200 бод)
  // Это необходимо, чтобы успевать передавать данные без задержек в Serial Plotter
  Serial.begin(115200);
}

void loop() {
  // Считываем текущее напряжение на каналах
  int chA = (digitalRead(A0) == HIGH) ? 1000 : 0;
  int chB = (digitalRead(A1) == HIGH) ? 450 : 0;

// Форматируем вывод под требования Arduino Serial Plotter:
  Serial.print("Channel_A:");
  Serial.print(chA);
  Serial.print(" ");
  Serial.print("Channel_B:");
  Serial.println(chB);

  // Пауза 15 мс убирает частые опросные "иголки" и превращает график в ровные монолитные блоки
  delay(15); 
}
