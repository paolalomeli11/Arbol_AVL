#include "Menu.h"

using namespace std;

int main()
{
    size_t op, v;
    Arbol ABB;

    do{
        system("cls");

        cout << "\n\n\t1) Insert node";
        cout << "\n\t2) Show pre-order";
        cout << "\n\t3) Show in-order";
        cout << "\n\t4) Show pos-order";
        cout << "\n\t5) Draw tree";
        cout << "\n\t6) Salir";
        cout << "\n\n\t   Option: ";
        cin >> op;

        cout << "\n\n\t";

        switch (op)
        {
        case 1:
            process_1(ABB);
            break;
        case 2:
            process_2(ABB);
            break;
        case 3:
            process_3(ABB);
            break;
        case 4:
            process_4(ABB);
            break;
        case 5:
            process_5(ABB);
            break;
        case 6:
            cout << "\n\n\tAdios :)";
            break;
        default:
            break;
        }
    }while(op != 6);

    return 0;
}