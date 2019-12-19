/************************************************
* Autores:
* Íñigo Aréjula Aísa 785370
* Marcos Hernando Ibáñez 778053
 

 
 
*************************************************/

#ifndef COLECCION_H
#define COLECCION_H

#include "pila.h"

using namespace std;




// Los valores del TAD representan 
// colecciones de ternas(clave, dato, natural), en 
// las que no se permiten claves repetidas dentro de la coleción.
//  Las ternas estan compuesta por una clave de tipo K, un dato de tipo D
//y un numero natural de tipo int (por lo que no se podrá usar ni el 0 ni los 
// negativos). El natural indica el número de veces que se encuentra dicho dato y clave 
// en la colección, por ello más adelante se hara referencia a este natural como repeteciones
//  
// La colección cuenta con un iterado que nos permitirá recorrer toda la colección
// yendo de la menor clave a la mayor.
//
// El tipo K requerirá tener definida una función:
// bool operator== (const K& t1, const K& t2)
// bool operator < (const K& t1, const K& t2) siendo t1 menor que t2
// bool operator > (const K& t1, const K& t2) siendo t1 mayor que t2

// Interfaz del TAD colección genérico.
template <typename K,typename D>
struct coleccion;


//definir operaciones de colecion:
//––––––––––––––––––––––––––––––––––

//Crea una colección c vacía 
//Coste constante en tiempo: o(1)
template <typename K, typename D>
void crear(coleccion<K, D> &c);

//devuelve true si y solo si existe una terna con clave key
//en la coleccion
//En el peor de los casos tiene coste o(n)
//Parámetros:
//Entrada: key de tipo K
//Entrada/salida: c de tipo coleccion
template <typename K, typename D>
bool existe(const coleccion<K,D> &c, K key);

//Si no existe una terna con clave key, actualiza la colección 
//resultado de añadir en la colección una terna (k,data,rp). Si la terna 
//ya existe la coleccion queda igual 
//En el peor de los casos tiene coste o(n)
//Parámetros:
//Entrada: key de tipo K, data de tipo D y rp de tipo int
//Entrada/salida: c de tipo coleccion
template <typename K, typename D>
bool introducir( coleccion<K,D> &c,K key,D data, int rp );

//Si existe una terna con clave key y repeticiones = n entonces el valor de
//repeticones de la terna pasa a valer n+1, en caso contrario la colección
//no cambia, el valor de repeticiones se actualiza
//En el peor de los casos tiene coste o(n)
//Parámetros:
//Entrada: key de tipo K
//Entrada/salida: c de tipo coleccion
template <typename K, typename D>
void agnadirRep(coleccion<K,D> &c,K key);

//Si existe una terna con clave key y repeticiones = n entonces el valor de
//repeticones de la terna pasa a valer n-1 (si repeteciones pasa a valer 0 la terna se elimina),
//en caso contrario la colección no cambia, el valor de repeticiones se actualiza
//En el peor de los casos tiene coste o(n)
//Parámetros:
//Entrada: key de tipo K
//Entrada/salida: c de tipo coleccion
template <typename K, typename D>
void quitarRep(coleccion<K,D> &c,K key);

//Si en la colección existe una terna con clave key entonces se 
//devueva una coleccion igual eliminando la terna con dicha clave
//y actualizando los valores de num y reps
//En el peor de los casos tiene coste o(n)
//Parámetros:
//Entrada: key de tipo K
//Entrada/salida: c de tipo coleccion
template <typename K, typename D>
void eliminar(coleccion<K,D> &c,K key);

//Si en la colección existe una terna con clave key entonces 
// data es igual a los datos de la terna y rp a las repeticiones de la misma
//En el peor de los casos tiene coste o(n)
//Parámetros:
//Entrada: key de tipo K
//Entrada/salida: c de tipo coleccion
//Salida: data de tipo D, rp de tipo int
template <typename K, typename D>
bool obtenerInfo(coleccion<K,D> &c, K key, D &data, int &rp);

