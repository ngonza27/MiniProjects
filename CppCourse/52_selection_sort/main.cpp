#include <iostream>


using namespace std;

int main(){
    int arr[] = {3,2,1,4,5,0};
    int aux, min;

    for(int i = 0; i < 6; ++i){
        min = i;
        for (int j = i+1; j < 6; ++j){
            if(arr[j] < arr[min]){
                min = j;
            }
        }
        aux = arr[i];
        arr[i] = arr[min];
        arr[min] = aux;
    }

    for(auto x: arr){
        cout << x << endl;
    }

    return 0;
}