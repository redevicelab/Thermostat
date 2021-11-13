/*
	thermostat - библиотека классического терморегулятора с верхним или нижним порогом срабатывания
	- Настройка гистерезиса, 
	- Выбор уровня выходного сигнала, 
	- Направления регулирования(нагрев или охлождение)
	Напралвение регулирования если установлено HEAT то это нагрев при достижении 
	установленой температуры выподнится действие по подачи управляющего сигнала на 
	исполняемое устроство(пример реле), При достижении нижнего парога 

*/

#if defined(ARDUINO)
	#include <Arduino.h>
#endif
#ifndef thermostat_h
#define thremostat_h

#define HEAT false
#define COOL true
#define LOW false
#define HIGH true

class Thermostat
{
public:

	Thermostat();    					// Кострукторы
	Thermostat(bool dir);				//		класса
	Thermostat(bool dir, bool level);	//			Thermostat
	~Thermostat();						// Деструктор
	void setInputValue(float val);		// Принимает значение температуры			
	void setPointValue(float val);		// Установка точки срабатывания  
	void setHysteresis(float val);		// Установка значения гистерезиса
	bool getResult();					// Функция получения результат уровня сигнала для исполняющего устройства(Например: реле)
	void setDirection(bool dir);		// Установка направление регулирования
	void setLevelOutput(bool level);	// Установка уровня сигнала
	bool getOutputLevel();				// Получение текущего уровня

private:
	float _input = 0; 					// Принимает значение температуры
	float _point = 0;					// Принимает значения точки срабатывания
	float _hysteresis = 0;				// Принимает значения гистерезиса
	bool _direction = false;			// Переменная направления срабатывание термостата
	bool _level = false;				// Инвертирует значение output
	bool _output = false;				// Выходное значение
	bool compute();						// Вычисление
	bool convertLevel(bool output);		// Инвертирование выходного сигнала
};
#endif
