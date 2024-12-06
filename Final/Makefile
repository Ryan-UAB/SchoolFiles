Hamming: main.o hamming.o
	g++ -std=c++14 main.o hamming.o -o hamming

main.o: main.cpp hamming.h
	g++ -std=c++14 -c main.cpp

hamming.o: hamming.cpp hamming.h
	g++ -std=c++14 -c hamming.cpp

run: hamming
	./hamming

clean: 
	rm -f *.o hamming