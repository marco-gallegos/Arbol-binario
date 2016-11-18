#include<iostream>
#include<algorithm>

using namespace std;

template<class DATO> class Nodo
{
public:

    Nodo(DATO dat = NULL, iz = NULL, de = NULL): valor(dat), izq(iz), der(de){}
    ~Nodo(){}
    DATO valor;
    //izq(izquierda  left) der(derecha right)
    Nodo<DATO> *izq,*der;
};

template<class DATO> class BinarySearchTree
{
public:
    BinarySearchTree():root(NULL){}
    ~BinarySearchTree(){}

    DATO *root;

    bool insert(DATO to_insert);
    bool is_in_tree(DATO to_search);


    void trim(DATO to_del);

    int deepness();
};


