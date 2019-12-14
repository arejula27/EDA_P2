#include <iostream>
#include "coleccion.h"

using namespace std;



int main(int argc, char **argv)
{
    coleccion<int,int> c;
    crear(c);
    cout<<"EXISTE ? 0: "<<existe(c,2)<<endl;
    cout<<"----------------------------------"<<endl;
    cout<<"INRODUCIR: "<<endl;
    introducir(c,5,5,1);
    cout<<"EXISTE raiz ? 1: "<<existe(c,5)<<endl;

    introducir(c,4,4,1);
    cout<<"INRODUCIR: izq "<<endl;
    cout<<"EXISTE raiz ? 1: "<<existe(c,5)<<endl;
    cout<<"EXISTE izq ? 1: "<<existe(c,4)<<endl;
    cout<<"INRODUCIR: der "<<endl;
    introducir(c,6,6,1);
    cout<<"EXISTE raiz ? 1: "<<existe(c,5)<<endl;
    cout<<"EXISTE izq ? 1: "<<existe(c,4)<<endl;
    cout<<"EXISTE der ? 1: "<<existe(c,6)<<endl;
    introducir(c,10,6,1);
     cout<<"INRODUCIR: der der"<<endl;
    cout<<"EXISTE raiz ? 1: "<<existe(c,5)<<endl;
    cout<<"EXISTE izq ? 1: "<<existe(c,4)<<endl;
    cout<<"EXISTE der ? 1: "<<existe(c,6)<<endl;
     cout<<"EXISTE der ? 1: "<<existe(c,10)<<endl;
    introducir(c,0,6,1);
    introducir(c,-8,6,1);
     cout<<"INRODUCIR: der der"<<endl;
    cout<<"EXISTE raiz ? 1: "<<existe(c,5)<<endl;
    cout<<"EXISTE izq ? 1: "<<existe(c,4)<<endl;
    cout<<"EXISTE der ? 1: "<<existe(c,6)<<endl;
    cout<<"EXISTE der ? 1: "<<existe(c,10)<<endl;
    cout<<"EXISTE der ? 0: "<<existe(c,0)<<endl;
    cout<<"EXISTE der ? 0: "<<existe(c,-8)<<endl;
    
    return 0;
}