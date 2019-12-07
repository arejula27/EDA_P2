/************************************************
 Autores:
 Íñigo Aréjula Aísa 785370
 Marcos Hernando Ibáñez 778053
 

 
 
*************************************************/

#ifndef COLECCION_H
#define COLECCION_H

// Interfaz del TAD coleccion genérico. Pre-declaraciones:
#include <iostream>
const int MAX = 100; //Límite tamaño de la coleccion, en // esta implementación.

template <typename D,typename K>
struct coleccion;

//definir operaciones de colecion:
//––––––––––––––––––––––––––––––––––

//PRE:-
//POS:devuelve una coleccion vacia
template <typename D,typename K> 
void crear(coleccion<D, K> &c);
//PRE:-
//POS: existe=Existe una clave == key en c
template <typename D, typename K>
bool existe(const coleccion<D,K> &c, K key);

//PRE:-
//POS: si(!existe(c,key)) se añade la nueva nodo a coleccion, 
//  sino no se modifica
// devuelve false si c esta comleta 
template <typename D, typename K>
bool introducir( coleccion<D,K> &c,K key,D data, int rep );

//PRE: -
//POS: si (existe(c,key) -> se sustituye el nodo (k,data,rep) por (k,data,rep+1)
//      sino no se modifica
template <typename D, typename K>
void agnadirRep(coleccion<D,K> &c,K key);

//PRE: -
//POS: si (existe(c,key) -> se sustituye el nodo (k,data,rep) por (k,data,rep-1)
//      sino no se modifica
template <typename D, typename K>
void quitarRep(coleccion<D,K> &c,K key);

//PRE:-
//POS: si (existe(c,key) -> devuelve una collecion igual a la recibida
//      pero sin el nodo con clave key, en caso contrario devuelve la
//      colección igual
template <typename D, typename K>
void eliminar(coleccion<D,K> &c,K key);

//PRE: key->existe(c,key);
//POS: devuelve en data el dato con clave key
// (en caso de no cumplisrse la PRE se devolvera false)
template <typename D, typename K>
bool obtenerDato(coleccion<D,K> &c,K key,D &data);

//PRE: key->existe(c,key);
//POS: devuelve en rep el int con clave key
// (en caso de no cumplisrse la PRE se devolvera false)
template <typename D, typename K>
bool obtenerNumero(coleccion<D,K> &c,K key,int &rep);

//PRE: -
//POS: devuelve el numero de nodos en la coleccion c
template <typename D, typename K>
void numClaves(coleccion<D, K> &c, int &num);

//PRE: -
//POS: card= sumatorio de todas las componentes  rep da las 
//      nodos(key,data,rep)
template <typename D, typename K>
void numCardinal(coleccion<D, K> &c, int &card);

//definir operaciones del iterdador de la colecion:
//–––––––––––––––––––––––––––––––––––––––––––––––––

//PRE: -
//POS: se inicia un iterador
template <typename D, typename K>
void iniciarIterador(coleccion<D, K> &c);

//PRE: -
//POS: devuelve true si quedan nodos por visitar de la coleccion c
template <typename D, typename K>
bool existeSiguiente(coleccion<D, K> &c);

//PRE: c.existeSiguiente(c)
//POS: key = clave de la siguiente nodo a visitar de c
template <typename D, typename K>
bool siguienteClave(coleccion<D, K> &c, K &key);

//PRE: c.existeSiguiente(c)
//POS: data = dato de la siguiente nodo a visitar de c
template <typename D, typename K>
bool siguienteDato(coleccion<D, K> &c,D &data);

//PRE: c.existeSiguiente(c)
//POS: rep= natural de la siguiente nodo a visitar de c
template <typename D, typename K>
bool siguienteNumero(coleccion<D, K> &c, int &rep);

//PRE: c.existeSiguiente(c)
//POS: Prepara el iterador para visitar la siguiente nodo de la colección c
template <typename D, typename K>
bool avanza(coleccion<D, K> &c);

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
    friend bool obtenerDato<D, K>(coleccion<D, K> &c, K key, D &data);
    friend bool obtenerNumero<D, K>(coleccion<D, K> &c, K key, int &rep);
    friend void numClaves<D, K>(coleccion<D, K> &c, int &num);
    friend void numCardinal<D, K>(coleccion<D, K> &c, int &card);

    friend void iniciarIterador<D, K>(coleccion<D, K> &c);
    friend bool existeSiguiente<D, K>(coleccion<D, K> &c);
    friend bool siguienteClave<D, K>(coleccion<D, K> &c, K &key);
    friend bool siguienteDato<D, K>(coleccion<D, K> &c, D &data);
    friend bool siguienteNumero<D, K>(coleccion<D, K> &c, int &rep);
    friend bool avanza<D, K>(coleccion<D, K> &c);

    private: //declaración de la representación innodo del tipo:
        

        struct nodo
        {
            D dato;
            K clave;
            int reps;
            nodo *izq;
            nodo *der;
        };
         nodo *raiz;
         nodo *index;
        

        
};

