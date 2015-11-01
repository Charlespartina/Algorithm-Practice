// Ziyi Tang
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
#define INF (int)1E9

int num = 6;
int mat[] = {20,100,10,20,100,5};
// Start Index at 0
int dp[100][100];

int cost(int i, int j){
	if (i == j)
		return 0;
	if(dp[i][j] != -1)
		return dp[i][j];
	else{
		int tmp = INF;
		for (int k = i + 1; k <= j; k++){
			tmp = min(tmp, cost(i, k-1) + cost(k, j) + mat[i]*mat[k]*mat[j+1]);
		}
		return dp[i][j] = tmp;
	}
}
int main(){
	memset(dp, -1, sizeof(dp));
	int result = cost(0,num-2);
	//int result = cost(0,num-1);
	for (int i = num-1; i >= 0; i--){
		for (int j = num-1-1; j >= 0; j--){
			printf("%10d", dp[i][j]);
		}
		printf("\n");
	}
	return 0;
}

// Output of this program is 26000