#include "Thermostat.h"

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

void Thermostat::setInputValue(float val){
	_input = val;
}

void Thermostat::setPointValue(float val){
	_point = val;
}

void Thermostat::setHysteresis(float val){
	_hysteresis = val;
}

void Thermostat::setDirection(bool dir) {
	_direction = dir;
}

void Thermostat::setLevelOutput(bool level) {
	_level = level;
}

bool Thermostat::compute() {
	if (_direction) 											//COOL
	{
		if (_input > (_point + _hysteresis)) _output = true; 	//ON
		else if (_input < _point) _output = false; 				//OFF
	}
	else if (!_direction) 										//HEAT
	{
		if (_input < (_point - _hysteresis)) _output = true; 	//ON
		else if (_input > _point) _output = false; 				//OFF
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
	return _output;
}

