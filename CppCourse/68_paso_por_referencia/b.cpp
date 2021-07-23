#include <iostream>


using namespace std;


template <class T>
void imprimirNumero(T n);

int suma(int n1,int n2);
void valoresNuevos(int&, int&);

// & significa => direccion de (ej: estoy haciendo referencia a la direccion de memoria de la variable n1)
int main(){
    int n1 = 5, n2 = 4, n3 = 40;

    //paso de variable por valor !!!
    //int n3 = suma(n1, n2);
    imprimirNumero(n3);
    cout << n3 << endl;
    //valoresNuevos(n1, n2);

    cout << "Nuevo valor del primer numero es: " << n1 << " El nuevo valor dels segundo numero es: " << n2 << endl;
    return 0;
}

template <class T>
void imprimirNumero(T n) {
    cout << n << endl;
    n = 6;
    cout << "Imprimir numero: " << n << endl;
}

int suma(int n1, int n2){
    return n1+n2;
}

void valoresNuevos(int& xnum, int& ynum){
    cout << "El valor del primer numnero es: " << xnum << " El valro del segundo numero es: " << ynum << endl;

    xnum = 89;
    ynum = 70;
}