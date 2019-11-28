/************************************************
 Autores:
 Íñigo Aréjula Aísa 785370
 Marcos Hernando Ibáñez 778053

 
 
*************************************************/ 


#include <iostream>
#include <fstream>
#include <cstring>
#include "coleccion.h"
#include "libro.h"


using namespace std;
 
//PRE: f1 y f2 son flujos de entrada y salida. c es un tipo colección.
//POST: Se ha añadido una línea en salida.txt resultado de una inserción.
void AL(ifstream &f1, ofstream &f2, coleccion<libro, string> &c)
{


    string key, title, author, year, num;
    int agno, rep;
    libro book;

    //Obtención de datos
    getline(f1, key);
    getline(f1, title);
    getline(f1, author);
    getline(f1, year);
    agno = stoi(year);
    getline(f1, num);
    rep = stoi(num);
    book = crearLib(title, author, agno);   //Se crea el libro correspondiente a los datos obtenidos

    if (introducir(c, key, book, rep)) 
    {
        //Se ha introducido con éxito
        string info;
        infoLibro(book, info);  
        //Se escribe la información del libro
        f2 << "INSERCION: " << key << ":::"
           << "<* " << info << " (" << rep << ")*>\n";
    }
    else
    {   //No se ha podido introducir el libro
        string info;
        infoLibro(book, info);
        //Se presenta la información del libro
        f2 << "insercion CANCELADA: " << key << ":::"
           << "<* " << info << " (" << rep << ")*>\n";
    }
}

//PRE: f1 y f2 son flujos de entrada y salida. c es un tipo colección
//POST: Se ha añadido una línea en salida.txt resultado de añadir un ejemplar a la colección
void AE(ifstream &f1, ofstream &f2, coleccion<libro, string> &c)
{
    
    string key;
    getline(f1, key);
    
    if (existe(c, key))
    {
        //Si el libro está en la colección se añade una repetición
        agnadirRep(c, key);
        int num;
        obtenerNumero(c, key, num);
        //Se escribe en salida.txt el resultado
        f2 << "ejemplar GUARDADO: " << key << " --- " << to_string(num) << "\n";
        
    }
    else
    {
        //El libro no está en la colección
        f2 << "ejemplar RECHAZADO: " << key << "\n";
    }
}

//PRE: f1 y f2 son flujos de entrada y salida. c es un tipo colección
//POST: Se ha añadido una línea en salida.txt resultado de eliminar un ejemplar
void EE(ifstream &f1, ofstream &f2, coleccion<libro, string> &c)
{

    string key;
    getline(f1, key);
    
    if(existe(c,key)){
        //El libro está en la en la colección
        int num;
        obtenerNumero(c, key, num);
        //Se elimina una repetición del libro y se escribe en salida.txt
        quitarRep(c, key);
        
        
        f2 << "ejemplar ELIMINADO: " << key << " --- " << to_string(num-1) << "\n";
    }
    else
    {
        //El libro no está en la colección
        f2 << "eliminacion INECESARIA: " << key << "\n";
    }
    
    
}

//PRE: f1 y f2 son flujos de entrada y salida. c es un tipo colección
//POST: Se ha añadido una línea en salida.txt resultado de eliminar un libro de la colección
void EL(ifstream &f1, ofstream &f2, coleccion<libro, string> &c)
{

    string key;
    getline(f1, key);

    if(existe(c,key)){
        //El libro está en la colección
        //Se elimina de la colección y se escribe en salida.txt
        eliminar(c, key);
        f2 << "libro DESCATALOGADO: " << key << "\n";
    }
    else
    {   //El libro no está en la colección
        f2 << "inecesario RETIRAR: " << key << "\n";
    }
    
    
}

//PRE: f1 y f2 son flujos de entrada y salida. c es un tipo colección
//POST: Se ha añadido una línea en salida.txt con información del libro
void LD(ifstream &f1, ofstream &f2, coleccion<libro, string> &c)
{
    
    string key;
    getline(f1, key);
    libro lib;
    if(obtenerDato(c,key,lib)){
        //El libro está en colección 
        //Se obtienen los datos del libro
        string info;
        infoLibro(lib, info);
        int rep;
        obtenerNumero(c, key, rep);
        //Se escribe en salida.txt el resultado
        f2 << "ENCONTRADO: " << key << ":::"
           << "<*" << info << "(" << rep << ")*>\n";
    }
    else{
        //El libro no está en la colección
        f2<< "libro DESCONOCIDO: " << key << "\n";
    }    
}

//PRE: f1 y f2 son flujos de entrada y salida. c es un tipo colección
//Se ha añadido una línea en salida.txt con información de la colección 
void LT(ifstream &f1, ofstream &f2, coleccion<libro, string> &c)
{
    
    //Obtención de datos
    int distintos;
    numClaves(c,distintos);
    int totales;
    numCardinal(c,totales);
    //Se escribe la información de la colección
    f2<< "LISTADO: \n" << "TOTAL LIBROS: " << distintos << " ..... ";
    f2<< "TOTAL EJEMPLARES: " << totales << "\n";
    libro lib;
    string info;
    iniciarIterador(c);
    //Bucle para escribir cada la información de cada libro
    while( siguienteDato(c,lib) ){
        
        
         infoLibro(lib, info);
         
         string keyBook ;
         
         siguienteClave(c,keyBook);
         

         int repBook ;
         obtenerNumero(c,keyBook,repBook);
        
        f2<< keyBook << ":::<* " << info << " (" << repBook << ")*>\n";
        avanza(c);
    }
}

//PRE: f1 y f2 son flujos de entrada y salida. c es un tipo colección
//POST: Ejecuta la orden correpondiente
void exeOrd(ifstream &f1, ofstream &f2, coleccion<libro, string> &c)
{

    string orden;

    while (getline(f1, orden, '\n')) //Bucle para identificar la orden a ejecutar
    {
        
        
        if (orden == "AL")
        {
            AL(f1,f2,c);
        }
        else if (orden == "AE")
        {

            AE(f1, f2, c);
        }
        else if (orden == "EE")
        {
            EE(f1, f2, c);
        }
        else if (orden == "EL")
        {
            EL(f1, f2, c);
        }
        else if (orden == "LD")
        {
            LD(f1,f2,c);
        }
        else if (orden == "LT")
        {
            LT(f1,f2,c);
        }
      
        
        
    }
}
int main()
{

    coleccion<libro,string> colec;
    crear(colec);
    ifstream f1("entrada.txt"); //Asociamos el flujo de entrada
    
    if(f1.is_open()){
        ofstream f2("salida.txt");
        if(f2.is_open()){
            exeOrd(f1, f2, colec); //Se lee la orden introducida desde el fichero de entrada
            f2.close();
        }
        else{
            cerr << "Fichero salida.txt no encontrado" << endl;
        }
        f1.close();
    }
    else{
        cerr << "Fichero entrada.txt no encontrado" << endl;
    }
    
    




    return 0;
}
