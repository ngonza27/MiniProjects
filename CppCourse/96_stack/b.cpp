#include <iostream>
#include <stdlib.h>
using namespace std;


struct Nodo {
    int data;
    Nodo *next;
};

void add_stack(Nodo *&, int);
void remove_stack(Nodo *&, int &);

int main(){
    Nodo *pila = NULL;
    int n1 = 1223, n2 = 22;

    add_stack(pila, n1);
    add_stack(pila, n2);
    //add_stack(pila, n2);

    remove_stack(pila, n2);

    cout << pila->data << endl;
    cout << pila->next->data << endl;

    return 0;
}


void add_stack(Nodo *&pila, int n){
    Nodo *new_nodo = new Nodo();
    (*new_nodo).data = n;
    (*new_nodo).next = pila;
    pila = new_nodo;
}


void remove_stack(Nodo *& pila, int &n){
    Nodo *aux = pila;
    pila = aux->next;
    delete aux;
}