#include <iostream>
#include <stdlib.h> //new and delete

using namespace std;

void pedirNotas();
int numCalificaciones, *calificacion;

int main(){
    pedirNotas();
    cout << "Notas ingresadas: " << endl;
    for(int i = 0; i < numCalificaciones; ++i){
        cout << "Nota: " << i+1  << " -> "<< calificacion[i] << endl;
    }
    delete[] calificacion; //liberando memoria
    return 0;
}


void pedirNotas(){
    cout << "Numero de calificaciones:"; cin >> numCalificaciones;
    calificacion = new int [numCalificaciones];

for(int i = 0; i < numCalificaciones; ++i){
        cout << "Ingrese una nota: "; cin >> calificacion[i];


    }
}