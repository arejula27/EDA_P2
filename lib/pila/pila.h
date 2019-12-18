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


//Devuelve verdad si y solo si p no tiene elementos
template <typename D>
bool empty(pila<D> &p);


//Devuelve la pila resultante de apilar data en p
template <typename D>
void push(pila<D> &p, D data);

//DEvuelve la pila resultante al eliminar el último elemento
//que fue apilado, si p es es vacia la devuelve igual
template <typename D>
void pop(pila<D> &p);

//Devuelve el último elemento apilado
//Parcial, operacion no definida para pila vacia
template <typename D>
bool top(pila<D> &p,D &data);

//Devuelve  el número de elementos de la pila 
template <typename D>
int size(pila<D> &p);

//Devuelve  la pila vacia
template <typename D>
void clear(pila<D> &p);

template <typename D>
struct pila{
    // La pila contará con un nodo guardian, siendo
    // este siempre el que se encuentre en la posición 
    // más baja, icluso en la sitacion de pila vacia

    friend void crear<D>(pila<D> &p);
    friend bool empty<D>(pila<D> &p);
    friend void push<D>(pila<D> &p, D data);
    friend void pop<D>(pila<D> &p);
    friend bool top<D>(pila<D> &p, D &data);
    friend int size<D>(pila<D> &p);
    friend void clear<D>(pila<D> &p);

private:

    struct nodo
    {
        //ATRIBUTOS
        //cada elemento de la pila contiene un dato
        // y la dirección del nodo anterior
        D dato;
        nodo *down;
        };

        int len;
        nodo * top;
};

//Devuelve una pila vacia sin elementos
template <typename D>
void crear(pila<D> &p)
{
    p.top = new typename pila<D>::nodo;
    p.top->down = nullptr;
    p.len =0;
}

//Devuelve verdad si y solo si p no tiene elementos
template <typename D>
bool empty(pila<D> &p)
{
    return p.len? false:true;
}

//Devuelve la pila resultante de añadir data a p
template <typename D>
void push(pila<D> &p, D data)
{   
    typename pila<D>::nodo *aux = p.top;
    p.top = new typename pila<D>::nodo;
    p.top->down = aux; 
    p.len++;
    p.top->dato = data;
}

//Devuelve la pila resultante al eliminar el último elemento
//que fue apilado, si p es es vacia la devuelve igual
template <typename D>
void pop(pila<D> &p)
{
    if(p.len>0)
    {
        typename pila<D>::nodo *aux = p.top;
        p.top = p.top->down;
        delete aux;
        p.len--;
    }
   
}

//Devuelve el último elemento apilado
//Parcial, operacion no definida para pila vacia
template <typename D>
bool top(pila<D> &p,D &data)
{
    if (p.len>0)
    {
        data = p.top->dato;
        return true;
    }
    return false;
    
    
}

//Devuelve  el número de elementos de la pila
template <typename D>
int size(pila<D> &p)
{
    return p.len;
}

//Devuelve  la pila vacia
template <typename D>
void clear(pila<D> &p){

    while (p.len>0)
    {
        pop(p);
    }
    

}

#endif // !PILA_H