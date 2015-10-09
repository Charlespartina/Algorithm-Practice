// Ziyi Tang
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define bound 1000
using namespace std;
typedef pair<int, int> pi;
// Test Case
const string a = "POIUYIJKJYYOIUYOIUYLK";
const string b = "PIPOITOIUJJOIUYK";
// Initialize Lookup Table
int dp[bound][bound]; 
// Initialize decision Table
pi whereTo[bound][bound];
int length(int i, int j){
	if (dp[i][j] != -1){
		return dp[i][j];
	}
	else{
		int thelength;
		if (i < 0 || j < 0){
			return 0;
		}
		else if (a[i] == b[j]){
			thelength = 1 + length(i-1,j-1);
			dp[i][j] = thelength;
			whereTo[i][j] = make_pair(i-1,j-1);
			return thelength;
		}
		else{
			int tmp1 = length(i-1,j);
			int tmp2 = length(i,j-1);
			if (tmp1 > tmp2){
				thelength = tmp1;
				whereTo[i][j] = make_pair(i-1,j);
			}
			else{
				thelength = tmp2;
				whereTo[i][j] = make_pair(i,j-1);
			}
			dp[i][j] = thelength;
			return thelength;
		}
	}
	

}
int main(){
	memset(dp, -1, sizeof(dp)); // Set all position to -1
	int m = a.size();
	int n = b.size();
	int result = length(m-1,n-1);
	cout << result << endl;

	return 0;
}