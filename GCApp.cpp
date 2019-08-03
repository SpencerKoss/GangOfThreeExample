#include "pch.h"
#include "GCharacter.h"
using namespace std;


GCharacter exampleCopyConstructor(GCharacter tempGC) {
	cout << "Copy Constructor called Twice " << endl;
	cout << "Once for the formal parameter being passed by value" << endl;
	cout << "Once for the return value " << endl;
	return tempGC;
}

int main()
{
	GCharacter gc1;

	gc1.insert("potion");
	gc1.insert("Crossbow");
	gc1.insert("Axe");
	gc1.insert("Helmet");
	gc1.insert("Chestguard");
	gc1.insert("Map");


	cout << gc1 << endl;
	GCharacter gc2("Bob, 5");
	gc2.insert("Axe");

	exampleCopyConstructor(gc2);

	//Copy Constructor
	GCharacter gc3 = gc2;

	//Overloaded Assignment Operator
	gc2 = gc1;

	cout << "gc2: " << gc2 <<  endl;
	cout << "gc1: " << gc1 << endl;
	cout << "gc3: " << gc3 << endl;
}
//OUTPUT:
//Copy Constructor Called
//Copy Constructor called Twice
//Once for the formal parameter being passed by value
//Once for the return value
//Copy Constructor Called
//Destructor Called Bob, 5 @ this memory location 004FF534
//Destructor Called Bob, 5 @ this memory location 004FF574
//Copy Constructor Called
//Overloaded Assignment Call
//gc2 : Game Character Spencer
//	has the following Tools :
//| potion | Crossbow | Axe | Helmet | Chestguard |
//
//gc1 : Game Character Spencer
//	has the following Tools :
//| potion | Crossbow | Axe | Helmet | Chestguard |
//
//gc3 : Game Character Bob, 5
//	has the following Tools :
//| Axe |
//
//Destructor Called Bob, 5 @ this memory location 004FF784
//Destructor Called Spencer @ this memory location 004FF7B4
//Destructor Called Spencer @ this memory location 004FF7E4