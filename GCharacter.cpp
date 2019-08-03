#include "pch.h"
#include "GCharacter.h"
using namespace std;

//Constructor
GCharacter::GCharacter(string n, int cap)
{
	name = n;
	capacity = cap;
	used = 0;
	toolHolder = new string[cap];
}

//Copy Constructor
GCharacter::GCharacter(const GCharacter& source) {
	cout << "Copy Constructor Called\n";
	this->name = source.name;
	this->capacity = source.capacity;
	used = source.used;
	toolHolder = new string[source.capacity];

	//Copy functions operates the same way as a for loop would
	copy(source.toolHolder, source.toolHolder + used, this->toolHolder);

	/*for (int i = 0; i < used; i++) {
		toolHolder[i] = source.toolHolder[i];
	}*/
}

//Overloaded Assignment Operator
GCharacter& GCharacter::operator=(const GCharacter& source) {
	cout << "Overloaded Assignment Call\n";

	//Check for Self-Assignment
	//gc1 = gc1;
	if (this == &source) {
		return *this; //Returning GCharacter Object
	}

	this->name = source.name;
	this->capacity = source.capacity;
	used = source.used;
	//Copy functions operates the same way as a for loop would
	copy(source.toolHolder, source.toolHolder + used, this->toolHolder);

	return *this; //Returning GCharacter Object
}
GCharacter::~GCharacter()
{
	cout << "Destructor Called " << this->name << " @ this memory location " << this << endl;
	delete[] toolHolder;
}

//This is for inserting a new tool into ToolHolder
void GCharacter::insert(const string& toolName) {
	if (used == capacity) {
		cout << "Full Toolkit! Out of luck!\n";
	}
	else {
		toolHolder[used] = toolName;
		used++;
	}
}

std::ostream& operator<<(std::ostream& os, const GCharacter& gc) {
	os << "Game Character " << gc.name << "\n has the following Tools: " << std::endl << "| ";

	for (int i = 0; i < gc.used; i++) {
		os << gc.toolHolder[i] + " | ";

	}
	return os << std::endl;
}