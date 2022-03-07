#define smokePin A0    // определяем аналоговый выход к которому подключен датчик
int sensorThres = 400; // пороговое значение, при котором считаем что газ есть

void setup() {
  Serial.begin(9600);
}

void loop() {
  int analogSensor = analogRead(smokePin);    // считываем значения с аналогового входа
  Serial.print (analogSensor);                // выводим в порт значение сигнала с датчика

  if (analogSensor > sensorThres) {  // если значение больше допустимого
    Serial.println(" Gaz!");         // выводим в порт надпись, что газ есть
  }
  else {                             // иначе
   Serial.println(" normal");        // выводим в порт надпись, что газа нет
  }
  delay(500);  // задержка в 500 миллисекунд, рока что delay
}
