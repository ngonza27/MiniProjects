#include <iostream>
#include <stdlib.h>

using namespace std;


void pedirDatos();
void mostrarMatriz(int **, int, int);

int **pmatriz, nfila, ncol;

int main(){
    pedirDatos();
    mostrarMatriz(pmatriz, nfila, ncol);

    //Liberar memoria
    for(int i=0; i < nfila; i++){
        delete[] pmatriz[i];
    }
    delete [] pmatriz;

    return 0;
}



void pedirDatos(){
    cout << "Ingrese numero de filas: "; cin >> nfila;
    cout << "Ingrese numero de columnas: "; cin >> ncol;
    pmatriz = new int*[nfila];

    for(int i = 0; i < nfila; i++){
        pmatriz[i] = new int[ncol];
    }

    for(int i = 0; i < nfila; i++){
        for(int j = 0; j < ncol; j++){
            cout << "Digite un numero [" << i << "] [" << j << "]" << endl;
            cin >> *(*(pmatriz+i)+j);
        }
    }
}


void mostrarMatriz(int **pmatriz, int nfila, int ncol){
cout << "La matriz que usted ingreso es: " <<endl;
   for(int i = 0; i < nfila; i++){
        for(int j = 0; j < ncol; j++){
            cout << *(*(pmatriz+i)+j) << " ";
        }
        cout << endl;
    }
}