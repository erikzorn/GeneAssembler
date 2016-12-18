
assemble: main.o String.o GSequence.o
	g++ main.o String.o GSequence.o -o assemble

main.o: main.cpp
	g++ -c main.cpp

String.o: String.cpp String.h
	g++ -c String.cpp

GSequence.o: GSequence.h GSequence.cpp
	g++ -c GSequence.cpp

clean:
	rm *.o assemble


