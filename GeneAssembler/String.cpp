/*
 * File: String.cpp
 * Author: Erik Zorn
 *
 * Function: Contains methods to create, manipulate, and access elememts of char arrays
 * 
 * Created on: Tuesday, October 11, 2016
 *
 */

#include <iostream>
#include <cstdlib>
#include "String.h"

using namespace std;

// Constructor: Initializes a String object with length of 0  
String::String(){
	_length = 0;
	data = new char[_length];
}
// Parameterized Constructor: Takes in char array. Allocates memory to string and assigns values of parameter 
String::String(char str[]) {
	_length = getCharArraySize(str);	// get size of parameter
	data = new char[_length]; 	 
	for (int i=0; i<_length; i++) {	// create blank array
                data[i] = str[i];
        }	
}
String::String(String &copy) {
	_length = copy.length();        // get size of parameter
        data = new char[_length];
	for (int i=0; i<_length; i++) { // create blank array
                data[i] = copy[i];
        }
}
// Unallocates the memory of data
String::~String() {
	delete[] data;
}

// Print String object
void String::print() {
	if(_length==0) { 		// if empty array, print NULL
		cout << "NULL" << endl;
	}
	else {				// else print populated indices
		for(int i=0; i<_length ; i++) {
			cout << data[i];
		}
		cout << endl;
	}
}

// return length of String
int String::length() {
	return _length;
}

// Private function to find size of array
int String::getCharArraySize(char arr[]) {
	int size(0);
	while(arr[size] != '\0') {	// iterate through array until teminal character is reached
                size++;
        }
	return size;			// return loop count
}

// Returns true if the String is empty
bool String::empty() {			
	if (_length == 0){
		return true;
	}
	return false;
}

// Clears String and sets _length to 0
void String::clear() {
	//for (int i=0; i<_length; i++) {
	//	data[i]=' ';
	//}
	_length = 0;
}

// Determines whether String contains a substring within and returns the beginning
// index of substring within string
int String::find(char substr[], int startIndex) {
	//cout << "findFunc: " << substr << endl;
	bool found = false;		// Boolean to see if substring is found
	int _lengthSub = getCharArraySize(substr);
	//cout << "lengthSub:  " << _lengthSub << "  _length:  " << _length<<endl;	
	for(int i=startIndex; i<_length; i++) {	// Loops until _length of String is reached
		// When index is found that contains char that matched first char in substring
		// it goes on to check next characters to determine equality. If the substring 
		// does not match then next char of the main String is assessed
		if(data[i] == substr[0]) {	
			for(int j=0; j<_lengthSub;j++) {
				if(data[j+i] == substr[j]) {
					found = true;
					
				}
				else {
					found = false;
					j = _lengthSub;
				}	
			}			
		}
		// If a match is found then exit loop by returning index of main loop that first char 
		// match was found at
		if (found) {
			return i;
		}
	}
	// If match wasnt found, return -1
	return -1;
}

// Return what character is at a given index in a String Object. Overload []
char String::operator[](int index) const {
	if(index>=_length) {
		cout << "Error, index out of bounds" << endl;
		exit(0);
	}
	return data[index];
}

// Checks if strings are equal
bool String::operator==(String &two) {
	int _lengthTwo = two.length();
	if(_length == _lengthTwo) {	// If lengths are equal, check if characters are equal
		for(int i=0;i<_length;i++) {
		 	if(data[i] != two[i]) {	// Compares indices
				return false;		// return false if contradiction is found
			}
		}
		return true;		// If no falsity was found, return true
	}
	return false;	// If lengths are not equal, return false
}

// Overloads = operator to set a char[] equal to another char[]
String String::operator=(const String &two) {
     	delete[] data;
	 _length = two._length;
        data = new char[_length];
        for(int i=0;i<_length;i++) {
                data[i] = two[i];
        }
	return *this;
}

// Add content of Strings together using + operator
String String::operator+(String &two) {

        int _lengthTwo = two.length();
        int combinedLength = _length + _lengthTwo;      // finds length of strings combined
        //char *temp = new char[combinedLength];          // create temp array
	char temp[combinedLength];
        for(int i=0; i<_length; i++) {                  // copies first string to array
                temp[i] = data[i];
        }
        for(int i=0; i<_lengthTwo;i++) {            // copies second string to second half of array
                temp[i+_length] = two[i];
        }
	

        String test(temp);
	test._length=combinedLength;
	//cout << "combinded length " << test._length << endl;
        return test;
}
ostream& operator<<(ostream& os,const String& str)
{	
	int length = str._length;
	if(length==0) {                // if empty array, print NULL
                os << "NULL" << endl;
        }
        else {                          // else print populated indices
                for(int i=0; i<length ; i++) {
                        os << str[i];
                }
        }
    return os;
}
