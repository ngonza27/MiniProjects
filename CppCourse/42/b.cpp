#include <iostream>
#include <string.h>


#include <stdlib.h> //atoi, stoi

using namespace std;

int main(){
    char a[] = "nicolas el alto";
    char b[2] = "a";
    char aa[] = "Hola";
    char bb[] = "Hola";

    cout << a << strlen(a)<< endl;
    cout << strlen(b)<< endl;

    //strcpy(b,a); copiar el strin B al string A

    //comparar si dos cadenas de caracteres son iguales, (iguales = 0, diferentes != 0)
    cout << "Los string son iguales? " << strcmp(aa,bb) << endl; 

    //concatenar dos cadenas de caracteres
    cout << strcat(b,bb) << endl;

    //partir una cadena de caracteres
    cout << a << " Splitted: " <<strtok(a, "a") << endl;

    //invertir una cadena de caracteres, strrev no existe en linux
    //cout << strrev(a) << endl;

    //cadena de caracteres a mayusculas, no existe en linux
    //cout << strupr(a) << endl;

    //cadena de caracteres a minusculas, no existe en linux
    //cout << strlwr(a) << endl;

    char num[] = "123.123";
    double numFromStr;

    numFromStr = atoi(num); //string to int
    //           atof(num)    string to float
    cout << numFromStr + 1 << endl;


    return 0;
}