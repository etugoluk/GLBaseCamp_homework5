#pragma once

#include <iostream>

#define BUF 256

class String
{
	size_t	_size;
	char*	_str;
public:
	String(const char *str = "");
	String(String const &s);
	~String();

	size_t	size() const;
	char	*c_str() const;

	void	append(String const &s);
	int		compare(String const &s) const;
	size_t	length() const;
	void	resize(size_t n);
	void	clear();
	void	swap(String & s);
	size_t	substr(String const &s);
	void	insert(size_t pos, String const &s);
	void	insert(size_t pos, char c);

	String & operator=(String const &s);
	String & operator+=(String const &s);
	friend String operator+(String const &s1, String const &s2);

	friend std::istream & operator>>(std::istream &is, String &s);
	friend std::ostream & operator<<(std::ostream &os, String const &s);

	friend bool operator==(String const &s1, String const &s2);
	friend bool operator!=(String const &s1, String const &s2);

};

String operator+(String const &s1, String const &s2);

std::istream & operator>>(std::istream &is, String &s);
std::ostream & operator<<(std::ostream &os, String const &s);

bool operator==(String const &s1, String const &s2);
bool operator!=(String const &s1, String const &s2);