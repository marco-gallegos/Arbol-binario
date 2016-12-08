#include<iostream>
#include<algorithm>

using namespace std;

template<class DATO> class Nodo
{
public:

    Nodo(DATO dat,Nodo<DATO> *iz = NULL, Nodo<DATO> *de = NULL): valor(dat), izq(iz), der(de){}
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

    Nodo<DATO> *root;

    bool Empty(const Nodo<DATO> *nod);
    bool Insert( DATO to_insert);
    bool is_in_tree(DATO to_search);


    void trim(DATO to_del);

    void in_orden(void (* func)(DATO),Nodo<DATO> *nodo = NULL, bool root = true);

    int deepness();
};

template<class DATO>  bool BinarySearchTree<DATO>::Empty(const Nodo<DATO> *nod)
{
    return nod==NULL;
}

template<class DATO> bool BinarySearchTree<DATO>::Insert( DATO to_insert)
{
    if (Empty(this->root)) {
        this->root = new Nodo<DATO>(to_insert);
        return true;
    }
    Nodo<DATO> *it = this->root;

    while(it->valor != to_insert) {
        if(to_insert < it->valor){

            if(it->izq == NULL){
                it->izq = new Nodo<DATO>(to_insert);
                return true;
            }

            it = it->izq;
        }

        if(to_insert > it->valor){

            if(it->der == NULL){

                it->der = new Nodo<DATO>(to_insert);
                return true;
            }
            it = it->der;
        }
        if(it->valor == to_insert)
        {
            return false;
        }
    }

    return false;
}

template<class DATO> void BinarySearchTree<DATO>::in_orden(void (* func)(DATO),Nodo<DATO> *nodo, bool root){
    if(root){
        nodo=this->root;
    }
    if(nodo->izq != NULL){
        in_orden(func ,nodo->izq,false);
    }
    func(nodo->valor);
    if(nodo->der != NULL){
        in_orden(func, nodo->der,false);
    }
}
