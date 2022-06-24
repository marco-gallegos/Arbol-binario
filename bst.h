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
    ~BinarySearchTree(){trim(root);}

    Nodo<DATO> *root;

    bool Empty(const Nodo<DATO> *nod);
    bool is_leaf(Nodo<DATO> *nod);

    bool Insert( DATO to_insert);
    bool is_in_tree(DATO to_search);
    //interfaz para del
    bool Delete(DATO a_borrar);
    bool Del(DATO a_borrar, Nodo<DATO> *actual, Nodo<DATO> *ant = NULL);


    void trim(Nodo<DATO> *nodo);

    void in_orden(void (* func)(DATO),Nodo<DATO> *nodo = NULL, bool root = true);

    int deepness();

    void iterate();
};

template<class DATO>  bool BinarySearchTree<DATO>::Empty(const Nodo<DATO> *nod)
{
    return nod==NULL;
}

template<class DATO>  bool BinarySearchTree<DATO>::is_leaf(Nodo<DATO> *nod){
    return (nod->der == NULL && nod->izq == NULL);
}

template<class DATO> bool BinarySearchTree<DATO>::Insert( DATO to_insert){
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

template<class DATO> bool BinarySearchTree<DATO>::is_in_tree(DATO to_search){
    Nodo<DATO> *it = this->head;
    while (it->valor != to_search) {
        if (to_search < it->valor) {
            if(it->izq != NULL)
                return false;
            it = it ->izq;
        }
        if (to_search < it->valor) {
            if(it->der != NULL)
                return false;
            it = it ->der;
        }
    }
    return true;
}


template<class DATO> bool BinarySearchTree<DATO>::Delete(DATO a_borrar){
    bool res = Del(a_borrar,this->root);
    return res;
}

template<class DATO> bool BinarySearchTree<DATO>::Del(DATO a_borrar,Nodo<DATO> *actual, Nodo<DATO> *ant ){

    Nodo<DATO> *aux = NULL,*anterior = ant,*it = actual;

    //si es la raiz y es hoja
    if(a_borrar == this->root->valor && is_leaf(this->root))
    {
        delete it;
        this->root = NULL;
        return true;
    }

    //buscamos el elemento
    while(it->valor != a_borrar){
        if(a_borrar < it->valor){
            if (it->izq == NULL) {
                return 0;
            }
            anterior=it;
            it = it->izq;
        }
        if(a_borrar > it->valor){
            if (it->der == NULL) {
                return 0;
            }
            anterior = it;
            it = it->der;
        }
    }

    //si es hoja solo se elimina
    if(is_leaf(it))
    {
        //eliminamos la referencia
        if(anterior->der == it)
        {
            anterior->der = NULL;
        }
        if(anterior->izq == it){
            anterior->izq = NULL;
        }
        //eliminamos it
        delete it;
        return true;
    }
    else{
        //aux guardara el valor dado que se intercambiara por un nodo hoja
        aux = it;
        //buscar el nodo mas a la izquierda del nodo derecho
        if (it->der != NULL) {
            it = it->der;
            while(it->izq != NULL){
                anterior = it;
                it = it->izq;
            }
        }
        //buscar el valor mas a la derecha del nodo izquierdo
        else
        {
            it = it->izq;
            while(it->der != NULL){
                anterior = it;
                it = it->der;
            }
        }
        swap(aux->valor,it->valor);
        Del(a_borrar,it,anterior);
    }

    return false;
}

template<class DATO> void BinarySearchTree<DATO>::trim(Nodo<DATO> *nodo)
{
    if(nodo){
        trim(nodo->izquierdo);
        trim(nodo->derecho);
        delete nodo;
        nodo = NULL;
    }
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

template<class DATO> void BinarySearchTree<DATO>::iterate(){
    Nodo<DATO> *it = this->root;
    int opc = 0;
    while(opc != 8){
        cout<<it->valor<<endl;
        cout<<"1 der\t2 izq\t\t8 exit"<<endl;
        cin>>opc;cin.ignore();
        switch (opc) {
        case 1:
            if(it->der != NULL){
                it = it->der;
            }
            else{
                cout<<"no hay "<<endl;
            }
            break;
        case 2:
            if(it->izq != NULL){
                it = it->izq;
            }
            else {
                cout<<"no hay "<<endl;
            }
            break;
        case 9:
            break;
        default:
            cout<<"opcion invalida";
            break;
        }
    }
}
