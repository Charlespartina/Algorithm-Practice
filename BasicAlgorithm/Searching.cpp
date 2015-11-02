#include <iostream>
#include <algorithm>
using namespace std;

const int n = 12;
const int array[] = {11,13,15,17,19,20,21,22,30,1,4,9};
const int key = 19;

// Find the index for maximum element within the array
int findMinIdx(int l, int r, int rm){
	int mid = (l+r)/2;
	if (mid == l || mid == r){
		return array[l] < array[r] ? l : r;
	}
	else{
		if (array[mid] > rm)
			return findMinIdx(mid+1, r, rm);
		else
			return findMinIdx(l, mid, rm);
			// It is possible that the mid point is the minimum,
			// so we include it into the next recursion
	}
}
// Binary Search
int binsearch(int i, int j, int key){
	if (i > j)
		return -1; // Not Found
	else{
		int mid = (i+j)/2;
		if (key > array[mid])
			return binsearch(mid+1, j, key);
		else if (key < array[mid]){
			return binsearch(i, mid-1, key);
		}
		else{
			return mid;
		}
	}

}
int main(){
	int lm = array[0];
	int rm = array[n-1];
	int minp = findMinIdx(0, n-1, rm);
	int pos1 = binsearch(minp, n-1,key);
	int pos2 = binsearch(0, minp-1,key);
	int re = -1;
	if (pos1 != -1)
		re =  pos1;
	else if(pos2 != -1)
		re =  pos2;
	else
		re =  -1;
	cout << re << endl;


	return 0;
}