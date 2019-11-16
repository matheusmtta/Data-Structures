#ifndef _TEXT
#define _TEXT

#include <string>
#include <iostream>

class Word{
	private:
		std::string name;
		std::string code;
	public:
		int count = 0;
		std::string get_name();
		std::string get_code();
		int get_count();
		void set_count(int);
		void set_name(std::string);
		void set_code(std::string);
		void display();
};



#endif