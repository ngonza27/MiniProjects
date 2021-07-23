#include <iostream>
#include <stdlib.h>

using namespace std;


struct Node {
    int data;
    Node *next;
};

void add_to_list(Node *&, int n);
void show_list(Node *);
void find_node(Node *, int);
void delete_from_list(Node *&, int n);
void reverse_list(Node *&);

Node *list = NULL;

int main(){
    add_to_list(list, 6);
    add_to_list(list, 7);
    add_to_list(list, 8);

    //find_node(list, 8);

    show_list(list);
    //delete_from_list(list, 7);
    //cout << "After delete" << endl;

    reverse_list(list);
    show_list(list);
    return 0;
}

void add_to_list(Node *& list, int n){
    Node *new_node = new Node();
    new_node->data = n;

    Node *aux1 = list, *aux2;

    //insert in order
    while((aux1 != NULL) && (aux1->data < n)){
        aux2 = aux1;
        aux1 = aux1->next;
    }

    if(list == aux1){
        list = new_node;        
    } else {
        aux2->next = new_node;
    }
    new_node->next = aux1;
}

void show_list(Node *list){
    Node *actual_node = list;
    while(actual_node != NULL){
        cout << actual_node->data << endl;
        actual_node = actual_node->next;
    }
}

void find_node(Node *list, int n){
    Node *actual_node = list;
    bool found = false;
    while(actual_node != NULL){
        if(actual_node->data == n){
            found = true;
        }
        actual_node = actual_node->next;
    }
    found ? cout << "Data " << n << " was found in the list" << endl : cout << "Data was not found" << endl;
}

void delete_from_list(Node *&list, int n){
    if(list != NULL){
        Node *aux = list;
        Node *prev = NULL;
        bool found = false;

        while((aux != NULL) && (aux->data != n)){
            prev = aux;
            aux = aux->next;
        }
        if(aux == NULL){
            cout << "Element not found" << endl;
        } else if (prev == NULL){ //primer elemento
            list = list->next;
            delete aux;
        } else {
            prev->next = aux->next;
            delete aux;
        }
    }

}

void reverse_list(Node *&list){
    Node *prev = NULL;
    while(list != NULL){
        Node *nextNode  = list->next;
        list->next = prev;
        prev = list;
        list = nextNode;
    }
    list = prev;
}