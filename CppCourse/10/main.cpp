#include <iostream>
#include <math.h>

using namespace std;

//sqrt and pwr
int main(){
    double num, sqrtt, pwr;
    cout << "numero: " << endl; cin >> num;
    sqrtt = sqrt(num);
    pwr = pow(num, 2);

    cout << "Sqrt: " << sqrtt << "Power of 2: " << pwr << endl;


    return 0;
}