#ifndef ARBOL_H
#define ARBOL_H

#include "Nodo.h"

class Arbol
{
private:
    Nodo *root;    
public:
    Arbol();
    Arbol(Nodo &r);
    void pre_order(Nodo *nodo_actual);
    void in_order(Nodo *nodo_actual);
    void pos_order(Nodo *nodo_actual);
    Nodo*& get_root();

    void insert(Nodo *&nodo_actual, const int &v);
    void balance(Nodo *&raiz, int v);
    void update(Nodo *&raiz);
    Nodo* left_left(Nodo *&raiz);
    void left_right(Nodo *&raiz);
    Nodo* right_right(Nodo *&raiz);
    void right_left(Nodo *&raiz);
    void draw(Nodo *raiz, int x, int y, char l, int h);
};

#endif //ARBOL_H