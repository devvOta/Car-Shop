all: exec

main.o: main.c
	gcc -o main.o -c main.c

car.o: car.c
	gcc -o car.o -c car.c

user.o: user.c
	gcc -o user.o -c user.c

other.o: other.c car.h user.h
	gcc -o other.o -c other.c

exec: main.o car.o user.o other.o
	gcc main.o car.o user.o other.o -o exec

clean:
	rm -f *.o
	rm -f exec
