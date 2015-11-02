#include <iostream>
#include <string>
using namespace std;

const int num = 10;
int array[] = {10,3,4,2,8,7,6,5,9,1}; // The original array
int tmp[100]; // A temporary array for merge sort
int IMergeSort(int i, int j){
	if (i == j)
		return 0; // A single element doesn't have inversion
	int mid = (i+j)/2;
	int sum = 0;
	sum += IMergeSort(i, mid);
	sum += IMergeSort(mid+1,j);
	int k1 = i;
	int k2 = mid+1;
	int idx = i;
	while(k1 <= mid && k2 <= j){
		if (array[k1] < array[k2]){
			tmp[idx] = array[k1];
			k1++;
			idx++;
		}
		else{
			tmp[idx] = array[k2];
			k2++;
			idx++;
			sum += mid-k1+1; 
			// When copying an element from right array,
			// the number of inversion is 
			// all remaining elements in the left subarray
		}
	}
	while (k1 <= mid){
		tmp[idx] = array[k1];
		k1++;
		idx++;
	}
	while (k2 <= j){
		tmp[idx] = array[k2];
		k2++;
		idx++;
	}
	for (int k = i; k <= j; k++){
		array[k] = tmp[k];
	}
	return sum;

}
int main(){
	int re = IMergeSort(0, num-1);
	cout << re << endl;

	// Test code to showing sorted array
	// for (int i = 0;i < num; i++){
	// 	cout << array[i] << " ";
	// }
	// cout << endl;
	return 0;
}