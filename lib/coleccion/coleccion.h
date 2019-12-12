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
// bool operator < (const K& t1, const K& t2)
// bool operator <= (const K& t1, const K& t2)
// bool operator > (const K& t1, const K& t2)
// bool operator >= (const K& t1, const K& t2)

// Los valores del TAD representan 
// colecciones de ternas(clave, dato, natural), en 
// las que no se permiten claves repetidas, en las que
// el natural representa el número de veces que está repetido
// el par(clave, dato) en la colección, y que cuentan con operaciones
// para gestionar las ternas además de un iterador para recorrerlas. }

template <typename K,typename D>
struct coleccion;


//definir operaciones de colecion:
//––––––––––––––––––––––––––––––––––

//Crea una colección c vacía (sin nodos)
template <typename K,typename D> 
void crear(coleccion<K,D> &c);


//devuelve true si y solo si existe un nodo con clave key
//en la coleccion
template <typename K, typename D>
bool existe(const coleccion<K,D> &c, K key);

//Si no existe un nodo con clave key actualiza la colección 
//resultado de añadir en c una   terna (k,data,rp). Si el nodo 
//ya existe la coleccion queda igual 
template <typename K, typename D>
void introducir( coleccion<K,D> &c,K key,D data, int rp );

//Si existe un nodo con clave key y repeticiones = n entonces el valor de
//repeticones del nodo pasa a valer n+1, en caso contrario la colección
//no cambia, el valor de reps se actualiza
template <typename K, typename D>
void agnadirRep(coleccion<K,D> &c,K key);

//Si existe un nodo con clave key y repeticiones = n entonces el valor de
//repeticones del nodo pasa a valer n-1 (si reps pasa a valer 0 la elimina),
//en caso contrario la colección no cambia, el valor de reps se actualiza
template <typename K, typename D>
void quitarRep(coleccion<K,D> &c,K key);

//Si en la colección existe un nodo con clave key entonces se 
//devueva una coleccion igual eliminando el nodo con dicha clave
//y actualizando los valores de num y reps
template <typename K, typename D>
void eliminar(coleccion<K,D> &c,K key);

//Si en la colección existe un nodo con clave key entonces 
// data es igual a los datos del nodo y rp a las reps del mismo 
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

//Devuelve verdad si y sólo si queda alguna terna por visitar con el iterador de la colección c
template <typename K, typename D>
bool existeSiguiente(coleccion<K,D> &c);

//Devuelve la clave, dato y  natural (número de repeticiones)
// del siguiente nodo a visitar de c. 
//Parcial: la operación no está definida si ya se ha visitado la última terna.
template <typename K, typename D>
bool siguienteNodo(coleccion<K,D> &c, K &key, D &data, int &rp);


//Prepara el iterador para visitar la siguiente terna de la colección c 
//Parcial: la operación no está definida si ya se ha visitado la última terna
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
    friend void introducir<K,D>(coleccion<K,D> &c, K key, D data, int rp);
    friend void agnadirRep<K,D>(coleccion<K,D> &c, K key);
    friend void quitarRep<K,D>(coleccion<K,D> &c, K key);
    friend void eliminar<K,D>(coleccion<K,D> &c, K key);
    friend bool obtenerInfo<K,D>(coleccion<K,D> &c, K key, D &data, int &rp);
    friend void numClaves<K,D>(coleccion<K,D> &c, int &num);
    friend void numCardinal<K,D>(coleccion<K,D> &c, int &card);
    friend void iniciarIterador<K,D>(coleccion<K,D> &c);
    friend bool existeSiguiente<K,D>(coleccion<K,D> &c);
    friend bool siguienteNodo<K,D>(coleccion<K,D> &c, K &key, D &data, int &rp);
    friend bool avanza(const coleccion<K,D> &c);

    /***********************************************
    *Funciones auxiliares
    *––––––––––––––––––––––––––––––––––––––––––
    *NO SON PARTE DE LA ESPECIFICACIÓN PÚBLICA
    *––––––––––––––––––––––––––––––––––––––––––
    ***********************************************/

    friend bool existe(typename coleccion<K, D>::nodo *a, K key)
    friend bool introducir(typename coleccion<K, D>::nodo *a, K key, D data, int rp);
    friend bool agnadirRep(typename coleccion<K, D>::nodo *a, K key);
    friend bool quitarRep(typename coleccion<K, D>::nodo *a, K key);
    friend int eliminar(typename coleccion<K, D>::nodo *a, K key);
    friend bool obtenerInfo(typename coleccion<K, D>::nodo *a, K key, D &data, int &rp);

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
        int keyMax;//guarda la clave con el valor máximo de la colección
        pila < typename coleccion<K, D>::nodo *> pl;
};