//devuelve el numero de ternas de la colección
//Coste constante: o(1)
//Parámetros:
//Entrada/salida: c de tipo coleccion
//Salida:  num de tipo int
template <typename K, typename D>
void numClaves(coleccion<K,D> &c, int &num);

//Devuelve el valor de la suma, de todas las repeticiones 
// de todas las ternas de la colección
//Coste constante: o(1)
//Parámetros:
//Entrada/salida: c de tipo coleccion
//Salida:  card de tipo int
template <typename K, typename D>
void numCardinal(coleccion<K,D> &c, int &card);

//definir operaciones del iterdador de la colecion:
//–––––––––––––––––––––––––––––––––––––––––––––––––

//Inicializa el iterador para recorrer llas ternasde la colección, 
//de forma que la siguiente terna sea el primero a visitar 
//(situación de no haber visitado ninguna terna).
//En el peor de los casos tiene coste o(n)
//Parámetros:
//Entrada/salida: c de tipo coleccion
template <typename K, typename D>
void iniciarIterador(coleccion<K,D> &c);

//Devuelve true si y sólo si queda alguna terna por visitar con el iterador de la colección c
//Parámetros:
//Entrada: c de tipo coleccion
//Coste constante: o(1)
template <typename K, typename D>
bool existeSiguiente(coleccion<K,D> &c);

//Devuelve la clave, dato y  natural (número de repeticiones)
// del siguiente terna a visitar de la coleccion. 
//Parcial: la operación no está definida si ya se ha visitado la última terna.
//Coste constante: o(1)
//Parámetros:
//Entrada: c de tipo coleccion
//Salida: key de tipo K, data de tipo D, rp de tipo int
template <typename K, typename D>
bool siguienteNodo(coleccion<K,D> &c, K &key, D &data, int &rp);


//Prepara el iterador para visitar la siguiente terna de la colección 
//Parcial: la operación no está definida si ya se ha visitado la última terna
//En el peor de los casos tiene coste o(n)
//Parámetros:
//Entrada/salida: c de tipo coleccion
template <typename K, typename D>
bool avanza(coleccion<K,D> &c);

//fin de interfaz


/***********************************************
    *––––––––––––––––––––––––––––––––––––––––––
    *EMPIEZA LA PARTE PRIVADA
    *––––––––––––––––––––––––––––––––––––––––––
***********************************************/
//Funciones auxiliares
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
    //La colección estará implementada mediante un tipo coleccion que 
    //esta compuesta por un ABB, donde se guardarán las ternas en sus nodos
    //cada nodo tendra una terna, he hijo izquiera y derecho,
    //los hijos izqierdos tendrán una terna con clave menor 
    // y los hijos derechos tendran una terna con clave mayor.
    //
    //el tipo colección también tendrá dos datos de tipo 
    // int los cuales guardaran el valor equivalente al 
    //número de nodos (num) y al numerode repetciones totales
    // de todas las ternas de la colección (reps)
    // el tipo colección contará con una pila que se usará para
    //implementar el iterador

    

    //Se defie los nodos propios de la coleccion
    struct nodo
    {
        //Los nodos de la coleccion estan compuestos por la terna de valores
        //clave de tipo K, dato de tipo D y rep de tipo int
        //ademas contarán cons dos punteros a nodo para sus hijos izquierdo y derecho
        
        D dato;
        K clave;
        int rep;
        nodo *izq;
        nodo *der;

    };
        nodo *raiz;//primer elemento
        int reps;//suma de repeteciones de todos los nodos
        int num;//numero de nodos
        pila < typename coleccion<K, D>::nodo *> pl;//pila de punteros a nodo usada en el iterador

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

//Crea una colección c vacía 
//Coste constante en tiempo: o(1)
template <typename K, typename D>
 void crear(coleccion<K,D> &c){

     c.reps = 0;
     c.num = 0;
     c.raiz = nullptr;
     crear(c.pl);

}

