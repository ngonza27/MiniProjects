#include <iostream>

using namespace std;


/*
Punteros

&n -> la direccion de n
*n -> varaible que almacena una posicion de memoria en n

*/

int main(){

    int num  = 20, *dir_num;

    dir_num = &num;

    cout << "Numnero: " << *dir_num << endl;
    cout << "Direccion de memoria: " << dir_num << endl;
    return 0;
}
