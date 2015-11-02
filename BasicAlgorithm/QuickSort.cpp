/*
 *	Iterative QuickSort
 *	Created by Ziyi Tang
 *	
 */

#include <iostream>
#include <cstdio>
#include <stack>
#include <sstream>

#define NUM 1000
using namespace std;
typedef pair<int,int> pi;
typedef stack<pi> spi;

int A[NUM];

void swap(int* a, int* b){
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void iter_quicksort(int L, int U){
	stack<pi> record;
	if (L < U)
		record.push(make_pair(L,U));

	while (!record.empty()){
		pi tmp = record.top(); record.pop();
		int l = tmp.first;
		int u = tmp.second;
		if (l >= u) continue;
		if (A[l] < A[u]) swap(&A[l],&A[u]);
		int pivot = A[u];
		int left = l;
		int right = u;
		do{
			swap(&A[left],&A[right]);
			do {left += 1;} while (A[left] < pivot);
			do {right -= 1;} while (A[right] > pivot);
		}
		while(left < right);
		swap(&A[l], &A[right]);
		record.push(make_pair(l, right-1));
		record.push(make_pair(right+1, u));
		for (int i = 0; i <= U; i++){
			printf("%d ", A[i]);
		}
		cout << endl;
	}


}
int main(){
	// Input
	printf("Enter numbers separated by white space:\n");
	string line;
	getline(cin, line);
	stringstream ss(line);
	int tmp;
	int idx = 0;
	while(ss >> tmp){
		A[idx] = tmp;
		idx++;
	}
	iter_quicksort(0, idx-1);
	for (int i = 0; i < idx; i++){
		printf("%d ", A[i]);
	}


	return 0;
}