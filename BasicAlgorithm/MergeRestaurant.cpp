// Ziyi Tang
#include <iostream>
#include <cstring>
using namespace std;

const int num = 5; // The amount of restaurants
const int size[] = {10,20,30,40,50}; // The size of each restaurant
int dp[num][num];
int sizesum[num][num];

int sumSize(int i, int j){
	if (sizesum[i][j] != -1){
		return sizesum[i][j];
	}
	int sum = 0;
	for (int k = i; k <= j; k++){
		sum += size[k];
	}
	return sizesum[i][j] = sum;
}

int mergeCost(int i, int j){
	if (dp[i][j] != -1){
		return dp[i][j];

	}
	if (i >= j-1){
		return max(size[i], size[j]);
	}
	else{
		int minprice = 999999;
		for (int k = i; k < j; k++){
			int tmp = mergeCost(i,k) + mergeCost(k+1,j)
					+ max(sumSize(i,k), sumSize(k+1,j));
			minprice = min(minprice, tmp);
		}
		return dp[i][j] = minprice;
	}
}
int main(){
	memset(dp, -1, sizeof(dp));
	memset(sizesum, -1, sizeof(sizesum));
	int result = mergeCost(0, num-1);
	cout << result << endl;
	return 0;
}