//implementar operaciones de colecion:
//––––––––––––––––––––––––––––––––––

//Crea una colección c vacía (sin nodos)
template <typename K, typename D>
 void crear(coleccion<K,D> &c){

     c.index=nullptr;
     c.reps = 0;
     c.num = 0;
     c.raiz = nullptr;
     c.keyMax = 0;
     crear(c.pl);

}

//Devuelve true si en el abb existe un nodo con clave key
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

//Devuelve true si y solo si ha introducido el nodo en la coleccion
template <typename K, typename D>
bool introducir(typename coleccion<K, D>::nodo *a, K key, D data, int rp){
    if(key < a->clave){
        if(a->izd == nullptr){
            a->izd = typename coleccion<K, D>::nodo;
            a->izd->dato = data;
            a->izd->clave = key;
            a->izd->rep = rp;
            a->izd->izd = nullptr;
            a->izd->der = nullptr;
            return true;
        }
        else return introducir(a.izd,key,data,rp);
    }

    if(key == a->clave){
        return false;
    }

    if(key > a->clave){
        if(a->der == nullptr){
            a->izd = typename coleccion<K, D>::nodo;
            a->izd->dato = data;
            a->izd->clave = key;
            a->izd->rep = rp;
            a->izd->izd = nullptr;
            a->izd->der = nullptr;
            return true;
        }
        else return introducir(a.der,key,data,rp);
    }


}




//Si no existe un nodo con clave key actualiza la colección 
//resultado de añadir en c una   terna (k,data,rp). Si el nodo 
//ya existe la coleccion queda igual 
template <typename K, typename D>
void introducir(coleccion<K,D> &c, K key, D data, int rp)
{
   
   if(c.raiz == nullptr){
        c.raiz =  typename coleccion<K, D>::nodo;
        c.raiz->izd = nullptr;
        c.raiz->der = nullptr;
        c.raiz->dato = data;
        c.raiz->clave = key;
        c.raiz->rep = rp;
      
   }
   else if(introducir(&c.raiz,key,data,rp)){
       c.num++;
       c.reps = c.reps + rp;
   } 
    

}


