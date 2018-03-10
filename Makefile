CC = g++
CFLAGS = -g

.PHONY: clean

all: rayitres


rayitres: interfaz.o main.o
	$(CC) $(CFLAGS) -o rayitres main.o interfaz.o

%.o: %.cpp
	$(CC) $(CFLAGS) -c $<

clean:
$(RM) *.o
