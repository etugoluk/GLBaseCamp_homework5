#include "String.hpp"
#include <cstring>

String & String::operator=(String const &s)
{
	std::cout << "Operator = called" << std::endl;
	if (this != &s)
	{
		delete [] _str;
		_size = s.size();
		_str = strcpy(new char[_size + 1], s.c_str());
	}
	return *this;
}

String & String::operator+=(String const &s)
{
	std::cout << "Operator += called" << std::endl;
	append(s);
	return *this;
}

std::istream & operator>>(std::istream &is, String &s)
{
	if (s._str)
		delete [] s._str;

	s._str = new char[BUF + 1];
	is.getline(s._str, BUF);
	s._size = strlen(s._str);
	
	return is;
}

std::ostream & operator<<(std::ostream &os, String const &s)
{
	os << s.c_str();
	return os;
}

bool operator==(String const &s1, String const &s2)
{
	return !(s1 != s2);
}

bool operator!=(String const &s1, String const &s2)
{
	return (s1.compare(s2));
}
