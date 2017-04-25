#include "String.h"
#include <string>
#include <iostream>
#include "String.h"

// This constructor is used when
// for example the programmer do this:
// String string("Text");
String::String(const char* cstring) : _strLen(0)
{
	_strPtr = new char[strlen(cstring) + 1];	// Without + 1 junk will be displayed
	memcpy(_strPtr, cstring, strlen(cstring) + 1);
	//_strPtr[strlen(string)] = '\0'; // This causes problems!
	_strLen = strlen(cstring);
}

// This constructor is used when
// for example the programmer do this:
// String string(); or String string;
String::String() : _strLen(0)
{
	_strPtr = new char[10];
	for (size_t i = 0; i < 9; i++)
		_strPtr[i] = '0' + 0;
	_strPtr[9] = '\0';
}

// We need to free the memory!
// Check if _strPtr isn't a nullptr.
// Here my manually added '\0' caused a problem!
// That is why they are commented out.
String::~String()
{
 	if(_strPtr != nullptr)
		delete[] _strPtr;
}

// += Operator, will add 's' to the end of the current _strPtr
String& String::operator+=(const String& string)
{
	char* temp = new char[_strLen + string.getLength() + 1];
	size_t i = 0;
	for (; i < getLength(); i++)
		temp[i] = _strPtr[i];

	for (size_t j = 0; j < string.getLength(); j++)
		temp[i++] = string.toC_str()[j];

	//temp[_strLen + string.getLength()] = '\0';
	delete[] _strPtr;
	_strPtr = temp;
	_strLen += string.getLength();
	return *this;
}

// Will add _strPtr together with a String and return the result.
const String String::operator+(const String& string) const
{
	// This variable will temporarily hold our combined
	// c-string that will be passed on to a String.
	char* temp = new char[_strLen + string.getLength()];
	size_t i = 0;
	for (; i < getLength(); i++)
		temp[i] = _strPtr[i];

	for (size_t j = 0; j < string.getLength(); j++)
		temp[i++] = string.toC_str()[j];

	//temp[_strLen + s.getLength()] = '\0'; // This causes problems!
	String newString(temp);
	delete[] temp;
	return newString;
}

// Will add _strPtr together with a char* and return the result.
const String String::operator+(const char* cstring) const
{
	size_t tempLenght = strlen(cstring);
	size_t oldLengt = getLength();
	char* temp = new char[tempLenght + oldLengt];
	size_t i = 0;

	for (; i < oldLengt; i++)
		temp[i] = _strPtr[i];

	for (size_t j = 0; j < tempLenght; j++)
	{
		temp[i++] = cstring[j];
	}
	//temp[tempLenght + oldLengt] = '\0'; // This causes problems!
	String newString(temp);
	delete[] temp;
	return newString;
}

// Will assign the passed char* with the help of
// memcpy to _strPtr and return a String&.
String& String::operator=(const char* cstring)
{
	size_t tempLenght = 1 + strlen(cstring);
	_strPtr = new char[tempLenght];
	_strLen = tempLenght;

	// Copies the 'tempLenght' bytes from
	// 'cstring' to '_strPtr'.
	// It copies X bytes from the source to its destination.
	// destination, source, lenght.
	std::memcpy(_strPtr, cstring, tempLenght);
	return *this;
}

// 
String& String::operator=(const String& s)
{
	size_t tempLenght = 1 + s.getLength();
	_strPtr = new char[tempLenght];
	_strLen = tempLenght;

	if (tempLenght >= getLength())
		resize(tempLenght);
	
	//_strPtr[tempLenght] = '\0'; // This causes problems!
	std::memcpy(_strPtr, s.toC_str(), tempLenght);

	return *this;
}

// If the _strPtr target is to small, we need to resize it!
void String::resize(int size = 1)
{
	char* tempArray = new char[getLength() + size + 1]; // _strPtr;
	for (int i = 0; i < _strLen + size; i++)
		tempArray[i] = _strPtr[i];
	delete _strPtr;

	_strPtr = new char[_strLen + size];
	for (int i = 0; i < _strLen + size; i++)
		_strPtr[i] = tempArray[i];
	//_strPtr[_strLen + size] = '\0'; // This causes problems!
	delete tempArray;
	_strLen += size;
}

// Friends variant, without the keyword 'friend' 
// I wasn't allowed to have more than a single argument.
// This function will take a char and String and add
// them together and return the result.
const String operator+(const char * c, const String & s)
{
	size_t tempLenght = s.getLength();
	size_t oldLengt = strlen(c);
	char* temp = new char[tempLenght + oldLengt];
	size_t i = 0;

	for (; i < oldLengt; i++)
	{
		temp[i] = c[i];
	}

	for (size_t j = 0; j < s.getLength(); j++)
	{
		temp[i++] = s.toC_str()[j];
	}

	String newString(temp);
	delete[] temp;
	return newString;
}
