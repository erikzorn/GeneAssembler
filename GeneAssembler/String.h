/***************************************************************************
 * File: String.h
 * Author: Erik Zorn
 * Function: Helper file for string.cpp                                                                        
 ***************************************************************************/

using namespace std;

class String 
{	
	friend ostream& operator<<(ostream& os, const String& str);
	private:
		
		int _length;
		char *data;
		int getCharArraySize(char arr[]);
    
	//protected:
	//	int getCharArraySize(char arr[]);
	public:
	
		String();
		String(char str[]);
		String(String &copy);
		virtual ~String(); //Destructor should delete your data pointer.
    
		void print();
		int length();
		void clear(); 
		bool empty();
		int find(char substr[], int startIndex);
		
		bool operator==(String& two); //Should replace your equal() method. 
	//	bool operator+(String& two);
		String operator+(String& two); //Should replace your add() method. Should append the char* in two to the object doing the calling. Return true if you were able to add the two together, false if not. 
		String operator=(const String &); //Should assign two to the calling object. 
		char operator[](int index) const; //Should replace your at() method. 
		
		
		
};
