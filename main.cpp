#include <iostream>
#include "bst.h"

using namespace std;
void show_int(int to_show)
{
    cout<<to_show<<" - ";
    return;
}

int main()
{
    BinarySearchTree<int> *arbolint = new BinarySearchTree<int>();
    int opc = 0;
    int aux_int = 0;
    while(opc!=9)
    {
        cout<<"1 - insert\t2 - delete\t3 - inorden\t9-salir"<<endl;
        cin>>opc;cin.ignore();
        switch (opc) {
        case 1:
            cout<<"int to insert  -> ";
            cin>>aux_int;cin.ignore();
            arbolint->Insert(aux_int);
            break;
        case 2:
            break;
        case 3:
            arbolint->in_orden(show_int);
            cout<<endl;
            break;
        default:
            cout<<"invalido"<<endl;
            break;
        }
    }
    return 0;
}

