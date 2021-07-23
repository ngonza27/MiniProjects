#include <iostream>

using namespace std;


int main(){

    int arr[5] = {3,4,2,1,5};
    bool found = false;
    int target = 10;

    int i = 0;
    while((!found) && (i < 5)){
        if(arr[i] == target){
            found = true;
        }
        i++;
    }
    if(!found){
        cout << "Number not found in the array" << endl;
    } else {
        cout << "Number found in the position: " << i-1 << endl;
    }

    return 0;
}