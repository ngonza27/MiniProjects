#include <iostream>

using namespace std;


int main(){
    int numeros[] = {2,4,3,1,5};
    int i, pos, actual;

    for(i = 0; i < 5; ++i){
        pos = i;
        actual = numeros[i];
        while((pos > 0) && (numeros[pos-1] > actual)) {
            numeros[pos] = numeros[pos-1];
            pos--;
        }
        numeros[pos] = actual;
    } 


    for(auto j: numeros){
        cout << j << endl;
    }

    return 0;
}