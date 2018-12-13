#include "String.hpp"
#include <cstring>

#define BUF 256

String::String(const char *str)
try
{
	if (!str)
	{
		_size = 0;
		_str = nullptr;
	}
	else
	{
		_size = strlen(str);
		_str = strcpy(new char[strlen(str) + 1], str);
	}
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
{
	if (!s._str)
	{
		_size = 0;
		_str = nullptr;
	}
	else
	{
		_size = s.size();
		_str = strcpy(new char[strlen(s.c_str()) + 1], s.c_str());
	}
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

//OPERATORS

String & String::operator=(String const &s)
{
	std::cout << "Operator = called" << std::endl;
	if (this != &s)
	{
		if (_str)
			delete [] _str;
		if (!s._str)
		{
			_size = 0;
			_str = nullptr;
		}
		else
		{
			_size = s.size();
			_str = strcpy(new char[strlen(s.c_str()) + 1], s.c_str());
		}
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
	if (s._str)
		os << s._str;
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

//FUNCTIONS

size_t	String::size() const
{
	return _size;
}

char*	String::c_str() const
{
	return _str;
}

void	String::append(String const &s)
{
	if (!s._str)
		return ;

	char *tmp = new char[_size + s.size() + 1];
	if (_str)
		tmp = strcpy(tmp, _str);
	tmp = strcat(tmp, s._str);
	tmp[_size + s.size()] = '\0';

	if (_str)
		delete [] _str;
	_str = tmp;
	_size = strlen(tmp);
}

int		String::compare(String const &s) const
{
	if (_str && !s._str)
		return 1;
	else if (!_str && s._str)
		return -1;
	else if (!_str && !s._str)
		return 0;
	else
		return strcmp(_str, s._str);
}

size_t	String::length() const
{
	return _size;
}

void	String::resize(size_t n)
{
	char *tmp_str = new char[n + 1];
	if (_str)
	{
		strncpy(tmp_str, _str, n);
		tmp_str[n] = '\0';
	}
	else
		memset(tmp_str, '\0', n + 1);

	if (_str)
		delete [] _str;
	_str = tmp_str;
	_size = n;
}

void	String::clear()
{
	if (_str)
		delete[] _str;
	_str = nullptr;
	_size = 0;
}

void	String::swap(String & s)
{
	size_t	tmp_size;
	char*	tmp_str;

	tmp_size = this->_size;
	this->_size = s._size;
	s._size = tmp_size;

	tmp_str = this->_str;
	this->_str = s._str;
	s._str = tmp_str;
}

size_t		String::substr(String const &s)
{
	if (!_str || !s._str)
		return (SIZE_MAX);

	int	i = 0;
	int	j = 0;
	int	k = 0;

	char *s_str = s.c_str();

	if (*s_str == '\0')
		return (0);
	while (_str[i] != '\0')
	{
		j = 0;
		k = i;
		while (_str[k] == s_str[j])
		{
			k++;
			j++;
			if (s_str[j] == '\0')
				return (i);
		}
		i++;
	}
	return (SIZE_MAX);
}

void	String::insert(size_t pos, String const &s)
{
	if (!s._str || !_str || pos >= _size)
		return ;

	char* tmp_str = new char[_size + s.size() + 1];

	strncpy(tmp_str, _str, pos);
	strncpy(tmp_str + pos, s.c_str(), s.size());
	strncpy(tmp_str + pos + s.size(), _str + pos, _size - pos);

	_size += s.size();
	tmp_str[_size] = '\0';

	delete [] _str;
	_str = tmp_str;
}

void	String::insert(size_t pos, char c)
{
	if (!_str || pos >= _size)
		return ;

	char* tmp_str = new char[_size + 1 + 1];

	strncpy(tmp_str, _str, pos);
	tmp_str[pos] = c;
	strncpy(tmp_str + pos + 1, _str + pos, _size - pos);

	_size += 1;
	tmp_str[_size] = '\0';

	delete [] _str;
	_str = tmp_str;
}

