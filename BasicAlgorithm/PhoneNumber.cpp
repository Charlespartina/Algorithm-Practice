// Non-increasing digits
// Dynamic Programming
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
#define REP(i,s,t) for(int i=s;i<t;i++)
#define FILL(a,b) memset(a,b,sizeof(a))

int dp[10][10];
int digits;
int rec(int pos, int num){
	if(pos == digits)
		return 1;
	if(dp[pos][num] != -1)
		return dp[pos][num];
	int sum = 0;
	REP(i,0,num+1){
		sum += rec(pos+1, i);
	}
	return dp[pos][num] = sum;
}
int main(){
	while(cin >> digits){
		FILL(dp,-1);
		int re = rec(0,9);
		cout << re << endl;
		// REP(i,0,digits) {
		// 	REP(j,0,10){
		// 		cout << dp[i][j] << " ";
		// 	}
		// 	cout << endl;
		// }
	}
	return 0;
}
