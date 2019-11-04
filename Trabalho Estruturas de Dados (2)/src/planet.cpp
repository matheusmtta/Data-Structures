#include "includes/planet.h"
#include <string>

void Planet::set_name(std::string name){
	this->_name = name;
}

void Planet::set_time(int s){
	this->time_s = s;
}

std::string Planet::get_name(){
	return this->_name;
}

int Planet::get_time(){
	return this->time_s;
}