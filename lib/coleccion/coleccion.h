/************************************************
* Autores:
* Íñigo Aréjula Aísa 785370
* Marcos Hernando Ibáñez 778053
 

 
 
*************************************************/

#ifndef COLECCION_H
#define COLECCION_H

#include "pila.h"

// Interfaz del TAD colección genérico.
// Pre-declaraciones:
// El tipo K requerirá tener definida una función:
// bool operator== (const K& t1, const K& t2)
//bool operator < (const K& t1, const K& t2)
//bool operator <= (const K& t1, const K& t2)
//bool operator > (const K& t1, const K& t2)
//bool operator >= (const K& t1, const K& t2)

//Los valores del TAD representan 
//colecciones de ternas(clave, dato, natural), en 
//las que no se permiten claves repetidas, en las que
// el natural representa el número de veces que está repetido
// el par(clave, dato) en la colección, y que cuentan con operaciones
// para gestionar las ternas además de un iterador para recorrerlas. }

template <typename K,typename D>
struct coleccion;


//definir operaciones de colecion:
//––––––––––––––––––––––––––––––––––

#warning DOC CREAR
template <typename K,typename D> 
void crear(coleccion<K,D> &c);


//devuelve true si y solo si existe un nodo con clave key
//en la coleccion
template <typename K, typename D>
bool existe(const coleccion<K,D> &c, K key);

#warning DOC INTRODUCIR
template <typename K, typename D>
bool introducir( coleccion<K,D> &c,K key,D data, int rp );

//Si existe un nodo con clave key y repeticiones = n entonces el valor de
//repeticones del nodo pasa a valer n+1, en caso contrario la colección
//no cambia, el valor de reps se actualiza
template <typename K, typename D>
void agnadirRep(coleccion<K,D> &c,K key);

#warning DOC QUITARREPS
template <typename K, typename D>
void quitarRep(coleccion<K,D> &c,K key);

//Si en la colección existe un nodo con clave key entonces se 
//devueva una coleccion igual eliminando el nodo con dicha clave
//y actualizando los valores de num y reps
template <typename K, typename D>
void eliminar(coleccion<K,D> &c,K key);

#warning DOC QUITARREPS
template <typename K, typename D>
bool obtenerInfo(coleccion<K,D> &c, K key, D &data, int &rp);

//devuelve el numero de nodos de la colección
template <typename K, typename D>
void numClaves(coleccion<K,D> &c, int &num);

//Devuelve el valor de la suma, para todos los nodos 
//(clave, dato,rep) en la colección c, de la tercera componente, rep.
template <typename K, typename D>
void numCardinal(coleccion<K,D> &c, int &card);

//definir operaciones del iterdador de la colecion:
//–––––––––––––––––––––––––––––––––––––––––––––––––

//Inicializa el iterador para recorrer los nodos de la colección c, 
//de forma que el siguiente nodo sea el primero a visitar 
//(situación de no haber visitado ningun nodo).
template <typename K, typename D>
void iniciarIterador(coleccion<K,D> &c);

#warning DOC EXISTESIG
template <typename K, typename D>
bool existeSiguiente(coleccion<K,D> &c);

//Devuelve la clave, dato y  natural (número de repeticiones)
// del siguiente nodo a visitar de c. 
//Parcial: la operación no está definida si ya se ha visitado la última terna.
template <typename K, typename D>
bool siguienteNodo(coleccion<K,D> &c, K &key, D &data, int &rp);

#warning DOC AVANZA
template <typename K, typename D>
bool avanza(coleccion<K,D> &c);

//fin de interfaz
// Declaración:
//–––––––––––––

template <typename K, typename D>
struct coleccion{

