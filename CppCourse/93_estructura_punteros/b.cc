#include <iostream>

using namespace std;

struct Persona {
    char nombre[20];
    int edad;
} persona;

void pedirDatos();
Persona *ptr;

int main(){
    pedirDatos();
    
    cout << "nombre:" << (*ptr).nombre << endl;
    cout << ptr << endl;
    cout << "edad:" << (*ptr).edad << endl;
    
    return 0;
}

void pedirDatos(){
    ptr = &persona;
    cout << "ingrese nombre: "; cin >> (*ptr).nombre; //aca puntero_persona es la posicion de memoria
    cout << "ingrese su edad: "; cin >> (*ptr).edad;
}
