#ifndef thermostat_h
#define thremostat_h
#include <Arduino.h>

#define HEAT false
#define COLD true
#define LOW false
#define HIGH true

/*
	thermostat - библиотека классического терморегулятора с верхним или нижним порогом срабатывания
	- Настройка гистерезиса, 
	- Выбор уровня выходного сигнала, 
	- Направления регулирования(нагрев или охлождение)

*/

class Thermostat
{
public:
	float input = 0; 					// Принимает значение температуры
	float setPoint = 0;					// Установка значения темперуры
	float hysteresis = 0;				// Установка значения гистерезиса
	Thermostat();    					// Кострукторы
	Thermostat(bool dir);				//	класса
	Thermostat(bool dir, bool level);	//		Thermostat
	~Thermostat();						// Деструктор класса ну тут он как бы не сильно то и нужен
	bool getResult();					// Функция получения результат уровня сигнала для исполняющего устройства(Например: реле)
	void setDirection(bool dir);		// Установка направление регулирования
	void setLevelOutput(bool level);	// Установка уровня сигнала
	bool getOutputLevel();

private:
	bool _direction = false;
	bool _level = false;
	bool _output = false;
	bool compute();
	bool convertLevel(bool output);
};
#endif
