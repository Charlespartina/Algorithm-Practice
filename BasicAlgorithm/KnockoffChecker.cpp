// Knock-off Checker
#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
using namespace std;
#define FILL(a,b) memset(a,b,sizeof(a))
#define REP(i,s,t) for(int i = s; i < t; i++)

int dp [15][1 << 9];

int rec(int sum, int bm){
	bitset<9> tmp(bm);
	cout << tmp << endl;
	if (sum == 0)
		return 1;
	if (bm == ((1 << 10) - 1 - 1) && sum != 0)
		return 0;
	if (sum < 0)
		return 0;
	if(dp[sum][bm] != -1)
		return dp[sum][bm];	
	else{
		int yes = 0;
		for(int i = 1; i <= 9; i++){
			if(((1 << i) & bm) != 0)
				continue;
			yes |= rec(sum-i,bm | (1<<i));
		}
		return dp[sum][bm] = yes;
	}

}
int main(){
	FILL(dp,-1);
	int s;
	int removed;
	// 'now' indicates the numbers removed
	int now;
	while(cin >> s >> removed){
		int bm = 0;
		REP(i,0,removed){
			cin >> now;
			bm |= (1<<(now));
		}
		int re = rec(s,bm);
		cout << re << endl;
	}

	return 0;
}