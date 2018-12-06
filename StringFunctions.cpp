#include "String.hpp"
#include <cstring>

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
	char *tmp = new char[this->_size + s.size() + 1];
	tmp = strcpy(tmp, this->_str);
	tmp = strcat(tmp, s.c_str());
	tmp[this->_size + s.size()] = '\0';

	delete [] this->_str;
	this->_str = tmp;
	this->_size = strlen(tmp); 
}

int		String::compare(String const &s) const
{
	return strcmp(this->_str, s.c_str());
}

size_t	String::length() const
{
	return _size;
}

void	String::resize(size_t n)
{
	char *tmp_str = new char[n + 1];
	strncpy(tmp_str, _str, n);
	tmp_str[n] = '\0';

	delete [] _str;
	_str = tmp_str;
	_size = n;
}

void	String::clear()
{
	if (_str)
		delete[] _str;
	_str = NULL;
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
	if (pos >= _size)
		return ;

	char* tmp_str = new char[_size + s.size() + 1];

	strncpy(tmp_str, _str, pos);
	strncpy(tmp_str + pos, s.c_str(), s.size());
	strncpy(tmp_str + pos + s.size(), _str + pos, _size - pos);

	_size += s.size();
	tmp_str[_size] = '\0';

	if (_str)
		delete [] _str;

	_str = tmp_str;
}

void	String::insert(size_t pos, char c)
{
	if (pos >= _size)
		return ;

	char* tmp_str = new char[_size + 1 + 1];

	strncpy(tmp_str, _str, pos);
	tmp_str[pos] = c;
	strncpy(tmp_str + pos + 1, _str + pos, _size - pos);

	_size += 1;
	tmp_str[_size] = '\0';

	if (_str)
		delete [] _str;

	_str = tmp_str;
}

