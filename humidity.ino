#include "DHT.h"
#define DHTPIN 2 // пин для подключения датчика DHT
#define DHTTYPE DHT11 

DHT dht(DHTPIN, DHTTYPE); // создание экземпляра объекта DHT

const int pinRED=5; // вывод красной ноги RGB-светодиода?
const int pinGREEN=4; // вывод зеленой ноги RGB-светодиода
const int pinBLUE=3; // вывод синей ноги RGB-светодиода

void setup() {
Serial.begin(9600);
dht.begin(); // запуск датчика DHT

// настройка выводов подключения к RGB светодиоду
pinMode(pinRED,OUTPUT);
pinMode(pinGREEN,OUTPUT);
pinMode(pinBLUE,OUTPUT);
}

void loop() {
float h = dht.readHumidity(); // получение данных влажности

// ошибочные данные с датчика!
if (isnan(h)) {
Serial.println("Failed to read from DHT");
set#000000;

} else {

Serial.print("Humidity: ");
Serial.println(h);

if(h<40)
set#010000;
else if(h>60)
set#000001;
else
set#000100;
}
delay(5000); // пауза 5 секунд, пока что так
}

// процедура установки цвета для RGB-светодиода
void setRGB(int R, int G, int B) {
digitalWrite(pinRED,R); // сухо (<40%)
digitalWrite(pinGREEN,G); // оптимальная влажность воздуха для человека (40 – 60%)
digitalWrite(pinBLUE,B); // повышенная влажность ( >60%)
}
