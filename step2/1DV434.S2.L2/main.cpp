/**********************************************************************/
// File:	main.cpp
// Summary: The main file for the second lab in step two.
// Version:	Version 1.0 - 2017-04-18
// Owner:	Kim Wahlman
// -------------------------------------------
// Log:	2017-04-18	Created and implemented the file. Kim
/**********************************************************************/

#include <iostream>
#include "String.h"
using std::cout;
using std::cin;
using std::endl;

class Application
{
public:
	int run();
};

int Application::run()
{
	String str1("Hello ");
	String str2(str1);
	cout << str1 << str2 << endl;			// Ska skriva ut "Hello Hello " 
	str2 = "my world!";
	cout << str1 << str2 << endl;			// Ska skriva ut "Hello my world!"
	String str3;
	cout << "Enter a name: "; 
	cin >> str3;							// (...Användaren skriver t.ex. "Pluto"...)
	str2 = str1 + str3;
	cout << str2 << endl;					// Ska skriva ut "Hello Pluto"
	str2 = "Goodbye " + str3;
	cout << str2 << endl;					// Ska skriva ut "Goodbye Pluto" 
	cout << str1 << "and " << "Goodbye " 
											// Ska skriva ut "Hello and Goodbye is not the same word!" return 0;
		 << (str1 == "Goodbye " ? "is " : "is not ") << "the same word!\n";
	cin.ignore();
	cin.get();
	return 0;
}

int main()
{
	Application myApp;
	return myApp.run();
}
