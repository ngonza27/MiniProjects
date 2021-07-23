#include <iostream>


using namespace std;

void calcular(int, int, int&, int&);

int main(){
    int num1 = 4, num2 = 5, suma, mult; 

    calcular(num1,num2,suma,mult);

    cout << "Valor suma: "<< suma << " Valor mult: " << mult << endl;
    return 0;
}


void calcular(int n1, int n2, int& suma, int& mult){
    suma  = n1 + n2;
    mult  = n1 * n2;
}
