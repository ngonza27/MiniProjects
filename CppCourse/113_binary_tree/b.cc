#include <iostream>
#include <stdlib.h>

using namespace std;

struct Node {
    int data;
    Node *izq;
    Node *der;
    Node *padre;
};

Node *createNode(int, Node *);
void insertNode(Node *&, int, Node *);
void show_tree(Node *, int);
bool search_in_tree(Node *, int);
void preOrden(Node *);
void inOrden(Node *);
void postOrden(Node *);
void delete_node(Node *, int);
void delete_current_node(Node *);
Node *min_left(Node *); 
void replace_node(Node *, Node *);
void destroy_node(Node *);

Node *arbol = NULL;

//depth search:
/*
    inorden -> arbol izquierdo, raiz, arbol derecho
    preorden -> raiz, arbol izquierdo, arbol derecho
    postorden -> arbol izquierdo, arbol derecho, raiz
*/

int main(){

    int n1 = 10, n2 = 8, cont = 0;
    insertNode(arbol, 10, NULL);
    insertNode(arbol, 8, NULL);
    insertNode(arbol, 9, NULL);
    insertNode(arbol, 5, NULL);
    insertNode(arbol, 4, NULL);
    insertNode(arbol, 15, NULL);
    insertNode(arbol, 20, NULL);

    show_tree(arbol, cont);

    //bool found_in_tree = search_in_tree(arbol, 10);
    //cout << "Lo encontro en el arbol? " << found_in_tree << endl;

    //preOrden(arbol);
    //inOrden(arbol);
    postOrden(arbol);

    delete_node(arbol,5);
    cout << endl;
    postOrden(arbol);

    return 0;
}

Node *createNode(int n, Node *padre){
    Node *newNode = new Node();

    newNode->data = n;
    newNode->izq = NULL;
    newNode->der = NULL;
    newNode->padre = padre;

    return newNode;
}

void insertNode(Node *&arbol, int n, Node *padre){
    if(arbol == NULL){
        Node *newNode = createNode(n, padre);
        arbol = newNode;
    } else {
        int valRaiz = arbol->data;
        if(n < valRaiz){
            insertNode(arbol->izq, n, arbol);        
        } else {
            insertNode(arbol->der, n, arbol);
        }
    }
}

void show_tree(Node *arbol, int cont){
    if(arbol == NULL){
        return;
    } else {
        show_tree(arbol->der,cont+1);
        for(int i =0; i < cont; i++){
            cout << "   ";
        }
        cout << arbol->data << endl;
        show_tree(arbol->izq, cont+1);
    }
}

bool search_in_tree(Node *arbol, int n){
    if(arbol == NULL){
        return false;
    } else if (arbol->data == n) {
        return true;
    } else if(n < arbol->data){
        return search_in_tree(arbol->izq, n);
    } else {
        return search_in_tree(arbol->der, n);
    }
}

void preOrden(Node *arbol) {
    if(arbol == NULL){
        return;
    } else {
        cout << arbol->data << "-";
        preOrden(arbol->izq);
        preOrden(arbol->der);
    }
}

void inOrden(Node *arbol) {
    if(arbol == NULL){
        return;
    } else {
        inOrden(arbol->izq);
        cout << arbol->data << "-";
        inOrden(arbol->der);
    }
}

void postOrden(Node *arbol) {
    if(arbol == NULL){
        return;
    } else {
        postOrden(arbol->izq);
        postOrden(arbol->der);
        cout << arbol->data << "-";
    }
}

void delete_node(Node *arbol, int n){
    if(arbol == NULL){
        return;
    } else if (n < arbol->data){
        delete_node(arbol->izq, n);
    } else if (n > arbol->data){
        delete_node(arbol->der, n);
    } else {
        delete_current_node(arbol);
    }
}

void delete_current_node(Node *deleteNode){
    if(deleteNode->izq && deleteNode->der){
        Node *min = min_left(deleteNode->der);
        deleteNode->data = min->data;
        delete_current_node(min); 
    } else if (deleteNode->izq) {
        replace_node(deleteNode, deleteNode->izq);
        destroy_node(deleteNode);
    } else if (deleteNode->der) {
        replace_node(deleteNode, deleteNode->der);
        destroy_node(deleteNode);
    } else {
        replace_node(deleteNode, NULL);
        destroy_node(deleteNode);
    }
}

Node *min_left(Node *arbol) {
    if(arbol == NULL){
        return NULL;
    }
    if(arbol->izq){
        return min_left(arbol->izq);
    } else {
        return arbol;
    }
}

void replace_node(Node *arbol, Node *newNode) {
    if(arbol->padre){
        if(arbol->data == arbol->padre->izq->data){
            arbol->padre->izq = newNode;
        }
        if(arbol->data == arbol->padre->der->data){
            arbol->padre->der = newNode;
        }
    }
    if(newNode){
        newNode->padre = arbol->padre;
    }
}

void destroy_node(Node *node){
    node->izq  = NULL;
    node->der = NULL;
    delete node;
}
