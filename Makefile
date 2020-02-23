CC = gcc
CFLAGS =`pkg-config gtk+-2.0 --cflags` `pkg-config gtk+-2.0 --libs`
SRC = Proyecto.c Arbol.o Arbol.h
OBJ = Proyecto.o Arbol.o


#Reglas explicitas

all: $(OBJ)
	$(CC) $(CFLAGS) -o Proyecto $(OBJ) `pkg-config gtk+-2.0 --cflags` `pkg-config gtk+-2.0 --libs`
clean:
	$(RM) $(OBJ) main

#Reglas implicitas
Arbol.o: Arbol.c Arbol.h
Proyecto.o: Proyecto.c Arbol.c Arbol.h