//devuelve true si y solo si existe un nodo con clave key
//en el arbol cuyo nodo raiz es a
//En el peor de los casos tiene coste o(n) en la altura
//Parámetros:
//Entrada: a de tipo puntero a nodo, key de tipo K
template <typename K, typename D>
bool existeR(typename coleccion<K, D>::nodo *a, K key)
{
    if(a == nullptr)return false;//caso no encontrado
    if(key < a->clave) return existeR<K, D>(a->izq,key);//buscar en subarbol de menores
    if(key == a->clave) return true;//encontrado
    else return existeR<K, D>(a->der,key);//buscar por el subarbol derecho

}

//devuelve true si y solo si existe un nodo con clave key
//en el arbol
//En el peor de los casos tiene coste o(n) en la altura
//Parámetros:
//Entrada: key de tipo K
//Entrada/salida: c de tipo coleccion
template <typename K, typename D>
bool existe(const coleccion<K,D> &c, K key)
{

    return existeR<K,D>(c.raiz,key);
    
}

//Si no existe un nodo con clave key, actualiza el arbol cuya raiz es a
//resultado de añadir el nodo con clave k dato data y rep rp. Si el nodo
//ya existe devuelve false
//En el peor de los casos tiene coste o(n) en la altura
//Parámetros:
//Entrada: a de tipo nodo, key de tipo K,data de tipo D, rp de tipo int
template <typename K, typename D>
bool introducirR(typename coleccion<K, D>::nodo*& a, K key, D data, int rp){
    
    if(a == nullptr)//si no esta en el arbol introducir
    {
        a =  new typename coleccion<K, D>::nodo;
        a->izq= nullptr;
        a->der = nullptr;
        a->dato = data;
        a->clave = key;
        a->rep = rp;
        return true;
    }
      
    
    if(key < a->clave)//buscar por el subarbol izquierdo
    {
        return introducirR<K, D>(a->izq,key,data,rp);
    }

    if(key == a->clave)//si está en el arbol devolver false
    {
        return false;
    }

    else //buscar por el subarbol derecho
    {
        return introducirR<K, D>(a->der,key,data,rp);
    }


}




//Si no existe un nodo con clave key, actualiza el arbol
//resultado de añadir el nodo con clave k dato data y rep rp.
//Si el nodo  ya existe la coleccion queda igual 
//En el peor de los casos tiene coste o(n)
//Parámetros:
//Entrada: key de tipo K, data de tipo D y rp de tipo int
//Entrada/salida: c de tipo coleccion
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


//Si existe un nodo en el arbol cuya raiz es a y repeticiones = n 
//entonces el valor de repeticones del nodo pasa a valer n+1, en caso contrario la colección
//no cambia, el valor de repeticiones se actualiza
//En el peor de los casos tiene coste o(n) en la altura
//Parámetros:
//Entrada: key de tipo K y a de tipo puntero a nodo 
//Entrada/salida: a de tipo puntero a nodo 
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
//no cambia, el valor de repeticiones se actualiza
//En el peor de los casos tiene coste o(n) en la altura
//Parámetros:
//Entrada: key de tipo K
//Entrada/salida: c de tipo coleccion
template <typename K, typename D>
void agnadirRep(coleccion<K,D> &c, K key)
{
    if(agnadirRepR<K, D>(c.raiz,key)) c.reps++;
}



//Si existe un nodo con clave key en el abb cuya raiz es a y repeticiones = n entonces el valor de
//repeticones del nodo pasa a valer n-1 (si repeteciones pasa a valer 0 la terna se elimina),
//en caso contrario la colección no cambia, el valor de repeticiones se actualiza
//En el peor de los casos tiene coste o(n) en la altura
//Parámetros:
//Entrada: key de tipo K 
//Entrada/salida: a de tipo puntero a nodo 
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
//repeticones del nodo pasa a valer n-1 (si repeteciones pasa a valer 0 se elimina el nodo),
//en caso contrario la colección no cambia, el valor de repeticiones se actualiza
//En el peor de los casos tiene coste o(n) en la altura
//Parámetros:
//Entrada: key de tipo K
//Entrada/salida: c de tipo coleccion
template <typename K, typename D>
void quitarRep(coleccion<K, D> & c, K key)
{
    if(quitarRepR<K, D>(c,c.raiz,key)){
        c.reps--;
    }
  
    
}


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



