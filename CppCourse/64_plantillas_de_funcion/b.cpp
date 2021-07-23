#include <iostream>


using namespace std;

template <class T>
void absoluteValue(T number);


int main(){

    int n1 = 5;
    double n2 = -680.343570123;
    float n3 = -90.531; 

    absoluteValue(n1);
    absoluteValue(n2);
    absoluteValue(n3);

    return 0;
}


template <class T>
void absoluteValue(T number){
    if(number < 0) {
        number=number*-1;
    }
    cout << "Valor absoluto: " << number << endl;
}