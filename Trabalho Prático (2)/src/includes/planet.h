#ifndef PLANET_
#define PLANET_

#include <string>
#include <iostream>

class Planet{
	private:
		int time_s;
		std::string _name;
	public:
		void set_time(int);
		void set_name(std::string);
		int get_time();
		std::string get_name();
};


#endif