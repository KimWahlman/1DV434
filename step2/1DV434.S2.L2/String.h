/**********************************************************************/
// File:	String.h
// Summary: The definition file for the class String
// Version:	Version 1.0 - 2017-04-18
// Owner:	Kim Wahlman
// -------------------------------------------
// Log:	2017-04-18	Created and implemented the file. Kim,
/**********************************************************************/
#ifndef STRING_H
#define STRING_H

#include <ostream>
#include <istream>
#include <string>
#include <iomanip>

class String
{
public:
	String();
	String(const char*);

	inline String(const String& s) : _strLen(0)
	{
		size_t tempLenght = 1 + s.getLength();
		_strPtr = new char[tempLenght];
		_strLen = tempLenght;
		std::memcpy(_strPtr, s.toC_str(), tempLenght);
	}

	~String();

	inline friend std::istream& operator>>(std::istream& is, String& s)
	{
		char temp[100];
		is >> std::setw(100) >> temp;
		s = temp;
		return is;
	}

	inline friend std::ostream& operator<<(std::ostream& os, String& s)
	{
		os << s.toC_str();
		return os;
	}

	const String operator+(const char* s) const;
	
	// Will add _strPtr together with s and return the result.
	const String operator+(const String& s) const;

	// Friends variant, without the keyword 'friend' 
	// I wasn't allowed to have more than a single argument.
	// This function will take a char and String and add
	// them together and return the result.
	// For example: str2 = "Goodbye " + str3;
	friend	const String operator+(const char* c, const String& s);
	
	String& operator+=(const String& s);

	String& operator=(const String& s);
	String& operator=(const char* s);	

	// strcmp will compare these two c-strings.
	// and return if they match or not (true/false).
	inline bool operator==(const String &s) const
	{
		return strcmp(_strPtr, s.toC_str()) == 0;
	}

	inline const char* toC_str() const
	{
		return _strPtr;
	}
	
	// If the _strPtr target is to small, we need to resize it!
	void resize(int size);

	// Small functions like this one can be inlined.
	// All it does is returning _strLen.
	inline int getLength() const
	{
		return _strLen;
	}
private:
	char* _strPtr;
	int _strLen;
};
#endif
