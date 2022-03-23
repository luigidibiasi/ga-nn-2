
gann: gaNN.o entity.o

	gcc -fopenmp entity.o gaNN.o -o a.out

entity.o:
	gcc -fopenmp -c entity.c
gaNN.o:
	gcc -fopenmp  -c gaNN.c

clean:
	rm *.o
	rm a.out
