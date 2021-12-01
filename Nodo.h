#ifndef NODO_H
#define NODO_H

class Nodo
{
public:
    //METODOS
    Nodo();
    Nodo(int v);

    //ATRIBUTOS
    int getItem();
    int item;
    Nodo *izq, *der;
    int balance;
    int height;
};

#endif //NODO_H