// Ziyi Tang
#include <iostream>
#include <cstring>
#include <string>
#define bound 1000
#define INF (int)1E9
using namespace std;

int num = 4;
int test[] = {-2,1,2,-1};
int dp[bound][bound];

int recurse(int i, int j){
	if (i > j)
		return 0;
	if (dp[i][j] != -1)
		return dp[i][j];
	else{
		int tmp = -INF;
		for (int k = i; k <= j; k++){
			tmp = max(tmp, 2*recurse(i,k-1) + test[k] + 3*recurse(k+1,j));
		}
		return dp[i][j] = tmp;
	}
}
int main(){
	memset(dp,-1,sizeof(dp));
	int re = recurse(0, num-1);
	cout << re << endl;
	return 0;
}