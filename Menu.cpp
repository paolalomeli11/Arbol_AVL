#include <iostream>
#include <conio.h>
#include <math.h>
#include "Arbol.h"

using namespace std;

void process_1(Arbol &ABB)
{
    system("cls");
    cout << "\n\n\t\tINSERT";
    cout << "\n\n\t(int) value: ";
    int v;
    cin >> v;
    
    ABB.insert(ABB.get_root(), v);   
}
void process_2(Arbol &ABB)
{
    system("cls");
    if(ABB.get_root() == nullptr){
        cout << "\n\n\tThere's nothing to show.";
        getch();
        return;
    }

    cout << "\n\n\t\tPRE-ORDER\n\n\t";
    ABB.pre_order(ABB.get_root());
    cout << "\b\b\b   ";
    getch();
}
void process_3(Arbol &ABB)
{
    system("cls");
    if(ABB.get_root() == nullptr){
        cout << "\n\n\tThere's nothing to show.";
        getch();
        return;
    }

    cout << "\n\n\t\tIN-ORDER\n\n\t";
    ABB.in_order(ABB.get_root());
    cout << "\b\b\b   ";
    getch();
}
void process_4(Arbol &ABB)
{
    system("cls");

    if(ABB.get_root() == nullptr){
        cout << "\n\n\tThere's nothing to show.";
        getch();
        return;
    }

    cout << "\n\n\t\tPOS-ORDER\n\n\t";
    ABB.pos_order(ABB.get_root());
    cout << "\b\b\b   ";
    getch();
}
void process_5(Arbol &ABB)
{
    system("cls");
    if(ABB.get_root() == nullptr){
        cout << "\n\n\tThere's nothing to show.";
        getch();
        return;
    }
    size_t m = pow(2, (ABB.get_root())->height) + 20;
    ABB.draw(ABB.get_root(), m, 3, 'm', ABB.get_root()->height);
    getch();
}
