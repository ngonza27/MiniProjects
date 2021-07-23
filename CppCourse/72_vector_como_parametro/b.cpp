#include <iostream>


using namespace std;

void cuadrados(int vec[],int);
void imprimirVector(int vec[],int);


int main(){
    const int tam = 5;
    int arr[tam] = {1,2,3,4,5};

    cuadrados(arr, tam);
    imprimirVector(arr, tam);

    return 0;
}



void cuadrados(int vec[], int tam){
    for(int i = 0; i < tam; ++i){
        vec[i] *= vec[i];
    }
}


void imprimirVector(int vec[], int tam){
    for(int i = 0; i < tam; ++i){
       cout << vec[i] << " " << endl;
    }
}