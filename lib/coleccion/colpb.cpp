#include <iostream>
#include "coleccion.h"

using namespace std;



int main(int argc, char **argv)
{
    coleccion<int,int> c;
    crear(c);
    cout << "CREAR E INTRODUCIR" << endl;
    cout<<"----------------------------------"<<endl;
    cout<<"EXISTE ? 0: "<<existe(c,2)<<endl;
    cout<<"INRODUCIR: "<<endl;
    introducir(c,5,5,1);
    cout<<"EXISTE raiz ? 1: "<<existe(c,5)<<endl;
    int num;
    numClaves(c,num);
    cout<<"CLAVES ?1: "<<num<<endl;
    numCardinal(c,num);
    cout<<"REPS ?1: "<<num<<endl;

    introducir(c,4,4,1);
    cout<<"INRODUCIR: izq "<<endl;
    cout<<"EXISTE raiz ? 1: "<<existe(c,5)<<endl;
    cout<<"EXISTE izq ? 1: "<<existe(c,4)<<endl;
    numClaves(c,num);
    cout<<"CLAVES ?2: "<<num<<endl;
    numCardinal(c,num);
    cout<<"REPS ?2: "<<num<<endl;
    


     introducir(c,6,6,1);
    cout<<"INRODUCIR: der "<<endl;
    cout<<"EXISTE raiz ? 1: "<<existe(c,5)<<endl;
    cout<<"EXISTE izq ? 1: "<<existe(c,4)<<endl;
    cout<<"EXISTE der ? 1: "<<existe(c,6)<<endl;
    numClaves(c,num);
    cout<<"CLAVES ?3: "<<num<<endl;
    numCardinal(c,num);
    cout<<"REPS ?3: "<<num<<endl;

    introducir(c,10,6,1);
     cout<<"INRODUCIR: der der"<<endl;
    cout<<"EXISTE raiz ? 1: "<<existe(c,5)<<endl;
    cout<<"EXISTE izq ? 1: "<<existe(c,4)<<endl;
    cout<<"EXISTE der ? 1: "<<existe(c,6)<<endl;
     cout<<"EXISTE der ? 1: "<<existe(c,10)<<endl;
    numClaves(c,num);
    cout<<"CLAVES ?4: "<<num<<endl;
    numCardinal(c,num);
    cout<<"REPS ?4: "<<num<<endl;

    introducir(c,0,6,1);
    introducir(c,-8,6,1);
     cout<<"INRODUCIR: der der"<<endl;
    cout<<"EXISTE raiz ? 1: "<<existe(c,5)<<endl;
    cout<<"EXISTE izq ? 1: "<<existe(c,4)<<endl;
    cout<<"EXISTE der ? 1: "<<existe(c,6)<<endl;
    cout<<"EXISTE der ? 1: "<<existe(c,10)<<endl;
    cout<<"EXISTE der ? 0: "<<existe(c,0)<<endl;
    cout<<"EXISTE der ? 0: "<<existe(c,-8)<<endl;
    numClaves(c,num);
    cout<<"CLAVES ?4: "<<num<<endl;
    numCardinal(c,num);
    cout<<"REPS ?4: "<<num<<endl;

    cout <<  endl;
    cout << "AÑADIR REPS" << endl;
    cout<<"-------------------------------------"<<endl;
    agnadirRep(c,5);
    cout<<"AÑADO raiz "<<endl;
    numClaves(c,num);
    cout<<"CLAVES ?4: "<<num<<endl;
    numCardinal(c,num);
    cout<<"REPS ?5: "<<num<<endl;

    agnadirRep(c,4);
    cout<<"AÑADO izq : "<<endl;
    numClaves(c,num);
    cout<<"CLAVES ?4: "<<num<<endl;
    numCardinal(c,num);
    cout<<"REPS ?6: "<<num<<endl;

    agnadirRep(c,6);
    cout<<"AÑADO der : "<<endl;
    numClaves(c,num);
    cout<<"CLAVES ?4: "<<num<<endl;
    numCardinal(c,num);
    cout<<"REPS ?7: "<<num<<endl;

    agnadirRep(c,10);
    cout<<"AÑADO der der"<<endl;
    numClaves(c,num);
    cout<<"CLAVES ?4: "<<num<<endl;
    numCardinal(c,num);
    cout<<"REPS ?8: "<<num<<endl;


    agnadirRep(c,-10);
    cout<<"AÑADO der der"<<endl;
    numClaves(c,num);
    cout<<"CLAVES ?4: "<<num<<endl;
    numCardinal(c,num);
    cout<<"REPS ?8: "<<num<<endl;

    cout << "ELIMINAR" << endl;
    cout<<"-------------------------------------"<<endl;
    cout<<"ELIMINO RAIZ"<<endl;

    eliminar(c,5);
    cout<<"EXISTE raiz(5) ? 0: "<<existe(c,5)<<endl;
    cout<<"EXISTE izq(4) ? 1: "<<existe(c,4)<<endl;
    cout<<"EXISTE der(6) ? 1: "<<existe(c,6)<<endl;
    cout<<"EXISTE der der(10) ? 1: "<<existe(c,10)<<endl;
    numClaves(c,num);
    cout<<"CLAVES ?3: "<<num<<endl;
    numCardinal(c,num);
    cout<<"REPS ?6: "<<num<<endl;
    introducir(c,5,1,1);
    introducir(c,3,1,1);
    numClaves(c,num);
     cout<<"INTRODUZCO izq y der izq"<<endl;
    cout<<"CLAVES ?5: "<<num<<endl;
    numCardinal(c,num);
    cout<<"REPS ?8: "<<num<<endl;
    cout<<"EXISTE raiz(5) ? 0: "<<existe(c,5)<<endl;
    cout<<"EXISTE izq(4) ? 1: "<<existe(c,4)<<endl;
    cout<<"EXISTE der(6) ? 1: "<<existe(c,6)<<endl;
    cout<<"EXISTE der der(10) ? 1: "<<existe(c,10)<<endl;
    cout<<"EXISTE der(3) ? 1: "<<existe(c,3)<<endl;
    cout<<"EXISTE der der(5) ? 1: "<<existe(c,5)<<endl;

    cout<<"ELIMINO der con dos hijos(6)"<<endl;
    eliminar(c,6);
    cout<<"REPS ?6: "<<num<<endl;
    cout<<"EXISTE raiz(4) ? 1: "<<existe(c,4)<<endl;
    cout<<"EXISTE izq(3) ? 1: "<<existe(c,3)<<endl;
    cout<<"EXISTE der(6) ? 0: "<<existe(c,6)<<endl;
    cout<<"EXISTE der der(10) ? 1: "<<existe(c,10)<<endl;
    cout<<"EXISTE izq(3) ? 1: "<<existe(c,3)<<endl;
    cout<<"EXISTE der izq(5) ? 1: "<<existe(c,5)<<endl;











    
    return 0;
}