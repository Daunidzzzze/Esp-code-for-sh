#include <Wire.h> // Подключяем библиотеку Wire (для I2C)
#include <BH1750.h> // Подключяем библиотеку для bh1750

BH1750 lightMeter; // Объявляем объект lightMeter

void setup() {
  Serial.begin(9600); // Запускаем последовательный порт
  Wire.begin(); // Инициализируем шину I2C
  lightMeter.begin(); // Инициализируем и запускаем BH1750
  Serial.println(F("BH1750 тест"));
}

void loop() {
  float lux = lightMeter.readLightLevel(); //Считываем показания
  Serial.print("Light: "); // Отправляем значение освещенности в последовательный порт
  Serial.print(lux);
  Serial.println(" lx");
  delay(1000); // раз в секунду, пока что с делай
}
