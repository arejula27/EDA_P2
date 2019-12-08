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
# vars
EJEC = practica2

LIB_TEST = ./test/
BUILD = ./build/
DIR_LIBS=./lib

LIB_BOOK = ${DIR_LIBS}/libro
BOOK = ${LIB_BOOK}/libro

LIB_COLEC =${DIR_LIBS}/coleccion
COLEC = ${LIB_COLEC}/coleccion

LIB_PILA = ${DIR_LIBS}/pila
PILATEST = ${LIB_TEST}pilaMain

#---------------------------------------------------------
# para compilación y enlazado ("linkado")
CPPFLAGS= -I. -I${LIB_BOOK} -I${LIB_COLEC} -I${LIB_PILA} -std=c++11    #opciones compilación
TESTFLAGS = -I.  -I${LIB_PILA} -std=c++11 -stdlib=libc++ -lgtest  -lgtest_main -pthread
#---------------------------------------------------------
${EJEC}: ${EJEC}.o ${BOOK}.o 
	${CC} ${EJEC}.o ${BOOK}.o  -o ${BUILD}${EJEC} ${CPPFLAGS} 
#---------------------------------------------------------
pilatest: ${PILATEST}.cpp
	${CC}  ${PILATEST}.cpp ${TESTFLAGS}  -o ${BUILD}pilaTest
#---------------------------------------------------------
${EJEC}.o: ${EJEC}.cpp
	$(CC) ${EJEC}.cpp -c ${CPPFLAGS} 
#---------------------------------------------------------
${BOOK}.o: ${BOOK}.cpp
	$(CC) -c ${BOOK}.cpp -o ${BOOK}.o ${CPPFLAGS} 
#---------------------------------------------------------
# Cuidado con lo que se pone aquí, que se borra sin preguntar
clean:
	$(RM)  ${EJEC} ${BOOK}.o ${EJEC}.o