/************************************************
* Autores:
* Íñigo Aréjula Aísa 785370
* Marcos Hernando Ibáñez 778053
 

 
 
*************************************************/

#ifndef COLECCION_H
#define COLECCION_H

#include "pila.h"

using namespace std;


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


//template <typename K, typename D>
//typename coleccion<K, D>::nodo;

//definir operaciones de colecion:
//––––––––––––––––––––––––––––––––––

//Crea una colección c vacía (sin nodos)
//Coste constante en tiempo: o(1)
template <typename K, typename D>
void crear(coleccion<K, D> &c);

//devuelve true si y solo si existe un nodo con clave key
//en la coleccion
//En el peor de los casos tiene coste lineal en la altura
// que es aproximable a log2(n) y por tanto es coste o(log(n))
template <typename K, typename D>
bool existe(const coleccion<K,D> &c, K key);

//Si no existe un nodo con clave key actualiza la colección 
//resultado de añadir en c una   terna (k,data,rp). Si el nodo 
//ya existe la coleccion queda igual 
//En el peor de los casos tiene coste lineal en la altura
// que es aproximable a log2(n) y por tanto es coste o(log(n))
template <typename K, typename D>
bool introducir( coleccion<K,D> &c,K key,D data, int rp );

//Si existe un nodo con clave key y repeticiones = n entonces el valor de
//repeticones del nodo pasa a valer n+1, en caso contrario la colección
//no cambia, el valor de reps se actualiza
//En el peor de los casos tiene coste lineal en la altura
// que es aproximable a log2(n) y por tanto es coste o(log(n))
template <typename K, typename D>
void agnadirRep(coleccion<K,D> &c,K key);

//Si existe un nodo con clave key y repeticiones = n entonces el valor de
//repeticones del nodo pasa a valer n-1 (si reps pasa a valer 0 la elimina),
//en caso contrario la colección no cambia, el valor de reps se actualiza
//En el peor de los casos tiene coste lineal en la altura
// que es aproximable a log2(n) y por tanto es coste o(log(n))
template <typename K, typename D>
void quitarRep(coleccion<K,D> &c,K key);

//Si en la colección existe un nodo con clave key entonces se 
//devueva una coleccion igual eliminando el nodo con dicha clave
//y actualizando los valores de num y reps
//En el peor de los casos tiene coste lineal en la altura
// que es aproximable a log2(n) y por tanto es coste o(log(n))
template <typename K, typename D>
void eliminar(coleccion<K,D> &c,K key);

//Si en la colección existe un nodo con clave key entonces 
// data es igual a los datos del nodo y rp a las reps del mismo 
//En el peor de los casos tiene coste lineal en la altura
// que es aproximable a log2(n) y por tanto es coste o(log(n))
template <typename K, typename D>
bool obtenerInfo(coleccion<K,D> &c, K key, D &data, int &rp);

//devuelve el numero de nodos de la colección
//Coste constante: o(1)
template <typename K, typename D>
void numClaves(coleccion<K,D> &c, int &num);

//Devuelve el valor de la suma, para todos los nodos 
//(clave, dato,rep) en la colección c, de la tercera componente(rep).
//Coste constante: o(1)
template <typename K, typename D>
void numCardinal(coleccion<K,D> &c, int &card);

//definir operaciones del iterdador de la colecion:
//–––––––––––––––––––––––––––––––––––––––––––––––––

//Inicializa el iterador para recorrer los nodos de la colección c, 
//de forma que el siguiente nodo sea el primero a visitar 
//(situación de no haber visitado ningun nodo).
//Coste lineal en la altura al apilar los datos.
template <typename K, typename D>
void iniciarIterador(coleccion<K,D> &c);

//Devuelve true si y sólo si queda alguna terna por visitar con el iterador de la colección c
//Coste constante: o(1)
template <typename K, typename D>
bool existeSiguiente(coleccion<K,D> &c);

//Devuelve la clave, dato y  natural (número de repeticiones)
// del siguiente nodo a visitar de c. 
//Parcial: la operación no está definida si ya se ha visitado la última terna.
//Coste constante: o(1)
template <typename K, typename D>
bool siguienteNodo(coleccion<K,D> &c, K &key, D &data, int &rp);


