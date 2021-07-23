#include <iostream>

using namespace std;

int factorial(int);


int main(){

    int n = 10;

    cout << "Factorial de " << n << " es: " << factorial(n) <<endl;

    return 0;
}


int factorial(int n){
    if(n <= 1){
        return 1;
    }
    return  n * factorial(n-1);
}