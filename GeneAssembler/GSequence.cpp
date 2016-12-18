/*****************************************************************************************************
 * Title: 	-GSequence Object
 *
 * Author(s): 	-Erik Zorn & Stanley Sierputowski 
 *
 * Function: 	-Object resembles a String of ACTGs, finds mathing sequences, and appends sequences
 *		 to begginning and end
 *****************************************************************************************************/
#include <iostream>
#include <cstdlib>
#include "GSequence.h"
using namespace std;

		GSequence::GSequence() : String(){
			used=false;
		}
	
                GSequence::GSequence(char str[]) : String(str) {
			used = false;	
		}
		GSequence::GSequence(const String& copy){
			
		}
                GSequence:: ~GSequence() {

		}
		int GSequence::findPrev(String& genome,GSequence seq[],char beg[], int loopCount) {
			for(int i=0; i<20;i++) {
                                beg[i] = genome[i];
                        }
			beg[20]='\0';
			genome.print();			
			int index;
			int largestIndex(-1);	
			for(int i=1;i<loopCount;i++) {
				if(!seq[i].used) {
					index = seq[i].find(beg,0);
					if(index>=0) {
						seq[i].used = true;
						if(largestIndex==-1) 
							largestIndex=i;
						else if(seq[largestIndex].find(beg,0)<index)
							largestIndex=i;
					}
				}
			}
			return largestIndex;

		}
		int GSequence::findNext(String& genome,GSequence seq[],char end[], int loopCount) {
      			bool found = false; 
			for(int i=0; i<20;i++) {
                		end[i] = genome[i+(genome.length()-20)];
			}
			end[20] = '\0';
			genome.print();
			int index;
        		int smallestIndex(-1);
        		for(int i=1;i<loopCount;i++) {
				if(!seq[i].used) {
                        		index = seq[i].find(end,0);
					if(index >=0){			//All seq that have match
						found=true;
						seq[i].used=true;	//Sets seq to used
                                		if(smallestIndex==-1)
                                        		smallestIndex=i;
                               	 		else if(seq[smallestIndex].find(end,0)>index)	//Finds smallest overlap
                                        		smallestIndex=i;
           	             		}
                		}    	
			}
     
			return smallestIndex;
			
		}
		void GSequence:: atoe(String& genome,GSequence seq[],char end[], int index) {
			char temp[256];
  			int counter(0);
        		for(int i=80-seq[index].find(end,0); i>0;i--) {
              			temp[counter] = seq[index][100-i];
                		counter++;
        		}
       			temp[counter]='\0'; 
        		cout << "Add this to end: ";

        		GSequence addition(temp);
        		addition.print();
        		genome = (genome+addition);
        		seq[index].used=true;
		}
		void GSequence::atob(String& genome,GSequence seq[],char beg[], int index) {
			char temp[256];
			int counter(0);
			for(int i=0;i< seq[index].find(beg,0);i++){
				temp[i]=seq[index][i];
				counter++;
			}
			temp[counter]='\0';
			cout << "Add this to beg: ";
			GSequence addition(temp);
			addition.print();
			genome = (addition+genome);
			seq[index].used=true;
		}



