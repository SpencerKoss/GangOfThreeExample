#ifndef GCHARACTER_H
#define GHARACTER_H
#include <iostream>
#include <string>


class GCharacter
{
	friend std::ostream& operator<<(std::ostream& os, const GCharacter& gc);
public:
	static const int DEFAULT_CA = 5;

	//Constructor
	GCharacter(std::string name = "Spencer", int capacity = DEFAULT_CA);

	//Copy Constructor
	GCharacter(const GCharacter& source);

	//Overloaded Assignment Operator
	GCharacter& operator=(const GCharacter& source);

	//Destructor To Come 
	~GCharacter();

	//Insert Tool into tool holder
	void insert(const std::string& toolName);

private:
	//Data Members
	std::string name;
	int capacity;
	int used;
	std::string* toolHolder;

};

#endif // !GCharacter

