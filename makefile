#***************************************************************************
# File:   Makefile
# Author: Íñigo Aréjula
#		  Marcos Hernando 
# Date:   March 27, 2019
# Coms:   Ejemplo de Makefile
#         Ejecutar 'make' para compilar (o 'make -f Makefile')
#         Ejecutar 'make' clean para limpiar (borrar lo que genere)
#***************************************************************************

#---------------------------------------------------------
# macros
RM = /bin/rm -f  # para limpiar
CC = g++        # para compilar

#---------------------------------------------------------
auto:
	$(RM) practica1 libro.o practica1.o
	$ make practica1



#---------------------------------------------------------
practica1: practica1.o libro.o
	
	$(CC)practica1.o libro.o -o practica1 -std=c++11
#---------------------------------------------------------
libro.o: libro.cc
	$(CC) libro.cc -c -std=c++11

#---------------------------------------------------------
practica1.o: practica1.cpp
	$(CC)practica1.cpp -c -std=c++11
#---------------------------------------------------------


# Cuidado con lo que se pone aquí, que se borra sin preguntar
clean:
	$(RM) practica1 libro.o practica1.o