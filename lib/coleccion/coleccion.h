/************************************************
 Autores:
 Íñigo Aréjula Aísa 785370
 Marcos Hernando Ibáñez 778053
 

 
 
*************************************************/

#ifndef COLECCION_H
#define COLECCION_H

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
template <typename D,typename K> 
void crear(coleccion<D, K> &c);


//devuelve true si y solo si existe un nodo con clave key
//en la coleccion
template <typename D, typename K>
bool existe(const coleccion<D,K> &c, K key);

#warning DOC INTRODUCIR
template <typename D, typename K>
bool introducir( coleccion<D,K> &c,K key,D data, int rep );

//Si existe un nodo con clave key y repeticiones = n entonces el valor de
//repeticones del nodo pasa a valer n+1, en caso contrario la colección
//no cambia, el valor de reps se actualiza
template <typename D, typename K>
void agnadirRep(coleccion<D,K> &c,K key);

#warning DOC QUITARREPS
template <typename D, typename K>
void quitarRep(coleccion<D,K> &c,K key);

//Si en la colección existe un nodo con clave key entonces se 
//devueva una coleccion igual eliminando el nodo con dicha clave
//y actualizando los valores de num y reps
template <typename D, typename K>
void eliminar(coleccion<D,K> &c,K key);

#warning DOC QUITARREPS
template <typename D, typename K>
bool obtenerInfo(coleccion<D, K> &c, K key, D &data, int &rep);

//devuelve el numero de nodos de la colección
template <typename D, typename K>
void numClaves(coleccion<D, K> &c, int &num);

//Devuelve el valor de la suma, para todos los nodos 
//(clave, dato,rep) en la colección c, de la tercera componente, rep.
template <typename D, typename K>
void numCardinal(coleccion<D, K> &c, int &card);

//definir operaciones del iterdador de la colecion:
//–––––––––––––––––––––––––––––––––––––––––––––––––

//Inicializa el iterador para recorrer los nodos de la colección c, 
//de forma que el siguiente nodo sea el primero a visitar 
//(situación de no haber visitado ningun nodo).
template <typename D, typename K>
void iniciarIterador(coleccion<D, K> &c);

#warning DOC EXISTESIG
template <typename D, typename K>
bool existeSiguiente(coleccion<D, K> &c);

//Devuelve la clave, dato y  natural (número de repeticiones)
// del siguiente nodo a visitar de c. 
//Parcial: la operación no está definida si ya se ha visitado la última terna.

template <typename D, typename K>
bool siguienteNodo(coleccion<D, K> &c, K &key, D &data, int &rep);

#warning DOC AVANZA
template <typename D, typename K>
bool avanza(coleccion<D, K> &c);

//fin de interfaz
// Declaración:
//–––––––––––––

template <typename D, typename K>
struct coleccion{

    friend void crear<D, K>(coleccion<D , K> &c);
    friend bool existe<D, K>(const coleccion<D, K> &c, K key);
    friend bool introducir<D, K>(coleccion<D, K> &c, K key, D data, int rep);
    friend void agnadirRep<D,K>(coleccion<D, K> &c, K key);
    friend void quitarRep<D, K>(coleccion<D, K> &c, K key);
    friend void eliminar<D,K>(coleccion<D, K> &c, K key);
    friend bool obtenerInfo<D, K>(coleccion<D, K> &c, K key, D &data, int &rep);
    friend void numClaves<D, K>(coleccion<D, K> &c, int &num);
    friend void numCardinal<D, K>(coleccion<D, K> &c, int &card);
    friend void iniciarIterador<D, K>(coleccion<D, K> &c);
    friend bool existeSiguiente<D, K>(coleccion<D, K> &c);
    friend bool siguienteNodo<D, K>(coleccion<D, K> &c, K &key, D &data, int &rep);
    friend bool avanza<D, K>(coleccion<D, K> &c);

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
         nodo *index;//puntero auxiliar para el iterador
        

        
};

//implementar operaciones de colecion:
//––––––––––––––––––––––––––––––––––


template <typename D, typename K>
 void crear(coleccion<D, K> &c){
  
  #warning IMPLEMENTAR CREAR
}

template <typename D, typename K>
bool existe(const coleccion<D, K> &c, K key){
    #warning IMPLEMENTAR EXISTE
}


template <typename D, typename K>
bool introducir(coleccion<D, K> &c, K key, D data, int rep){
#warning IMPLEMENTAR INTRODUCIR
}
    




template <typename D, typename K>
void agnadirRep(coleccion<D, K> &c, K key){
#warning IMPLEMENTAR AGNADIRREP
}


template <typename D, typename K>
void quitarRep(coleccion<D, K> &c, K key){
#warning IMPLEMENTAR QUITARREP
}


template <typename D, typename K>
void eliminar(coleccion<D, K> &c, K key){
#warning IMPLEMENTAR ELIMINAR
}

template <typename D, typename K>
bool obtenerDato(coleccion<D, K> &c, K key, D &data, int &rep)
{
#warning IMPLEMENTAR OBTENERINFO
}


template <typename D, typename K>
void numClaves(coleccion<D, K> &c, int &num){
#warning IMPLEMENTAR NUMCLAVES
}


template <typename D, typename K>
void numCardinal(coleccion<D, K> &c, int &card){
#warning IMPLEMENTAR NUMCARDINAL
}

//implementar operaciones del iterdador de la colecion:
//–––––––––––––––––––––––––––––––––––––––––––––––––


template <typename D, typename K>
void iniciarIterador(coleccion<D, K> &c){
#warning IMPLEMENTAR INICIARITERADOR
}


template <typename D, typename K>
bool existeSiguiente(coleccion<D, K> &c){
#warning IMPLEMENTAR EXISTESIGUIENTE
}

template <typename D, typename K>
bool siguienteClave(coleccion<D, K> &c, K &key){
#warning IMPLEMENTAR SIGUIENTECLAVE
}

template <typename D, typename K>
bool siguienteDato(coleccion<D, K> &c, D &data){
#warning IMPLEMENTAR SIGUIENTEDATO
}

template <typename D, typename K>
bool siguienteNumero(coleccion<D, K> &c, int &rep){
#warning IMPLEMENTAR CSIGUIENTENUMERO
}

template <typename D, typename K>
bool avanza(coleccion<D, K> &c){
#warning IMPLEMENTAR AVANZA
}

#endif // !COLECCION_H

