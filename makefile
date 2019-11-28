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
EJEC = practica2.cpp
DIR_LIBS=../libreria
LIB_BOOK = ${DIR_LIBS}/libro
BOOK = ${LIB_BOOK}/libro
LIB_COLEC =${DIR_LIBS}/coleccion
COLEC = ${LIB_COLEC}/coleccion
#---------------------------------------------------------
# para compilación y enlazado ("linkado")
CPPFLAGS=-I. -I${LIB_BOOK} -I${LIB_COLEC} -std=c++11    #opciones compilación
#---------------------------------------------------------
${EJEC}: ${EJEC}.o ${BOOK}.o 
	${CC} ${EJEC}.o ${BOOK}.o  -o ${EJEC} ${CPPFLAGS} 
#---------------------------------------------------------
${EJEC}.o: ${EJEC}.cpp
	$(CC) ${EJEC}.cpp -c ${CPPFLAGS} 
#---------------------------------------------------------
${BOOK}.o: ${BOOK}.cpp
	$(CC) ${BOOK}.cpp -c ${CPPFLAGS} 
#---------------------------------------------------------
# Cuidado con lo que se pone aquí, que se borra sin preguntar
clean:
	$(RM)  ${EJEC} ${BOOK}.o ${EJEC}.o