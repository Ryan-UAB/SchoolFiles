Vigenere: main.o vigenere.o
	g++ -std=c++14 main.o vigenere.o -o vigenere

main.o: main.cpp vigenere.h
	g++ -std=c++14 -c main.cpp

vigenere.o: vigenere.cpp vigenere.h
	g++ -std=c++14 -c vigenere.cpp

run: vigenere
	./vigenere

clean: 
	rm -f *.o vigenere