//implementar operaciones de colecion:
//––––––––––––––––––––––––––––––––––


//PRE:-
//POS:devuelve una coleccion vacia

template <typename D, typename K>
 void crear(coleccion<D, K> &c){
  
  #warning IMPLEMENTAR CREAR
}

//PRE:-
//POS: existe=Existe una clave == key en c
template <typename D, typename K>
bool existe(const coleccion<D, K> &c, K key){
    #warning IMPLEMENTAR EXISTE
}

//PRE:-
//POS: si(!existe(c,key)) se añade la nueva nodo a coleccion,
//  sino no se modifica
// devuelve false si c esta completa
template <typename D, typename K>
bool introducir(coleccion<D, K> &c, K key, D data, int rep){
#warning IMPLEMENTAR INTRODUCIR
}
    



//PRE: -
//POS: si (existe(c,key) -> se sustituye el nodo (k,data,rep) por (k,data,rep+1)
//      sino no se modifica
template <typename D, typename K>
void agnadirRep(coleccion<D, K> &c, K key){
#warning IMPLEMENTAR AGNADIRREP
}

//PRE: -
//POS: si (existe(c,key) -> se sustituye el nodo (k,data,rep) por (k,data,rep-1)
//      sino no se modifica
template <typename D, typename K>
void quitarRep(coleccion<D, K> &c, K key){
#warning IMPLEMENTAR QUITARREP
}

//PRE:-
//POS: si (existe(c,key) -> devuelve una collecion igual a la recibida
//      pero sin el nodo con clave key, en caso contrario devuelve la
//      colección igual
template <typename D, typename K>
void eliminar(coleccion<D, K> &c, K key){
#warning IMPLEMENTAR ELIMINAR
}

//PRE: key->existe(c,key);
//POS: devuelve en data el dato con clave key
// (en caso de no cumplisrse la PRE se devolvera false)
template <typename D, typename K>
bool obtenerDato(coleccion<D, K> &c, K key, D &data){
#warning IMPLEMENTAR OBTENERDATO
}

//PRE: key->existe(c,key);
//POS: devuelve en rep el int con clave key
// (en caso de no cumplisrse la PRE se devolvera false)
template <typename D, typename K>
bool obtenerNumero(coleccion<D, K> &c, K key, int &rep){
#warning IMPLEMENTAR OBTENERNUMERO
}

//PRE: -
//POS: devuelve el numero de nodos en la coleccion c
template <typename D, typename K>
void numClaves(coleccion<D, K> &c, int &num){
#warning IMPLEMENTAR NUMCLAVES
}

//PRE: -
//POS: card= sumatorio de todas las componentes  rep de las
//      nodos(key,data,rep)
template <typename D, typename K>
void numCardinal(coleccion<D, K> &c, int &card){
#warning IMPLEMENTAR NUMCARDINAL
}

//implementar operaciones del iterdador de la colecion:
//–––––––––––––––––––––––––––––––––––––––––––––––––

//PRE: -
//POS: se inicia un iterador
template <typename D, typename K>
void iniciarIterador(coleccion<D, K> &c){
#warning IMPLEMENTAR INICIARITERADOR
}

//PRE: -
//POS: devuelve true si quedan nodos por visitar de la coleccion c
template <typename D, typename K>
bool existeSiguiente(coleccion<D, K> &c){
#warning IMPLEMENTAR EXISTESIGUIENTE
}

//PRE: c.existeSiguiente(c)
//POS: key = clave de la siguiente nodo a visitar de la coleccion c, devuelve false si no existe siguiente
template <typename D, typename K>
bool siguienteClave(coleccion<D, K> &c, K &key){
#warning IMPLEMENTAR SIGUIENTECLAVE
}

//PRE: c.existeSiguiente(c)
//POS: data = dato de la siguiente nodo a visitar de la coleccion c
template <typename D, typename K>
bool siguienteDato(coleccion<D, K> &c, D &data){
#warning IMPLEMENTAR SIGUIENTEDATO
}

//PRE: c.existeSiguiente(c)
//POS: rep= natural de la siguiente nodo a visitar de la coleccion c
template <typename D, typename K>
bool siguienteNumero(coleccion<D, K> &c, int &rep){
#warning IMPLEMENTAR CSIGUIENTENUMERO
}

//PRE: c.existeSiguiente(c)
//POS: Prepara el iterador para visitar la siguiente nodo de la colección c
template <typename D, typename K>
bool avanza(coleccion<D, K> &c){
#warning IMPLEMENTAR AVANZA
}

#endif // !COLECCION_H

