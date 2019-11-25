/************************************************
 Autores:
 Íñigo Aréjula Aísa 785370
 Marcos Hernando Ibáñez 778053

 
 
*************************************************/

#ifndef LIBRO_H
#define LIBRO_H
#include <cstring>
#include <iostream>
#include "libro.h"

using namespace std;


struct libro;

//PRE:-
//POS: devuelve un libro inicializado con los parametros introducidos
libro crearLib(string titulo, string autor, int agno);

//PRE: -
//POS: titulo(lib)= lib.titulo
string titulo (libro lib);

//PRE: -
//POS: autor(lib)= lib.autor
string autor (libro lib);

//PRE: -
//POS: agno(lib)= lib.agno
int agno (libro lib);

//PRE: -
//POS: info= "titulo --- autor --- año"
void infoLibro(libro lib, string &info);

struct libro{
    friend libro crearLib(string titulo, string autor, int agno);
    friend string titulo(libro lib);
    friend string autor(libro lib);
    friend int agno(libro lib);
    friend void infoLibro(libro lib, string &info);

private:
    string titulo;
    string autor;
    int agno;
        
};

#endif