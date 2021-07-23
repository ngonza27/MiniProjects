#include <iostream>

using namespace std;


// the array has to be ordered
int main(){
    int arr[8] = {1,2,3,4,5,6,7,8};
    int low, high, mid;

    int target = 6;
    bool found = false;

    low = 0;
    high = 8;
    while(low <= high){
        mid = (high + low) / 2;
        if(arr[mid] == target){
            found = true;
            break;
        }
        if(arr[mid] > target){
            high = mid;
            mid = (high + low) / 2;
        }
        if(arr[mid] < target){
            low = mid;
            mid = (high + low) / 2;
        }
    }

    if(found){
        cout << "Number was found at position: " << mid << endl;
    } else {
        cout << "Number was not found" << endl;
    }

    return 0;
}