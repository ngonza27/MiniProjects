#include <iostream>

using namespace std;


void intercambio(float *, float *);

int main(){

    float n1 = 9.4, n2 = 5.5;

    cout << "N1: " << n1 <<endl;
    cout << "N2: " << n2 <<endl;

    intercambio(&n1, &n2);

    cout << "N1: " << n1 <<endl;
    cout << "N2: " << n2 <<endl;

    return 0;
}


void intercambio(float *dir1, float *dir2){
    float aux;

    aux = *dir1;
    *dir1 = *dir2;
    *dir2 = aux;
}