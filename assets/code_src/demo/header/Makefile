CFLAGS = -O
CC = g++
NumTest:main.o add.o
	$(CC) $(CFLAGS) -o NumTest main.o add.o
main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp
add.o: add.cpp
	$(CC) $(CFLAGS) -c add.cpp
clean: 
	rm -f core *.o
