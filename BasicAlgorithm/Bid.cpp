#include <iostream>
#include <string>
using namespace std;
#define MAXN 100
#define REP(i,s,t) for(int i = s; i < t; i++)
#define FILL(s,v) memset(s, v, sizeof(s));
int BidCost[MAXN];
int BidStart[MAXN];
int nums;	// The number of days
int dp[MAXN];
void ini();

int rec(int j){
	if(j < 0)
		return 0;
	if(dp[j] != -1)
		return dp[j];
	if(BidCost[j] == 0)
		return rec(j-1);
	else
		return dp[j] = max((BidCost[j] + rec(BidStart[j])), rec(j-1));
}
int main(){
	ini();
	FILL(dp,-1);
	// Index starts at 0
	int re = rec(nums-1);
	return 0;
}

void ini(){
	cin >> nums;
	int tmp_cost;
	int tmp_start;
	REP(i,0,nums){
		cin >> tmp_start >> tmp_cost;
		BidCost[i] = tmp_cost;
		BidStart[i] = tmp_start-1;
	}
}