    friend void crear<K,D>(coleccion<K,D> &c);
    friend bool existe<K,D>(typename coleccion<K,D>::terna *paux, K key);
    friend bool existe<K,D>(const coleccion<K,D> &c, K key);
    friend bool introducir<K,D>(coleccion<K,D> &c, K key, D data, int rp);
    friend void agnadirRep<K,D>(coleccion<K,D> &c, K key);
    friend void quitarRep<K,D>(coleccion<K,D> &c, K key);
    friend void eliminar<K,D>(coleccion<K,D> &c, K key);
    friend bool obtenerInfo<K,D>(coleccion<K,D> &c, K key, D &data, int &rp);
    friend void numClaves<K,D>(coleccion<K,D> &c, int &num);
    friend void numCardinal<K,D>(coleccion<K,D> &c, int &card);
    friend void iniciarIterador<K,D>(coleccion<K,D> &c);
    friend bool existeSiguiente<K,D>(coleccion<K,D> &c);
    friend bool siguienteNodo<K,D>(coleccion<K,D> &c, K &key, D &data, int &rp);
    friend bool avanza<K,D>(coleccion<K,D> &c);

    private: 
        //ATRIBUTOS
        //Cada coleccion guarda la dirección del 
        //primer elemento (raiz) del arból binario,
        //además de el número de nodos (num), y el numero de 
        //repeticiones totales, esto sera la suma de las 
        //repetciones de cada nodo
        //contará con un puntero auxiliar de uso EXCLUSIVO 
        //del iterador

        //La colección se estructurará a modo de ABB

        //Se defie los nodos propios de la coleccion
        struct nodo
        {
            //ATRIBUTOS
            //Cada nodo cuenta con un dato y clave (tipo genérico)
            //también se almacena cuantas veces se repite cada nodo
            //además contará con dos punteros correpondientes a 
            //su hijo derecho y su hijo izquierdo, 
            D dato;
            K clave;
            int rep;
            nodo *izq;
            nodo *der;
        };
        nodo *raiz;//primer elemento
        int reps;//suma de repeteciones de todos los nodos
        int num;//numero de nodos
        nodo *index;//puntero auxiliar para el iterador estado actual
        nodo *index; //puntero auxiliar para el iterador siguiente 
        int keyMax;//guarda la clave con el valor máximo de la colección
        bool seen; //util para el iterador, marca si ya has pasado por el o no
        pila pl < typename coleccion<K, D>::nodo *>;
};

//implementar operaciones de colecion:
//––––––––––––––––––––––––––––––––––


template <typename K, typename D>
 void crear(coleccion<K,D> &c){
  
  #warning IMPLEMENTAR CREAR
}

//Devuelve true si ene l abb existe un nodo con clave key
template <typename K, typename D>
bool existe(typename coleccion<K, D>::nodo *a, K key)
{
    if(a == nullptr)return false;
    if(key < a->clave) return existe(a.izq,key);
    if(key == a->clave) return true;
    if(key > a->clave) return existe(a.der,key);

}

//devuelve true si y solo si existe un nodo con clave key
//en la coleccion
template <typename K, typename D>
bool existe(const coleccion<K,D> &c, K key)
{

    return existe(&c.raiz,key);
    
}


template <typename K, typename D>
bool introducir(coleccion<K,D> &c, K key, D data, int rp)
{

    //recuerda inicializar las variables del nodo, ej: seen = false
#warning IMPLEMENTAR INTRODUCIR
}


//busca en el abb a si se encuentra el nodo con clabe key, en dicho caso
//aumenta el valor de variable entera rep y devuelve true,
//false  en caso contario
template <typename K, typename D>
bool agnadirRep(typename coleccion<K, D>::nodo *a, K key)
{
    if(a == nullptr)return false;
    if(key <  a->clave) return existe(a.izq,key);
    if(key == a->clave){
        a->rep++;
        return true
    } 
    if(key > a->clave) return existe(a.der,key);
    

}

//Si existe un nodo con clave key y repeticiones = n entonces el valor de
//repeticones del nodo pasa a valer n+1, en caso contrario la colección
//no cambia, el valor de reps se actualiza
template <typename K, typename D>
void agnadirRep(coleccion<K,D> &c, K key)
{
    if(agnadirRep(&c.raiz,key)) c.reps++;
}


