#include  <iostream>


using namespace std;

int main(){
    double pi = 3.14159;
    cout.precision(11);
    cout.setf(ios::fixed);
    cout << "Your result is:" << pi ;

    return 0;
}