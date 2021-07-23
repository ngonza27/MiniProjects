#include <iostream>
#include <array>
#include <vector>

using namespace std;

int main(){
    string a = "nicolas";
    cout << a << endl;

    int arr1[5] = {1,2,3,4,5};
    //for (int i = 0; i < sizeof(arr1)/sizeof(arr1[0]); ++i){
    //    cout << arr[i] << endl;
    //}
    cout  << "\n"<<  "asd" << arr1[4] << endl;


    int arr2[1];

    vector<char> arr;
    arr.push_back('a');
    arr.push_back('b');
    arr.push_back('c');
    for(auto i: arr){
        cout << i << endl;
    }

    array<int, 2> arr3 = {9, 999};
    arr3.back() = 10;
    for(int x: arr3){
        cout << " " << x;
    }

    for (auto i = arr3.begin(); i != arr3.end(); ++i){
        cout << *i << endl;
    }
    return 0;
}