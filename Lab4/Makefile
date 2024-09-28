deque: main.o deque.o
	g++ main.o deque.o -o deque

main.o: main.cpp deque.h
	g++ -c main.cpp

deque.o: deque.cpp deque.h
	g++ -c deque.cpp

run: deque
	./deque

clean: 
	rm -f *.o deque