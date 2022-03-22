OBJS = mainVector.o vectorAux.o
CC = gcc
CTAGS = -c -g -DDEBUG

vectores : $(OBJS)
	$(CC) $(OBJS) -o vectores

mainVector.o : mainVector.c vectorAux.h  
	$(CC) $(CTAGS) mainVector.c

vectorAux.o : vectorAux.c vectorAux.h
	$(CC) $(CTAGS) vectorAux.c
