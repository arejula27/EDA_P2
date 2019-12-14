#include <iostream>
#include "coleccion.h"

using namespace std;



int main(int argc, char **argv)
{
    coleccion<int,int> c;
    crear(c);
    cout<<"EXISTE? "<<existe(c,2)<<endl;
    return 0;
}