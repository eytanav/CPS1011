CC = gcc
CFLAGS = -Wall
OBJ = main.o 4-exercise-1.o 4-exercise-2.o 4-exercise-3.o 4-exercise-4.o 4-exercise-5.o 4-exercise-6.o

all: program

program: $(OBJ)
	$(CC) $(CFLAGS) -o program $(OBJ) -lm

# Compilation rules for each .c file
main.o: main.c
	$(CC) $(CFLAGS) -c main.c

4-exercise-1.o: 4-exercise-1.c 4-exercise-1.h
	$(CC) $(CFLAGS) -c 4-exercise-1.c

4-exercise-2.o: 4-exercise-2.c 4-exercise-2.h
	$(CC) $(CFLAGS) -c 4-exercise-2.c

4-exercise-3.o: 4-exercise-3.c 4-exercise-3.h
	$(CC) $(CFLAGS) -c 4-exercise-3.c

4-exercise-4.o: 4-exercise-4.c 4-exercise-4.h
	$(CC) $(CFLAGS) -c 4-exercise-4.c

4-exercise-5.o: 4-exercise-5.c 4-exercise-5.h
	$(CC) $(CFLAGS) -c 4-exercise-5.c

4-exercise-6.o: 4-exercise-6.c 4-exercise-6.h
	$(CC) $(CFLAGS) -c 4-exercise-6.c

# Clean up object files and executable
clean:
	rm -f *.o program
