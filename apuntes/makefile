OBJS = testord.o metodos.o memoria.o auxi.o
CC = gcc
CTAGS = -O -c -DDEBUG
SOURCES = testord.c metodos.c memoria.c auxi.c
HEADERS = auxi.h metodos.h memoria.h
testord : $(OBJS)
	$(CC) $(OBJS) -o $@
testord.o : testord.c $(HEADERS)
	$(CC) $(CTAGS) testord.c
auxi.o : auxi.h
memoria.o : memoria.h
metodos.o : metodos.h
proyecto.tar : $(SOURCES) $(HEADERS) makefile
	tar -cvf proyecto.tar $^
clean:
	rm *.o


#alias OBJS hace referencia a los objetos de los archivos del proyecto. Recordatorio: ? Los .o vienen de los .c no de los .h
#alias CC hace referencia al compilador en este caso gcc
#alias CTAGS opciones que deseemos, -c es para compilar y -DDEBUG es por si tenemos algun DDEBUG en nuestro codigo
#alias SOURCE hace referencia a los archivos .c que disponemos
#alias HEADERS hace referencia a los archivos .h que disponemos en el proyecto
#testord.exe está formado por los OBJS, en la siguiente linea se realiza un *TAB* y se pone a compilar los objetos disponibles se realiza el -o(output) en el nombre del objetivo actual(eso se realiza con $@), es decir, testord
#las siguientes lineas .o son iguales, tienes que meter en el .o los archivos que sean usados en ese .o, es decir, en memoria.o solo ponemos memoria.h porque solo depende de si misma pero testord depende de testord.c y todos los .h
#para crear un .tar del proyecto tenemos que invocar los sources y los headers y realizar un makefile, la linea de comando que se usa es tar -cvf proyecto.tar  $^(para meter todas las dependencias)
#clean se usa para eliminar los .o, para que se ejecute debes de expecificarla en el make, realizas un rm *.o, es decir eliminar todos los archivos que acaben en .o
