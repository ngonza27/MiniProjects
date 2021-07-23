#include <iostream>

using namespace std;

int main(){
    int numero;
    cout << "numero: "; cin >> numero;

    switch(numero){
        case 1: cout << "que man mas alto parce"<< endl; break;
        case 2: cout << "ale ps parce" << endl; break;
        default: cout << "solo se pueden numeros 1-2"; break;
    }
    return 0;
}