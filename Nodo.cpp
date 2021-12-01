#include "Nodo.h"

Nodo::Nodo()
{
    izq = der = nullptr;
    balance = height = 0;
}
Nodo::Nodo(int v)
{
    izq = der = nullptr;
    item = v;
    balance = height = 0;
}