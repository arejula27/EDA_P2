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
 
//AL procesa los datos referentes a un libro que introduce en la coleccion
// y añade una linea en salida.txt con el resultado

//El coste de AL viene dado por el coste de la funcion introducir del TAD coleccion

void AL(ifstream &f1, ofstream &f2, coleccion<string,libro > &c)
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
    
    int varCla1,varCla2;
    numClaves(c,varCla1);
    bool intr =introducir(c,key,book,rep);
    numClaves(c,varCla2);

    if (intr && varCla1 < varCla2) 
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

//AL procesa los datos referentes a un libro de la coleccion al 
//cual se añade un ejemplar y añade una linea en salida.txt con el resultado

//El coste de AE viene dado por el coste de la funcion agnadirRep del TAD coleccion

void AE(ifstream &f1, ofstream &f2, coleccion<string, libro> &c)
{
    
    string key;
    getline(f1, key);
   // cout<<key<<endl;
    int varRep1,varRep2;
    numCardinal(c,varRep1);
    agnadirRep(c, key);
    numCardinal(c,varRep2);
    //cout << "Antes: " << varRep1<<"ahora: "<<varRep2<<endl;
    
    
    if (varRep1<varRep2)
    {
        //Si el libro está en la colección se añade una repetición
        int num;
        libro book;
        obtenerInfo(c, key,book, num);
        //Se escribe en salida.txt el resultado
        f2 << "ejemplar GUARDADO: " << key << " --- " << to_string(num) << "\n";
        
    }
    else
    {
        //El libro no está en la colección
        f2 << "ejemplar RECHAZADO: " << key << "\n";
    }
}

//EL procesa los datos referentes al libro de la coleccion del cual 
//se eliminará un ejemplar y añade una linea en salida.txt con el resultado 


//El coste de EE viene dado por el coste de la funcion quitarRep del TAD coleccion

void EE(ifstream &f1, ofstream &f2, coleccion<string, libro> &c)
{

    string key;
    getline(f1, key);

    int varRep1,varRep2;
    numCardinal(c,varRep1);
    //Se elimina una repetición del libro y se escribe en salida.txt
    quitarRep(c, key);
    numCardinal(c,varRep2);
    
    
    if (varRep1>varRep2){
        //El libro está en la en la colección
        int num;
        libro book;
        obtenerInfo(c, key,book, num);
        
        
        
        f2 << "ejemplar ELIMINADO: " << key << " --- " << to_string(num) << "\n";
    }
    else
    {
        //El libro no está en la colección
        f2 << "eliminacion INNECESARIA: " << key << "\n";
    }
    
    
}


//EL procesa los datos referentes al libro de la coleccion que se 
//eliminará y añade una linea en salida.txt con el resultado 

//El coste de EL viene dado por el coste de la funcion eliminar del TAD coleccion
void EL(ifstream &f1, ofstream &f2, coleccion<string, libro> &c)
{

    string key;
    getline(f1, key);

    int varCla1,varCla2;
    numClaves(c,varCla1);
    eliminar(c, key);
    numClaves(c,varCla2);

    if ( varCla1 > varCla2) 
    {

  
        //El libro está en la colección
        //Se elimina de la colección y se escribe en salida.txt
        
        f2 << "libro DESCATALOGADO: " << key << "\n";
    }
    else
    {   //El libro no está en la colección
        f2 << "innecesario RETIRAR: " << key << "\n";
    }
    
    
}


//LD lee la clave de un libro y lo busca en la coleccion.
//Añade una linea en salida.txt con los datos del libro si 
//lo ha encontrado, o indicando lo contrario.

//El coste de LD viene dado por el coste de la funcion obtenerInfo del TAD coleccion

void LD(ifstream &f1, ofstream &f2, coleccion<string, libro> &c)
{
    
    string key;
    getline(f1, key);
    libro lib;
      int rep;
    if(obtenerInfo(c,key,lib,rep)){
        //El libro está en colección 
        //Se obtienen los datos del libro
        string info;
        infoLibro(lib, info);
        //Se escribe en salida.txt el resultado
        f2 << "ENCONTRADO: " << key << ":::"
           << "<* " << info << " (" << rep << ")*>\n";
    }
    else{
        //El libro no está en la colección
        f2<< "libro DESCONOCIDO: " << key << "\n";
    }    
}



//LT añade una linea en salida.txt con los datos de cada 
// libro existente en la colección

//El coste de LT viene dado por el bucle cuya guarda es existeSiguiente(c).
//El coste de LT será n*coste(existeSiguiente), siendo n el num. elem. en la coleccion

void LT(ifstream &f1, ofstream &f2, coleccion<string, libro> &c)
{
    
    //Obtención de datos
    int distintos;
    numClaves(c,distintos);
    int totales;
    numCardinal(c,totales);
    //Se escribe la información de la colección
    f2<< "LISTADO: \n" << "TOTAL LIBROS: " << distintos << " ..... ";
    f2<< "TOTAL EJEMPLARES: " << totales << "\n";
    libro book;
    string info;
    string keyBook ;
    int repBook ;
    iniciarIterador(c);
    //Bucle para escribir cada la información de cada libro
    while( existeSiguiente(c) ){

        
         siguienteNodo(c,keyBook,book,repBook);
         infoLibro(book, info);
         
        f2<< keyBook << ":::<* " << info << " (" << repBook << ")*>\n";
        avanza(c);
    }
}


//Dados dos flujos de fichero (entrada y salida) ejecuta la orden
//indicada en el fichero de entrada sobre la coleccion c y escribe  
//el resultado correspondiente en el fichero de salida
void exeOrd(ifstream &f1, ofstream &f2, coleccion<string, libro> &c)
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

    coleccion<string,libro> colec;
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
