#include "String.hpp"
#include <cstring>

String::String(const char *str)
try
: _size(strlen(str)), _str(strcpy(new char[strlen(str) + 1], str))
{
	std::cout << "Default constructor called" << std::endl;
}
catch (std::exception &e)
{
	std::cout << "Exception in String constructor" << std::endl;
	if (_str)
		delete[] _str;
}

String::String(String const &s)
try
: _size(s.size()), _str(strcpy(new char[strlen(s.c_str()) + 1], s.c_str()))
{
	std::cout << "Copy constructor called" << std::endl;
}
catch (std::exception &e)
{
	std::cout << "Exception in String copy constructor" << std::endl;
	if (_str)
		delete[] _str;
}

String::~String()
{
	std::cout << "Destructor called" << std::endl;
	if (_str)
		delete[] _str;
}