//Prepara el iterador para visitar la siguiente terna de la colección c 
//Parcial: la operación no está definida si ya se ha visitado la última terna
//En el mejor caso coste constante o(1) en el peor lineal en la altura dos veces
//ya que si nos enconramos en el mayor del subarbol izquierdo de la raiz
//deberemos ascender todo el arbol y luego descemder por el 
//subarbol derecho hasta el menor sienod coste aproximable a log(n)
template <typename K, typename D>
bool avanza(coleccion<K,D> &c);

/***********************************************
    *Funciones auxiliares
    *––––––––––––––––––––––––––––––––––––––––––
    *NO SON PARTE DE LA ESPECIFICACIÓN PÚBLICA
    *––––––––––––––––––––––––––––––––––––––––––
    ***********************************************/

//Devuelve true si en el abb existe un nodo con clave key
template <typename K, typename D>
bool existeR(typename coleccion<K, D>::nodo *a, K key);

//Devuelve true si y solo si ha introducido el nodo en la coleccion
template <typename K, typename D>
bool introducirR(typename coleccion<K, D>::nodo *&a, K key, D data, int rp);

//busca en el abb a si se encuentra el nodo con clave key, en dicho caso
//aumenta el valor de variable entera rep y devuelve true,
//false  en caso contario
template <typename K, typename D>
bool agnadirRepR(typename coleccion<K, D>::nodo *a, K key);

//busca en el abb a si se encuentra el nodo con clave key, en dicho caso
//dismiuye el valor de variable entera rep (si la actualiza a cero la elimina)
//y devuelve true. False  en caso contario
template <typename K, typename D>
bool quitarRepR(coleccion<K, D> &c,typename coleccion<K, D>::nodo *&a, K key);

//Elimina el nodo con mayor clave del subarbol cuya 
//raiz es a. Actualiza los parámetros de salida con 
//los datos del nodo eliminado
template <typename K, typename D>
void eliminarMaxClave(typename coleccion<K, D>::nodo *&a,K &key, D &dat, int &rp, int &eli);

//Devuelve el número de repeteticiones del nodo con clave key
// y lo elimina de la colección, devuelve cero si el puntero es nulo
template <typename K, typename D>
int eliminarR(typename coleccion<K, D>::nodo *&a, K key);

//Busca en el abb a si se encuentra el nodo con clave key, en dicho caso
//data = datos del nodo, rp = reps del nodo y devuelve true,
//false  en caso contario
template <typename K, typename D>
bool obtenerInfoR(typename coleccion<K, D>::nodo *a, K key, D &data, int &rp);

//fin de interfaz
// Declaración:
//–––––––––––––


template <typename K, typename D>
struct coleccion{

    friend void crear<K,D>(coleccion<K,D> &c);
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
    friend bool avanza<K, D>(coleccion<K,D> &c);

    

    
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
        pila < typename coleccion<K, D>::nodo *> pl;

        friend bool existeR<K, D>(typename coleccion<K, D>::nodo *a, K key);
        friend bool introducirR<K, D>(typename coleccion<K, D>::nodo *&a, K key, D data, int rp);
        friend bool agnadirRepR<K, D>(typename coleccion<K, D>::nodo *a, K key);
        friend bool quitarRepR<K, D>(coleccion<K, D> &c,typename coleccion<K, D>::nodo *&a, K key);
        friend void eliminarMaxClave<K, D>(typename coleccion<K, D>::nodo *&a,K &key, D &dat, int &rp, int &eli);
        friend int eliminarR<K, D>(typename coleccion<K, D>::nodo *&a, K key);
        friend bool obtenerInfoR<K, D>(typename coleccion<K, D>::nodo *a, K key, D &data, int &rp);
       
};

//implementar operaciones de colecion:
//––––––––––––––––––––––––––––––––––
//Crea una colección c vacía (sin nodos)
template <typename K, typename D>
 void crear(coleccion<K,D> &c){

     c.reps = 0;
     c.num = 0;
     c.raiz = nullptr;
     crear(c.pl);

}

//Devuelve true si en el abb existe un nodo con clave key
//En el peor de los casos tiene coste lineal en la altura
// que es aproximable a log2(n) y por tanto es coste o(log(n))
template <typename K, typename D>
bool existeR(typename coleccion<K, D>::nodo *a, K key)
{
    if(a == nullptr)return false;
    if(key < a->clave) return existeR<K, D>(a->izq,key);
    if(key == a->clave) return true;
    else return existeR<K, D>(a->der,key);

}

//devuelve true si y solo si existe un nodo con clave key
//en la coleccion 
template <typename K, typename D>
bool existe(const coleccion<K,D> &c, K key)
{

    return existeR<K,D>(c.raiz,key);
    
}

