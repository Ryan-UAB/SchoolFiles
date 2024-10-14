event: main.o event.o
	g++ -std=c++11 main.o event.o -o event

main.o: main.cpp event.h
	g++ -std=c++11 -c main.cpp

event.o: event.cpp event.h
	g++ -std=c++11 -c event.cpp

run: event
	./event

clean: 
	rm -f *.o event