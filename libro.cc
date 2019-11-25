/************************************************
 Autores:
 Íñigo Aréjula Aísa 785370
 Marcos Hernando Ibáñez 778053

 
 
*************************************************/

#include "libro.h"

using namespace std;


//PRE:-
//POS: devuelve un libro inicializado con los parametros introducidos
libro crearLib(string titulo, string autor, int agno){

    libro book;
    book.titulo=titulo;
    book.autor=autor;
    book.agno=agno;
    return book;
}

//PRE: -
//POS: titulo(lib)= lib.titulo
string titulo(libro lib)
{

    return lib.titulo;
}

//PRE: -
//POS: autor(lib)= lib.autor
string autor(libro lib)
{
    return lib.autor;
}

//PRE: -
//POS: agno(lib)= lib.agno
int agno(libro lib)
{
    return lib.agno;
}

//PRE: -
//POS: info= "titulo --- autor --- año"
void infoLibro(libro lib, string &info){

    
    info = lib.titulo+" --- "+lib.autor+" --- "+to_string(lib.agno);
   
}
