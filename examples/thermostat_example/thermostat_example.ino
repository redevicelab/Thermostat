#include "Thermostat.h"

//направление регулирования и вывод уровня сигнала
 Thermostat regulator(HEAT,LOW);
/*
НАпралвение регулирования если установлено HEAT то это нагрев при достижении 
установленой температуры выподнится действие по подачи управляющего сигнала на 
исполняемое устроство(пример реле), При достижении нижнего парога 
*/
void setup() {
  pinMode(13, OUTPUT);        // пин реле
  regulator.setPoint = 35;    // установка (ставим на 35 градусов)
  regulator.hysteresis = 5;   // ширина гистерезиса
}

void loop() {
  int temp;                 // например читаем с датчика температуру
  regulator.input = temp;   // сообщаем регулятору текущую температуру

  // getResult возвращает значение для управляющего устройства
  digitalWrite(3, regulator.getResult());  // отправляем на реле (ОС работает по своему таймеру)
  delay(100);
}
