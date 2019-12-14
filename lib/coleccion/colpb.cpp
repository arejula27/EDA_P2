#include <iostream>
#include "coleccion.h"

using namespace std;



int main(int argc, char **argv)
{
    coleccion<int,int> c;
    crear(c);
    cout << "CREAR E INTRODUCIR" << endl;
    cout<<"----------------------------------"<<endl;
    cout<<"EXISTE(2) ? 0: "<<existe(c,2)<<endl;
    cout<<"INRODUCIR: "<<endl;
    introducir(c,5,5,1);
    cout<<"EXISTE raiz(5) ? 1: "<<existe(c,5)<<endl;
    int num;
    numClaves(c,num);
    cout<<"CLAVES ?1: "<<num<<endl;
    numCardinal(c,num);
    cout<<"REPS ?1: "<<num<<endl;

    introducir(c,4,4,1);
    cout<<"INRODUCIR: izq "<<endl;
    cout<<"EXISTE raiz(5) ? 1: "<<existe(c,5)<<endl;
    cout<<"EXISTE izq(4) ? 1: "<<existe(c,4)<<endl;
    numClaves(c,num);
    cout<<"CLAVES ?2: "<<num<<endl;
    numCardinal(c,num);
    cout<<"REPS ?2: "<<num<<endl;
    
    cout<<"INRODUCIR: der "<<endl;
    introducir(c,6,6,2);
    
    
    cout<<"REPS(der) ? 1: ";
    quitarRep(c,6);
    cout<<"REPS(der) ? 0: ";
    quitarRep(c,6);
    cout<<"EXISTE raiz(5) ? 1: "<<existe(c,5)<<endl;
    cout<<"EXISTE izq(4) ? 1: "<<existe(c,4)<<endl;
    cout<<"EXISTE der(6) ? 0: "<<existe(c,6)<<endl;
    numClaves(c,num);
    cout<<"CLAVES ?2: "<<num<<endl;
    numCardinal(c,num);
    cout<<"REPS ?2: "<<num<<endl;

    introducir(c,10,6,2);
    cout<<"INRODUCIR: der der"<<endl;
    cout<<"EXISTE raiz(5) ? 1: "<<existe(c,5)<<endl;
    cout<<"EXISTE izq(4) ? 1: "<<existe(c,4)<<endl;
    cout<<"EXISTE der(6) ? 0: "<<existe(c,6)<<endl;
    cout<<"EXISTE der(10) ? 1: "<<existe(c,10)<<endl;
    numClaves(c,num);
    cout<<"CLAVES ?3: "<<num<<endl;
    numCardinal(c,num);
    cout<<"REPS ?4: "<<num<<endl;

    introducir(c,0,6,0);
    introducir(c,-8,5,2);
    introducir(c,8,6,-3);
    cout<<"INRODUCIR: der der"<<endl;
    cout<<"EXISTE raiz(5) ? 1: "<<existe(c,5)<<endl;
    cout<<"EXISTE izq(4) ? 1: "<<existe(c,4)<<endl;
    cout<<"EXISTE der(6) ? 0: "<<existe(c,6)<<endl;
    cout<<"EXISTE der(10) ? 1: "<<existe(c,10)<<endl;
    cout<<"EXISTE izd(0) ? 0: "<<existe(c,0)<<endl;
    cout<<"EXISTE izd(8) ? 0: "<<existe(c,8)<<endl;
    cout<<"EXISTE izd(-8) ? 1: "<<existe(c,-8)<<endl;
    numClaves(c,num);
    cout<<"CLAVES ? 4: "<<num<<endl;
    numCardinal(c,num);
    cout<<"REPS ?6: "<<num<<endl;

    
    cout<<"PARTE DE IÑIGO\n";
    cout  << endl;
    cout << "AÑADIR REPS" << endl;
    cout<<"-------------------------------------\n";

    cout << "reconstruyo\n" <<endl;
    eliminar(c,5);
    eliminar(c,10);
    eliminar(c,4);
    eliminar(c,0);
    eliminar(c,-8);
    

    introducir(c,4,1,1);
    introducir(c,3,1,1);
    introducir(c,6,1,1);
    introducir(c,5,1,1);
    introducir(c,10,1,1);
    

    
    agnadirRep(c,4);
    cout<<"AÑADO raiz(4) "<<endl;
    numClaves(c,num);
    cout<<"CLAVES ?5: "<<num<<endl;
    numCardinal(c,num);
    cout<<"REPS ?6: "<<num<<endl;

    agnadirRep(c,3);
    cout<<"AÑADO izq(3) : "<<endl;
    numClaves(c,num);
    cout<<"CLAVES ?5: "<<num<<endl;
    numCardinal(c,num);
    cout<<"REPS ?7: "<<num<<endl;

    agnadirRep(c,6);
    cout<<"AÑADO der : "<<endl;
    numClaves(c,num);
    cout<<"CLAVES ?5: "<<num<<endl;
    numCardinal(c,num);
    cout<<"REPS ?8: "<<num<<endl;

    agnadirRep(c,10);
    cout<<"AÑADO der der"<<endl;
    numClaves(c,num);
    cout<<"CLAVES ?5: "<<num<<endl;
    numCardinal(c,num);
    cout<<"REPS ?9: "<<num<<endl;

    agnadirRep(c,5);
    cout<<"AÑADO der der"<<endl;
    numClaves(c,num);
    cout<<"CLAVES ?5: "<<num<<endl;
    numCardinal(c,num);
    cout<<"REPS ?10: "<<num<<endl;


    agnadirRep(c,-10);
    cout<<"AÑADO der der"<<endl;
    numClaves(c,num);
    cout<<"CLAVES ?5: "<<num<<endl;
    numCardinal(c,num);
    cout<<"REPS ?9: "<<num<<endl;

    cout << "ELIMINAR" << endl;
    cout<<"-------------------------------------"<<endl;
    cout<<"ELIMINO RAIZ"<<endl;

    eliminar(c,4);
    cout<<"EXISTE raiz(4) ? 0: "<<existe(c,4)<<endl;
    cout<<"EXISTE izq(5) ? 1: "<<existe(c,5)<<endl;
    cout<<"EXISTE der(6) ? 1: "<<existe(c,6)<<endl;
     cout<<"EXISTE iz2(3) ? 1: "<<existe(c,3)<<endl;
    cout<<"EXISTE der der(10) ? 1: "<<existe(c,10)<<endl;
    numClaves(c,num);
    cout<<"CLAVES ?4: "<<num<<endl;
    numCardinal(c,num);
    cout<<"REPS ?8: "<<num<<endl;

    introducir(c,7,1,1);
    introducir(c,2,1,1);
    numClaves(c,num);
     cout<<"INTRODUZCO izq(3) y der izq(5)"<<endl;
    cout<<"CLAVES ?6: "<<num<<endl;
    numCardinal(c,num);
    cout<<"REPS ?10: "<<num<<endl;
    cout<<"EXISTE raiz(3) ? 1: "<<existe(c,3)<<endl;
    cout<<"EXISTE izq(2) ? 1: "<<existe(c,2)<<endl;
    cout<<"EXISTE der(6) ? 1: "<<existe(c,6)<<endl;
    cout<<"EXISTE der der(10) ? 1: "<<existe(c,10)<<endl;
    cout<<"EXISTE der izq(5) ? 1: "<<existe(c,5)<<endl;
    cout<<"EXISTE der der izq (7) ? 1: "<<existe(c,7)<<endl;
    eliminar(c,5);
    introducir(c,4,1,1);
    introducir(c,5,1,1);

    cout<<"ELIMINO der con dos hijos(6)"<<endl;
    int a;
    eliminar(c,6);
    numCardinal(c,num);
    cout<<"REPS ?8: "<<num<<endl;
    numClaves(c,num);
    cout<<"CLAVES?6: "<<num<<endl;
    cout<<"EXISTE raiz(3) ? 1: "<<existe(c,3)<<endl;
    cout<<"EXISTE izq(2) ? 1: "<<existe(c,2)<<endl;
    cout<<"EXISTE der(5) ? 1: "<<existe(c,5)<<endl;
    cout<<"EXISTE der der(10) ? 1: "<<existe(c,10)<<endl;
    cout<<"EXISTE der izq(4) ? 1: "<<existe(c,4)<<endl;
    cout<<"EXISTE der der der izq(7) ? 1: "<<existe(c,7)<<endl;
    cout<<"EXISTE no(6) ? 0: "<<existe(c,6)<<endl;

    
    return 0;
}