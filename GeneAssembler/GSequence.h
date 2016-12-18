/*****************************************************************************************************
 * Title: 	-GSequence Helper
 *
 * Author(s): 	-Erik Zorn & Stanley Sierputowski 
 *
 * Function: 	-Inherits from String class resembles a String of ACTGs, 
 *		 finds mathing sequences, and appends sequences to begginning and end
 *****************************************************************************************************/
#include "String.h"
class GSequence: public String {
	private:
		

	public:
		bool used;
		GSequence();
		GSequence(char str[]);
		GSequence(const String& copy);
		virtual ~GSequence();
		int findPrev(String& genome, GSequence seq[], char beg[], int loopCount);
		int findNext(String& genome, GSequence seq[], char end[], int loopCount);
		void atoe(String& genome,GSequence seq[],char end[], int index);	
		void atob(String& genome,GSequence seq[],char beg[], int index);
}
;
