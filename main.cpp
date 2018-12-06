#include "String.hpp"

int main()
{
	//default constructor with default argument
	String s1;
	std::cout << "s1: " << s1 << std::endl; //operator <<

	//operator >>
	// std::cout << "Enter your string: " << std::endl;
	// std::cin >> s1;
	// std::cout << "s1 user string: " << s1 << std::endl;

	//default constructor with user argument
	String s2("Hello");
	std::cout << "s2: " << s2 << std::endl;

	//copy constructor
	String s3 = s2;
	std::cout << "s3: " << s3 << std::endl;

	//copy constructor
	String s4(s2);
	std::cout << "s4: " << s4 << std::endl;

	//operator ==
	String s5;
	s5 = "Hi!";
	std::cout << "s5: " << s5 << std::endl;

	//operator +=
	s3 += " world!";
	std::cout << "s3: " << s3 << std::endl;

	//operator ==
	if (s2 == s3)
		std::cout << "s2 and s3 are equal" << std::endl;
	else
		std::cout << "s2 and s3 are not equal" << std::endl;

	//operator !=
	if (s2 != s4)
		std::cout << "s2 and s4 are not equal" << std::endl;
	else
		std::cout << "s2 and s4 are equal" << std::endl;

	//get size of string
	std::cout << "s5 size: " << s5.size() << std::endl;

	//get char * presentation of string
	std::cout << "s5 in char*: " << s5.c_str() << std::endl;

	//append function
	s5.append(" guys!");
	std::cout << "append to s5: " << s5 << std::endl;

	//compare function
	std::cout << "s1 compare to s2: " << s1.compare(s2) << std::endl;
	std::cout << "s2 compare to s4: " << s2.compare(s4) << std::endl;

	//length function
	std::cout << "s1 size: " << s1.length() << std::endl;

	//resize function
	std::cout << "s3 as you remember: " << s3 << std::endl;
	s3.resize(20);
	std::cout << "s3 resize to 20 symbols: " << s3 << std::endl;
	s3.resize(5);
	std::cout << "s3 resize to 5 symbols: " << s3 << std::endl;
	s3.resize(0);
	std::cout << "s3 resize to 0 symbols: " << s3 << std::endl;

	//clear funtion
	s2.clear();
	std::cout << "Clear s2 has " << s5.size() << " size" << std::endl;

	//swap function
	std::cout << "Before swap: " << s3 << std::endl;
	std::cout << "s4: " << s4 << std::endl;
	std::cout << "s5: " << s5 << std::endl;
	s4.swap(s5);
	std::cout << "After swap: " << s3 << std::endl;
	std::cout << "s4: " << s4 << std::endl;
	std::cout << "s5: " << s5 << std::endl;

	//substr function
	std::cout << "find guys in s4 " << std::endl;
	std::cout << s4.substr("guys") << std::endl;
	std::cout << "not find hello in s4 " << std::endl;
	std::cout << s4.substr("hello") << std::endl;

	//insert string function
	s4.insert(3, " Dear");
	std::cout << s4 << std::endl;
	s4.insert(20, " Dear");
	std::cout << s4 << std::endl;

	//insert char function
	s4.insert(3, 'O');
	std::cout << s4 << std::endl;
	s4.insert(20, '!');
	std::cout << s4 << std::endl;

	return 0;
}