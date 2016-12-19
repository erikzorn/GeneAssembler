# GeneAssembler
A Makefile is included. To compile, issue the “make” command. Alternatively, you can manually compile the program by issuing the following command: “g++ *.cpp -a assemble”

The folder of .txt files contains files labeled "#bp_seq.txt" that are used as input and also contain "#Gene.txt" files which contain what the output should be when the program is run. To check the correctness of the file output by the system, run the diff command. (diff gene_file.txt new_file.txt). This will output the nuances between the two files. If there is no output then the files are identical.
