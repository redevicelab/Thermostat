#include "Thermostat.h"
#include <Arduino.h>

Thermostat::Thermostat()
{
	_direction = false;
	_level = false;
	_output = !_level;
}

Thermostat::Thermostat(bool dir)
{
	_direction = dir;
	_level = false;
	_output = !_level;
}

Thermostat::Thermostat(bool dir, bool level)
{
	_direction = dir;
	_level = level;
	_output = !_level;
}

Thermostat::~Thermostat()
{
}

void Thermostat::setDirection(bool dir) {
	_direction = dir;
}

void Thermostat::setLevelOutput(bool level) {
	_level = level;
}

bool Thermostat::compute() {
	if (_direction) {//На охлаждение
		if (input > (setPoint + hysteresis)) _output = true; //on
		else if (input < setPoint) _output = false; //off
	}
	else if (!_direction) {//На нагрев
		if (input < (setPoint - hysteresis)) _output = true; //on
		else if (input > setPoint) _output = false; //off
	}
	return _output;
}

bool Thermostat::convertLevel(bool output) {
	if (!_level)
	{
		output = !output;
	}
	return output;
}

bool Thermostat::getResult() {
	return convertLevel(compute());
}

bool Thermostat::getOutputLevel(){
	return  _output;
}

