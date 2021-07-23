#include <iostream>
#include <stdlib.h>

using namespace std;

struct Node {
    int data;
    Node *next;
};

void add_to_queue(Node *&, Node *&, int);
void remove_from_queue(Node *&, Node *&);
bool queueIsEmpty(Node *);

int main(){
    Node *front = NULL;
    Node *end = NULL;

    int n1 = 7, n2 = 9;

    add_to_queue(front,end,n1);
    add_to_queue(front,end,n2);

    cout << front->data << endl;
    cout << end->data << endl;

    cout << "Delete" << endl;
    remove_from_queue(front, end);
    cout << front->data << endl;
    cout << end->data << endl;

    return 0;
}


void add_to_queue(Node *&front, Node *&end, int n){
    Node *aux = new Node();
    aux->data = n;
    aux->next = NULL;
    if(queueIsEmpty(front)){
        front = aux;
    } else {
        end->next = aux;
    }
    end = aux;
}

void remove_from_queue(Node *& front , Node *& end){
    Node *aux = new Node();

    if(front == end){
        front = NULL;
        end = NULL;
    } else {
        front = front->next; 
    }
    delete aux;
}

bool queueIsEmpty(Node *front){
    return front == NULL ? true : false;
}