template <typename K, typename D>
void quitarRep(coleccion<K, D> & c, K key)
{
#warning IMPLEMENTAR QUITARREP
}


template <typename K, typename D>
int eliminar(typename coleccion<K, D>::nodo *a, K key)
{
    if (a == nullptr)
        return 0;
    if (key < a->clave)
        return existe(a.izq, key);
    if (key == a->clave)
    {
        int eli = a->rep
        delete a;
        a=nullptr;
        return eli;
    }
       
    if (key > a->clave)
        return existe(a.der, key);

}
//Si en la colección existe un nodo con clave key entonces se
//devueva una coleccion igual eliminando el nodo con dicha clave
//y actualizando los valores de num y reps
template <typename K, typename D>
void eliminar(coleccion<K,D> &c, K key)
{
    int eli;
    if(eli = eliminar(&c.raiz,key)>0)
    {
        c.reps-=eli;
        c.num--;
    }

}

template <typename K, typename D>
bool obtenerInfo(coleccion<K,D> &c, K key, D &data, int &rp)
{
#warning IMPLEMENTAR OBTENERINFO
}

//devuelve el numero de nodos de la colección
template <typename K, typename D>
void numClaves(coleccion<K,D> &c, int &num)
{
 num = c.num;
}

//Devuelve el valor de la suma, para todos los nodos
//(clave, dato,rep) en la colección c, de la tercera componente, rep.
template <typename K, typename D>
void numCardinal(coleccion<K,D> &c, int &card)
{
#warning IMPLEMENTAR NUMCARDINAL
}

//implementar operaciones del iterdador de la colecion:
//–––––––––––––––––––––––––––––––––––––––––––––––––


template <typename K, typename D>
typename coleccion<K, D>::nodo * iniciarIterador(typename coleccion<K, D>::nodo *a)
{

    if(a!=nullptr){

        if(a->izq ==nullptr) return a;
        else 
        {
            push(pl,a);
            return iniciarIterador(a->izq);

        }
    }

    
}

//Inicializa el iterador para recorrer los nodos de la colección c,
//de forma que el siguiente nodo sea el primero a visitar
//(situación de no haber visitado ningun nodo).
template <typename K, typename D>
void iniciarIterador(coleccion<K,D> &c)
{
    c.index = iniciarIterador(&c.raiz);

}





template <typename K, typename D>
bool existeSiguiente(coleccion<K,D> &c)
{
#warning IMPLEMENTAR EXISTESIGUIENTE
//este tiene que ser o(1) jeje
}

template <typename K, typename D>
bool siguienteNodo(typename coleccion<K, D>::nodo *a, typename coleccion<K, D>::nodo *res)
{
    //si existe izquierdo y no lo he visitado me toca
    if (a->izq != null && !a->izq->seen){
        push(pl,a);
        return siguienteNodo(a->izq,res);
    }
    else if(!a->seen){
        a->seen = true;
        res = a;
        return true;
    }
    else if (a->der != null && !a->der->seen){
        return siguienteNodo(a->der,res);
    }
    else
    {
        
        //abb a ha sido visitado entero, siguiente es su progenitor
        typename coleccion<K, D>::nodo *aux ;

        if(!top(pl, aux))return false;//si no hay progenitor
        else
        {
            pop(pl);
            res = aux
            //volver a poner a false los valores de los hijos
            a->izq->seen = false;
            a->der->seen = false;
            return true;
        }
    }
}

//Devuelve la clave, dato y  natural (número de repeticiones)
// del siguiente nodo a visitar de c.
//Parcial: la operación no está definida si ya se ha visitado la última terna.
template <typename K, typename D>
bool siguienteNodo(coleccion<K,D> &c, K &key, D &data, int &rp)
{
    typename coleccion<K, D>::nodo *aux;
    bool val= siguienteNodo(c.index, c.sig);
    data = c.sig->dato;
    rp = c.sig->rep;

}


template <typename K, typename D>
bool avanza(coleccion<K,D> &c)
{
#warning IMPLEMENTAR AVANZA
}

#endif // !COLECCION_H