//Devuelve true si y solo si ha introducido el nodo en la coleccion
template <typename K, typename D>
bool introducirR(typename coleccion<K, D>::nodo*& a, K key, D data, int rp){
    
    if(a == nullptr)
    {
        a =  new typename coleccion<K, D>::nodo;
        a->izq= nullptr;
        a->der = nullptr;
        a->dato = data;
        a->clave = key;
        a->rep = rp;
        return true;
    }
      
    
    if(key < a->clave)
    {
        return introducirR<K, D>(a->izq,key,data,rp);
    }

    if(key == a->clave)
    {
        return false;
    }

    else 
    {
        return introducirR<K, D>(a->der,key,data,rp);
    }


}




//Si no existe un nodo con clave key actualiza la colección 
//resultado de añadir en c una   terna (k,data,rp). Si el nodo 
//ya existe la coleccion queda igual 
template <typename K, typename D>
bool introducir(coleccion<K,D> &c, K key, D data, int rp)
{
    if(rp>0){
        if(introducirR<K, D>(c.raiz,key,data,rp))
        {
            c.num++;
            c.reps = c.reps + rp;
        } 
        //devuelve true si la clave es natural
        return true;

   }
   else return false;
    
    

}


//busca en el abb a si se encuentra el nodo con clave key, en dicho caso
//aumenta el valor de variable entera rep y devuelve true,
//false  en caso contario//Coste o(n) en tiempo
//En el peor de los casos tiene coste lineal en la altura
// que es aproximable a log2(n) y por tanto es coste o(log(n))
template <typename K, typename D>
bool agnadirRepR(typename coleccion<K, D>::nodo *a, K key)
{
    if(a == nullptr)return false;
    if(key <  a->clave) return agnadirRepR<K, D>(a->izq,key);
    if(key == a->clave){
        a->rep++;
        return true;
    } 
    else return agnadirRepR<K, D>(a->der,key);
    

}

//Si existe un nodo con clave key y repeticiones = n entonces el valor de
//repeticones del nodo pasa a valer n+1, en caso contrario la colección
//no cambia, el valor de reps se actualiza
template <typename K, typename D>
void agnadirRep(coleccion<K,D> &c, K key)
{
    if(agnadirRepR<K, D>(c.raiz,key)) c.reps++;
}



//busca en el abb a si se encuentra el nodo con clave key, en dicho caso
//dismiuye el valor de variable entera rep (si la actualiza a cero la elimina)
//y devuelve true. False  en caso contario
//En el peor de los casos tiene coste lineal en la altura
// que es aproximable a log2(n) y por tanto es coste o(log(n))
template <typename K, typename D>
bool quitarRepR(coleccion<K, D> &c,typename coleccion<K, D>::nodo *&a, K key)
{
    if(a == nullptr){
        
        return false;
    }
    if(key <  a->clave) return quitarRepR<K, D>(c,a->izq,key);
    if(key == a->clave){
        a->rep--;
        if(a->rep == 0){
            //llamamos a eliminar en el nodo que queremos elimanar
            //de tal forma que no tiene un costo extra en la busqueda
            eliminarR<K, D>(a,a->clave);//ya le 
            c.num-- ;
          
        }
        else{
         
        }
        return true;

    } 
    else return quitarRepR<K, D>(c,a->der,key);
    

}

//Si existe un nodo con clave key y repeticiones = n entonces el valor de
//repeticones del nodo pasa a valer n-1 (si reps pasa a valer 0 la elimina),
//en caso contrario la colección no cambia, el valor de reps se actualiza
template <typename K, typename D>
void quitarRep(coleccion<K, D> & c, K key)
{
    if(quitarRepR<K, D>(c,c.raiz,key)){
        c.reps--;
    }
  
    
}

//Elimina el nodo con mayor clave del subarbol cuya 
//raiz es a. Actualiza los parámetros de salida con 
//los datos del nodo eliminado
//En el peor de los casos tiene coste lineal en la altura
// que es aproximable a log2(n) y por tanto es coste o(log(n))
template <typename K, typename D>
void eliminarMaxClave(typename coleccion<K, D>::nodo *&a,K &key, D &dat, int &rp, int &eli){
    typename coleccion<K, D>::nodo *aux;
    if(a->der == nullptr){
        
        eli = a->rep;
        key = a->clave;
        rp = a->rep;
        dat = a->dato;
        aux = a;
        a = a->izq;
        delete(aux);
    }
    else{
        eliminarMaxClave<K, D>(a->der,key,dat,rp,eli);
    }



}


