CC=gcc
CFLAGS=-I.
DEPS = SimpleVector2D.h SimpleVector3D.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

cpp_math_lib: SimpleVector2D.o 
	gcc -o cpp_math_lib SimpleVector2D.o SimpleVector3D.o -I.
