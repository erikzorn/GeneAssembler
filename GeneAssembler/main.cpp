/******************************************************************************************************************
 * Title: 	-240 Final Project
 *
 * Author(s): 	-Erik Zorn & Stanley Sierputowski 
 *
 * Function: 	-Assemble a gene based on an overlap of 20 characters from several 100 character DNA sequences
 *
 * Input: 	-Text file with 'A','C','T',and 'G' sequences of 100 characters in length
 *
 * Output: 	-Text file with a String of 'A','C','T',and 'G's that resembles a Gene
 *		-Gene build progression, # of sequences appended, gene character length, execution time
 ******************************************************************************************************************/

#include <iostream>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <ctime>
#include "GSequence.h"

using namespace std;

int main(int argc, char** argv) {
	int start_s=clock();
	ifstream in_file;
	ofstream out_file;
	char c;
	char a;
	char test[256];
	int loopCount(0);
	char beg[256];
	char end[256];
   
	// Check if correct arguments are entered 
	if (argc != 3) {
		cout << "Usage: " << argv[0] << " <Input file> <outfile>" << endl;
		exit(1);
	}

	in_file.open(argv[1]);
   
	if (in_file.fail()) {
		cout << "Error openning the file " << argv[1] << " \n";
		exit(1);
	}

	out_file.open(argv[2]);

	if (out_file.fail()) {
		cout << "Error openning the file " << argv[2] << " \n";
		exit(1);
	}
	int sequences(0);	// variable to keep track of number of sequences
	while (!in_file.eof()) {
                while(a != 'A' && a != 'C' && a != 'T' && a != 'G') {	// iterates past ID numbers
                        in_file.get(a);
                }
		if(!in_file.eof()) {
                        for(int i=0; i<100; i++) {	// loops over 1 sequence
                                in_file.get(a);
                        }
                }
		sequences++;	// increment count
                in_file.get(a);

	}
	cout<< "SEQ COUNT: " << sequences << endl<< endl;	// prints number of sequences
	in_file.clear();
	in_file.seekg(0, ios::beg);	
	GSequence *seq;
	seq = new GSequence[sequences];
	while (!in_file.eof()) {
		
		while(c != 'A' && c != 'C' && c != 'T' && c != 'G') {
			in_file.get(c);
		}
		test[0] = c;
		if(!in_file.eof()) {
			for(int i=1; i<100; i++) {
				in_file.get(test[i]);	
        		}
		}
		GSequence line(test);
		seq[loopCount] = line;
		loopCount++;
		in_file.get(c);	
		in_file.get(c);
    	}
	
	String genome;
	genome = seq[0]; // fir

	// loop runs until last 20 chars of genome String isnt found in a sequence	
	int smallestIndex(1);
	while(smallestIndex){
		cout << "GENOME LENGTH: " << genome.length() << endl;
		smallestIndex= seq[0].findNext(genome,seq,end,sequences);
		if(smallestIndex==-1){	// if find returns -1 then break loop
                        break;
		}
		// appends substring to end of genome
		seq[0].atoe(genome,seq,end,smallestIndex);
		
	}

	// loop runs until first 20 chars of genome String isnt found in a sequence
	int largestIndex(1);
	while(largestIndex){
		cout << "GENOME LENGTH: " << genome.length() << endl;
		largestIndex = seq[0].findPrev(genome, seq, beg, sequences);
		if(largestIndex==-1){	// if find returns -1 then break loop
                        break;
		}
		// appends substring to beginning of sequence
		seq[0].atob(genome,seq,beg,largestIndex);
	}

	delete [] seq;	// unallocate memory

	out_file << genome << endl;	// write to output file

    	in_file.close();	// close files
    	out_file.close();
	int stop_s=clock();	// record end clock time

	cout << endl << "GENOME ASSEMBLED" << endl;
	cout << "SEQUENCES INPUT: " << sequences << endl;
	cout << "GENOME LENGTH: " << genome.length() << endl;
	cout << "EXECUTION TIME: " << (stop_s-start_s)/double(CLOCKS_PER_SEC)*1000 << " milliseconds" << endl;

    	return (EXIT_SUCCESS);
}
