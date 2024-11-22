.phony: clean

SRC=6809.c main.c monitor.c simple.c wpc.c
OBJ=6809.o main.o monitor.o simple.o wpc.o

LIBS=-lc

CC=cc
CXFLAGS=-g

LD=cc

%.o: %.c
	$(CC) $(CXFLAGS) -c -o $@ $<

exec09: $(OBJ)
	$(LD) $(LDFLAGS) -o $@ $^

clean:
	rm -f *.o exec09
