#include <iostream>

using namespace std;

int maxNumber(int x, int y);

int main(int argc, char *argv[]){
    if(argc > 3){
        cout << "Only expecting two numbers" << endl;
        return 0;
    }
    int x = atoi(argv[1]);
    int y = atoi(argv[2]);
    cout << x << " " << y << endl;
    int max;
    max = maxNumber(x,y);

    cout << max << endl;

    return 0;
}


int maxNumber(int x, int y){
    return x > y ? x : y;
}