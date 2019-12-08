#ifndef PILA_H
#define PILA_H

//Los valores del TAD pila representan secuencias 
//de elementos con acceso LIFO (last in, first out), 
//esto es, el último elemento en ser añadido (entrar) será 
//el primero en ser borrado (salir)
template <typename D>
struct pila;

//definir operaciones de pila:
//––––––––––––––––––––––––––––––––––


//Devuelve una pila vacia sin elementos 
template <typename D>
void crear(pila<D> &p);


//Devuelve verdad si y solo si p no tiene elemntos
template <typename D>
bool empty(pila<D> &p);


//Devuelve la pila resultante de añadir e a p
template <typename D>
void push(pila<D> &p);

//DEvuelve la pila resultante al eliminar el último elemento
//que fue apilado, si p es es vacia la devuelve igual
template <typename D>
void pop(pila<D> &p);

//Devuelve el último elemento apilado
//Parcial, operacion no definida para pila vacia
template <typename D>
bool top(pila<D> &p);

template <typename D>
struct pila{

    friend void crear<D>(pila<D> &p);
    friend bool empty<D>(pila<D> &p);
    friend void push<D>(pila<D> &p);
    friend void pop<D>(pila<D> &p);
    friend bool top<D>(pila<D> &p);

private:
    struct nodo
    {
        //ATRIBUTOS
        //cada elemento de la pila contiene un dato
        // y la dirección del nodo anterior
        D dato;
        nodo *down;
        };
};

//Devuelve una pila vacia sin elementos
template <typename D>
void crear(pila<D> &p)
{
    
}

//Devuelve verdad si y solo si p no tiene elemntos
template <typename D>
bool empty(pila<D> &p)
{

}

//Devuelve la pila resultante de añadir e a p
template <typename D>
void push(pila<D> &p)
{

}

//DEvuelve la pila resultante al eliminar el último elemento
//que fue apilado, si p es es vacia la devuelve igual
template <typename D>
void pop(pila<D> &p)
{

}

//Devuelve el último elemento apilado
//Parcial, operacion no definida para pila vacia
template <typename D>
bool top(pila<D> &p)
{

}

#endif // !PILA_H