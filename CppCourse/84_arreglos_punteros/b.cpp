#include <iostream>


using namespace std;

int main(){
    int arr[] = {7,6,3,4,90};
    int *pointer;

    pointer = &arr[0]; //direccion de memoria inicial del vector
    //pointer = arr; //direccion de memoria inicial del vector
    cout << *pointer << endl;
    //las posiciones de memoria estan espaciadas de a 4 bytes (Cuando los numeros son enteros)
    for(int i = 0; i < 5; ++i){

        cout << "Elemento en la posicion [" << i << "] posicion de memoria: " << *pointer++ << endl;
    }

    return 0;
}