//Si en el abb cuya raiz es a existe un nodo con clave key entonces se 
//devueve el arbol igual eliminando el nodo con dicha clave
//y actualizando los valores de num y reps
//En el peor de los casos tiene coste o(n) en la altura
//Parámetros:
//Entrada: key de tipo K
//Entrada/salida: a de tipo puntero a nodo
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

//Si en c existe un nodo con clave key entonces se 
//devueve la coleccion igual eliminando el nodo con dicha clave
//y actualizando los valores de num y reps
//En el peor de los casos tiene coste o(n) en la altura
//Parámetros:
//Entrada: key de tipo K
//Entrada/salida: c de tipo coleccion
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

//Si en el abb cuya raiz es a existe un nodo con clave key entonces 
// data es igual a los datos del nodo y rp a las repeticiones del mismo
//En el peor de los casos tiene coste o(n) en la altura
//Parámetros:
//Entrada: key de tipo K y a de tipo puntero a nodo
//Salida: data de tipo D, rp de tipo int
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


//Si en c existe un nodo con clave key entonces 
// data es igual a los datos del nodo y rp a las repeticiones del mismo
//En el peor de los casos tiene coste o(n) en la altura
//Parámetros:
//Entrada: key de tipo K
//Entrada/salida: c de tipo coleccion
//Salida: data de tipo D, rp de tipo int
template <typename K, typename D>
bool obtenerInfo(coleccion<K,D> &c, K key, D &data, int &rp)
{
    return obtenerInfoR<K, D>(c.raiz, key, data, rp);
}

//devuelve el numero nodos de arbol
//Coste constante: o(1)
//Parámetros:
//Entrada/salida: c de tipo coleccion
//Salida:  num de tipo int
template <typename K, typename D>
void numClaves(coleccion<K,D> &c, int &num)
{
     num = c.num;
}

//Devuelve el valor de la suma, de todas las repeticiones 
// de todas los nodos del arbol
//Coste constante: o(1)
//Parámetros:
//Entrada/salida: c de tipo coleccion
//Salida:  card de tipo int
template <typename K, typename D>
void numCardinal(coleccion<K,D> &c, int &card)
{
   
    card = c.reps;
}

//implementar operaciones del iterdador de la colecion:
//–––––––––––––––––––––––––––––––––––––––––––––––––


//Inicializa el iterador para recorrer los nodos del arbol, 
//de forma que 
//(situación de no haber visitado ninguna terna).
//En el peor de los casos tiene coste o(n) en la altura
//Parámetros:
//Entrada/salida: c de tipo coleccion
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




//Devuelve true si y sólo si queda algun nodo por visitar con el iterador de la colección c
//Parámetros:
//Entrada: c de tipo coleccion
//Coste constante: o(1)
template <typename K, typename D>
bool existeSiguiente(coleccion<K,D> &c)
{
    return !empty(c.pl); //Hay siguiente dato en la pila
}

//Devuelve la clave, dato y  natural (número de repeticiones)
// del siguiente nodo a visitar del arbol. 
//Parcial: la operación no está definida si ya se ha visitado la último nodo.
//Coste constante: o(1)
//Parámetros:
//Entrada: c de tipo coleccion
//Salida: key de tipo K, data de tipo D, rp de tipo int
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

//Prepara el iterador para visitar el siguiente nodo  del arbol
//Parcial: la operación no está definida si ya se ha visitado el ultimo nodo
//En el peor de los casos tiene coste o(n) en la altura
//Parámetros:
//Entrada/salida: c de tipo coleccion
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