//busca en el abb a si se encuentra el nodo con clave key, en dicho caso
//aumenta el valor de variable entera rep y devuelve true,
//false  en caso contario
template <typename K, typename D>
bool agnadirRep(typename coleccion<K, D>::nodo *a, K key)
{
    if(a == nullptr)return false;
    if(key <  a->clave) return existe(a.izq,key);
    if(key == a->clave){
        a->rep++;
        return true;
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



//busca en el abb a si se encuentra el nodo con clave key, en dicho caso
//dismiuye el valor de variable entera rep (si la actualiza a cero la elimina)
//y devuelve true. False  en caso contario
template <typename K, typename D>
bool quitarRep(typename coleccion<K, D>::nodo *a, K key)
{
    if(a == nullptr)return false;
    if(key <  a->clave) return quitarRep(a.izq,key);
    if(key == a->clave){
        a->rep--;
        if(a->rep == 0){
            delete a;
            a=nullptr;
            c.num-- ;
        }
        return true;
    } 
    if(key > a->clave) return quitarRep(a.der,key);
    

}

//Si existe un nodo con clave key y repeticiones = n entonces el valor de
//repeticones del nodo pasa a valer n-1 (si reps pasa a valer 0 la elimina),
//en caso contrario la colección no cambia, el valor de reps se actualiza
template <typename K, typename D>
void quitarRep(coleccion<K, D> & c, K key)
{
    if(quitarRep(&c.raiz,key)) c.reps--;
    
}

//Devuelve el número de repeteticiones del nodo con clave key
// y lo elimina de la colección, devuelve cero si el puntero es nulo
template <typename K, typename D>
int eliminar(typename coleccion<K, D>::nodo *a, K key)
{
    if (a == nullptr){
        return 0;// si es vacio el arbol no devuelve reps
    }

    if (key < a->clave){
        return eliminar(a.izq, key);
    }
    else if (key > a->clave)
    {
        return eliminar(a.der, key);
    }

    else if (key == a->clave)
    {
        int eli = a->rep
        typename coleccion<K, D>::nodo *aux;
        if(a.izq==nullptr){
            aux =a;
            a = a.der;
            delete aux;
        }
        else if (a.der ==nullptr)
        {
            aux = a;
            a = a.izq;
            delete aux;
        }
        else{
            aux = a->izq;
            while (aux->der != nullptr)
            {
                aux = aux->der;
            }
            a->dato=aux->dato;
            a->clave= aux->clave;
            a->rep=aux->rep;
            eliminar(a->izq,a->dato);
           
            
        }
        return eli;
    }
       
    
    
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

//Busca en el abb a si se encuentra el nodo con clave key, en dicho caso
//data = datos del nodo, rp = reps del nodo y devuelve true,
//false  en caso contario
template <typename K, typename D>
bool obtenerInfo(typename coleccion<K, D>::nodo *a, K key, D &data, int &rp)
{
    if(a == nullptr)return false;
    if(key <  a->clave) return obtenerInfo(a.izq,key,&data,&rp);
    if(key == a->clave){
        data = a->dato;
        rp = a->rep;
        return true;
    } 
    if(key > a->clave) return obtenerInfo(a.der,key,&data,&rp);

    

}


//Si en la colección existe un nodo con clave key entonces 
// data es igual a los datos del nodo y rp a las reps del mismo 
template <typename K, typename D>
bool obtenerInfo(coleccion<K,D> &c, K key, D &data, int &rp)
{
    obtenerInfo(c.raiz, key, &data, &rp);
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
    card = c.reps;
}

//implementar operaciones del iterdador de la colecion:
//–––––––––––––––––––––––––––––––––––––––––––––––––


//Inicializa el iterador para recorrer los nodos de la colección c,
//de forma que el siguiente nodo sea el primero a visitar
//(situación de no haber visitado ningun nodo).
template <typename K, typename D>
void iniciarIterador(const coleccion<K,D> &c)
{   
     c.index = nullptr;
     clear(c.pl)
    typename coleccion<K, D>::nodo *aux = c.raiz;
    while (aux != nullptr)
    {
        push(&c.pl, aux);
        aux = aux->izd;
    }
    
}



//Devuelve true si el puntero del indice no es nulo
template <typename K, typename D>
bool existeSiguiente(const coleccion<K,D> &c)
{
    return !empty(c.pl); //Hay siguiente dato en la pila
}

//Devuelve la clave, dato y  natural (número de repeticiones)
// del siguiente nodo a visitar de c.
//Parcial: la operación no está definida si ya se ha visitado la última terna.
template <typename K, typename D>
bool siguienteNodo(const coleccion<K,D> &c, K &key, D &data, int &rp)
{
    typename coleccion<K, D>::nodo *aux;
    if(existeSiguiente(c)){
        top(c.pl, aux);
        key = aux->clave;
        data = aux->dato;
        rp = aux->rep;
        return true;
    }
    return false;

}


//Prepara el iterador para visitar la siguiente terna de la colección c 
//Parcial: la operación no está definida si ya se ha visitado la última terna
template <typename K, typename D>
bool avanza(const coleccion<K,D> &c)
{
    if(!empty(c.pl)){
        typename coleccion<K, D>::nodo *aux;
        pop(&c.pl);
        aux = aux->der;
        while(aux != nullptr){
                push(&c.pl, aux);
                aux = aux->izd;
        }
        return true;
    }
    else return false;
}

#endif // !COLECCION_H

