#include <iostream>

using namespace std;


int main(){
	int nums[8] = {8,6,7,3,0,5,4,2};
	int i,j,aux;

	for(i = 0; i < 8; ++i){
		for(j = 0; j < 8; ++j){
			if(nums[j] > nums[j+1]){
				aux = nums[j];
				nums[j] = nums[j+1];
				nums[j+1] = aux;
			}
		}
	}

	for (i=0; i < 8; ++i){
		cout << nums[i] << endl;
	}

  return 0;
}