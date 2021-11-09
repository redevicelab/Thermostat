# Thermostat
Arduino library, the classic thermostat 
# Thermostat
Многофункциональный термостат для Arduino
- Режим
- Возможности

### Совместимость
Совместима со всеми Arduino платформами (используются Arduino-функции)

## Содержание
- [Установка](#install)
- [Инициализация](#init)
- [Использование](#usage)
- [Пример](#example)
- [Версии](#versions)
- [Баги и обратная связь](#feedback)

<a id="install"></a>
## Установка
- [Скачать библиотеку](https://github.com/master.zip) .zip архивом для ручной установки:
    - Распаковать и положить в *C:\Program Files (x86)\Arduino\libraries* (Windows x64)
    - Распаковать и положить в *C:\Program Files\Arduino\libraries* (Windows x32)
    - Распаковать и положить в *Документы/Arduino/libraries/*
    - (Arduino IDE) автоматическая установка из .zip: *Скетч/Подключить библиотеку/Добавить .ZIP библиотеку…* и указать скачанный архив

<a id="init"></a>
## Инициализация
```cpp
// 
Thermostat thermo;                                   

```

<a id="usage"></a>
## Использование
```cpp
void func();

```

<a id="example"></a>
## Пример
```cpp
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
```

<a id="versions"></a>
## Версии
- v1.0

<a id="feedback"></a>
## Баги и обратная связь
При нахождении багов создавайте **Issue**
