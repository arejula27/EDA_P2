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
//POS: Devuelve el titulo del libro
string titulo(libro lib)
{

    return lib.titulo;
}

//PRE: -
//POS: Devuelve el autor del libro
string autor(libro lib)
{
    return lib.autor;
}

//PRE: -
//POS: Devuelve el año del libro
int agno(libro lib)
{
    return lib.agno;
}

//PRE: -
//POS: info almacena la cadena "titulo --- autor --- año"
//     correspondiente al libro
void infoLibro(libro lib, string &info){

    
    info = lib.titulo+" --- "+lib.autor+" --- "+to_string(lib.agno);
   
}
