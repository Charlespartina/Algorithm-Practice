#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;
#define MAXN 1000
const int INF = (int)1E9;
int dp[MAXN][MAXN];
vector<int> vi;

int n; // n elements in the array

int rec(int tn, int tk){
	if(tn == n){
		return 0;
	}
	if(dp[tn][tk] != -1)
		return dp[tn][tk];
	int minp = INF;
	int tmp_sum = 0;
	for(int i = tn; i < n; i++){
		tmp_sum += vi[i];
		minp = min(minp, tmp_sum*tmp_sum + rec(i+1,tk+1));
	}
	return dp[tn][tk] = minp;
}

int main(){

	// Input numbers separated by a white space in a line
	string line;
	getline(cin,line);
	stringstream ss(line);
	int tmp;
	while(ss >> tmp){
		vi.push_back(tmp);
	}
	
	n = vi.size();
	memset(dp,-1,sizeof(dp));
	int re = rec(0,1);

	// Output
	cout << re << endl;
}