//Devuelve el número de repeteticiones del nodo con clave key
// y lo elimina de la colección, devuelve cero si el puntero es nulo
//En el peor de los casos tiene coste lineal en la altura
// que es aproximable a log2(n) y por tanto es coste o(log(n))
template <typename K, typename D>
int eliminarR(typename coleccion<K, D>::nodo *&a, K key)
{
    if (a == nullptr){
        return 0;// si es vacio el arbol no devuelve reps
    }

    else if (key < a->clave){
        return eliminarR<K, D>(a->izq, key);
    }
    else if (key > a->clave)
    {
        return eliminarR<K, D>(a->der, key);
    }

    else //Es el nodo a eliminar
    {
        int eli = a->rep;
        typename coleccion<K, D>::nodo *aux;
        if(a->izq==nullptr){
            aux =a;
            a = a->der;
            delete aux;
        }
        else if (a->der ==nullptr)
        {
            aux = a;
            a = a->izq;
            delete aux;
        }
        else{

            eliminarMaxClave<K, D>(a->izq,a->clave,a->dato,a->rep,eli);
           
            
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
    eli = eliminarR<K, D>(c.raiz,key);
    if(eli >0)
    {
        c.reps-=eli;
        c.num--;
    }

}

//Busca en el abb a si se encuentra el nodo con clave key, en dicho caso
//data = datos del nodo, rp = reps del nodo y devuelve true,
//false  en caso contario//Coste o(n) en tiempo
//En el peor de los casos tiene coste lineal en la altura
// que es aproximable a log2(n) y por tanto es coste o(log(n))
template <typename K, typename D>
bool obtenerInfoR(typename coleccion<K, D>::nodo *a, K key, D &data, int &rp)
{
    if(a == nullptr)return false;
    if(key <  a->clave) return obtenerInfoR<K, D>(a->izq,key,data,rp);
    if(key == a->clave){
        data = a->dato;
        rp = a->rep;
        return true;
    } 
    else return obtenerInfoR<K, D>(a->der,key,data,rp);

    

}


//Si en la colección existe un nodo con clave key entonces 
// data es igual a los datos del nodo y rp a las reps del mismo 
template <typename K, typename D>
bool obtenerInfo(coleccion<K,D> &c, K key, D &data, int &rp)
{
    return obtenerInfoR<K, D>(c.raiz, key, data, rp);
}

//devuelve el numero de nodos de la colección
template <typename K, typename D>
void numClaves(coleccion<K,D> &c, int &num)
{
     num = c.num;
}

//Devuelve el valor de la suma, para todos los nodos
//(clave, dato,rep) en la colección c, de la tercera componente (rep).
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
void iniciarIterador( coleccion<K,D> &c)
{   
    
    clear(c.pl);
    typename coleccion<K, D>::nodo *aux = c.raiz;
    while (aux != nullptr)
    {
        push(c.pl, aux);
        aux = aux->izq;
    }
    
}



//Devuelve true si y sólo si queda alguna terna por visitar con el iterador de la colección c
template <typename K, typename D>
bool existeSiguiente(coleccion<K,D> &c)
{
    return !empty(c.pl); //Hay siguiente dato en la pila
}

//Devuelve la clave, dato y  natural (número de repeticiones)
// del siguiente nodo a visitar de c.
//Parcial: la operación no está definida si ya se ha visitado la última terna.
template <typename K, typename D>
bool siguienteNodo(coleccion<K,D> &c, K &key, D &data, int &rp)
{
    typename coleccion<K, D>::nodo *aux;
    if(existeSiguiente(c)){
        top(c.pl, aux);
        key = aux->clave;
        data = aux->dato;
        rp = aux->rep;
        
        return true;
    }

    else{
        return false;
    }

}


//Prepara el iterador para visitar la siguiente terna de la colección c 
//Parcial: la operación no está definida si ya se ha visitado la última terna
template <typename K, typename D>
bool avanza(coleccion<K,D> &c)
{
    if(!empty(c.pl)){
        typename coleccion<K, D>::nodo *aux;
        top(c.pl,aux);
        pop(c.pl);
        
        aux = aux->der;
        while(aux != nullptr){
                push(c.pl, aux);
                aux = aux->izq;
        }
        return true;
    }
    else return false;
}

#endif // !COLECCION_H
