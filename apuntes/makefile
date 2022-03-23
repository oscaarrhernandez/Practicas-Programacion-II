# Partimos del siguiente proyecto:
# Proyecto:
#          mainVector.c
#          vectorAux.c
#          vectorAux.h
#

OBJS = mainVector.o vectorAux.o
CC = gcc
CTAGS = -c -g -DDEBUG

vectores : $(OBJS)
  $(CC) $(OBJS) -o vectores

mainVector.o : mainVector.c vectorAux.h  
	$(CC) $(CTAGS) mainVector.c

vectorAux.o : vectorAux.c vectorAux.h
	$(CC) $(CTAGS) vectorAux.c

clean:
	rm *.o

#
#  OBJS hace referencia a los objetos de los archivos del proyecto. Recordatorio: Los .o se forman al unir los .h y los .c, 
#    por tanto tiene que haber el mismo numero de .o que de .c
#  CC hace referencia al compilador, en este caso gcc
#  CTAGS hace referencia a las distintas opciones que se definen en el makefile, en este caso -c para compilar -g para información de la depuración
#    y -DDEBUG para mostrar los ddebugs que se hayan escrito en el código
#  vectores es el ejecutable que queremos general, para ello se precisa la existencia de los ficheros objeto OBJS. La siguiente linea tiene este formato:
#    <TAB> Compilador Objetos -o (output) vectores(nombre del objetivo actual, también puedes poner $@ en vez del nombre)
#  Creamos los .o que necesitamos. El .o está formado por los .c y .h necesarios para cada parte, por ejemplo para el mainVector.o necesitamos el mainVector.c
#    y vectorAux.h. <TAB> Compilador Opciones nombredelCqueEjecutamos
#  Función clean, no es necesaria, se usa para eliminar los .o creados, debes de ser tu al ejecutar el make el que lo especifique: make clean
#
