CC=gcc
CFLAGS = -g -Wall
TARGET = libc
DEPS = ansi_color_codes.h

_OBJ = main.o dump.o lib.o mem.o print.o rand.o types.o
OBJ = $(patsubst %,%,$(_OBJ))

default: all

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $(DEPS) -o $(TARGET) $(OBJ)

main.o: main.c
	$(CC) $(CFLAGS) -Wno-unused-but-set-variable -c main.c

dump.o: dump.c dump.h
	$(CC) $(CFLAGS) -c dump.c

lib.o: lib.c lib.h
	$(CC) $(CFLAGS) -c lib.c

mem.o: mem.c mem.h
	$(CC) $(CFLAGS) -c mem.c

print.o: print.c print.h
	$(CC) $(CFLAGS) -c print.c

rand.o: rand.c rand.h
	$(CC) $(CFLAGS) -c rand.c

types.o: types.c types.h
	$(CC) $(CFLAGS) -c types.c

.PHONY: clean

clean:
	rm -f *.o libc
