#include <iostream>
#include <conio.h>
#include <windows.h>
#include <math.h>

#include "Arbol.h"

using namespace std;

Arbol::Arbol()
{
    root = nullptr;
}
Arbol::Arbol(Nodo &r)
{
    root = &r;
}

void Arbol::pre_order(Nodo *raiz)
{
    if(raiz == nullptr)
        return;

    cout << raiz->item << " - ";
    pre_order(raiz->izq);
    pre_order(raiz->der);
}
void Arbol::in_order(Nodo *raiz)
{
    if(raiz == nullptr)
        return;

    in_order(raiz->izq);
    cout << raiz->item << " - ";
    in_order(raiz->der);   
}
void Arbol::pos_order(Nodo *raiz)
{
    if(raiz == nullptr)
        return;

    pos_order(raiz->izq);
    pos_order(raiz->der);
    cout << raiz->item << " - ";
}

Nodo*& Arbol::get_root()
{
    return root;
}

void Arbol::update(Nodo *&raiz)
{
    int lh, rh;
    lh = rh = -1;

    if(raiz->izq != nullptr)
        lh = raiz->izq->height;
    if(raiz->der != nullptr)
        rh = raiz->der->height;

    raiz->height = 1 + max(lh, rh);
    raiz->balance = rh - lh;
}

void Arbol::insert(Nodo *&raiz, const int &v)
{
    if(raiz == nullptr){
        Nodo *nodo_nuevo = new Nodo(v);
        raiz = nodo_nuevo;
        return;
    }
    if(v == raiz->item){
        cout << "\n\tNo se pudo realizar la accion.\n";
        return;
        getch();
    }
    else if(v < raiz->item)
        insert(raiz->izq, v);
    else
        insert(raiz->der, v);

    update(raiz);
    balance(raiz, v);
}

void Arbol::balance(Nodo *&raiz, int v)
{
    if(raiz->balance == -2){
        if(raiz->izq->balance <= 0){
            left_left(raiz);
        }
        else
        {
            left_right(raiz);
        }
    }
    else if(raiz->balance == 2){
        if(raiz->der->balance >= 0)
        {
            right_right(raiz);
        }
        else
        {
            right_left(raiz);
        }
        getch();
    }   
}

Nodo* Arbol::left_left(Nodo *&raiz)
{
    Nodo *B = raiz->izq;

    raiz->izq = B->der;
    B->der = raiz;

    update(raiz);
    update(B);

    raiz = B;

    return B;
}
void Arbol::left_right(Nodo *&raiz)
{
    raiz->izq = right_right(raiz->izq);
    left_left(raiz);
}
Nodo* Arbol::right_right(Nodo *&raiz)
{
    Nodo *B = raiz->der;

    raiz->der = B->izq;
    B->izq = raiz;

    update(raiz);
    update(B);

    raiz = B;

    return B;
}
void Arbol::right_left(Nodo *&raiz)
{
    raiz->der = left_left(raiz->der);
    right_right(raiz);
}

void gotoxy(int x, int y)
{
	HANDLE hCon;
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hCon, dwPos);
}

void Arbol::draw(Nodo *raiz, int x, int y, char l, int h)
{
    if(raiz == nullptr)
        return;
 
    size_t n = pow(2, raiz->height);
    size_t m = pow(2, h);

    if(l == 'l')
    {
        for(int i=x+1; i<x+m-1; i++){     //ACOMODAR PARA LA CANTIDAD DE DIGITOS
            gotoxy(i,y-2); printf("%c",196);
        }
        gotoxy(x,y-2);    printf("%c",218);
        gotoxy(x,y-1);    printf("%c",179);
    }
    else if(l == 'r'){
        for(int i=x-1; i>x-m+1; i--){   //ACOMODAR PARA LA CANTIDAD DE DIGITOS
            gotoxy(i,y-2); printf("%c",196);
        }
        gotoxy(x,y-2);    printf("%c",191);
        gotoxy(x,y-1);    printf("%c",179);
    }

    gotoxy(x,y);    cout << raiz->item;

    y = y+2;

    draw(raiz->izq, x-n, y, 'l',raiz->height);
    if(raiz->item > 9)
        draw(raiz->der, x+n+1, y, 'r',raiz->height);
    else
        draw(raiz->der, x+n, y, 'r',raiz->height); 
    
}