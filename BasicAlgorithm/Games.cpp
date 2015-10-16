// Ziyi Tang
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

const double prob1 = 0.5;
const double prob2 = 0.5;
const int games = 10;
double dp[11][11]; // Start index at 1

int main(){
	memset(dp,0,sizeof(dp)); // Initial all entries to 0
	for (int j = 1; j <= games; j++){
		dp[10][j] = 1;
		// Initialize all entries in the last row to 1
	}
	for (int i = games-1; i >= 1; i--){
		for (int j = games-1; j >=1; j--){
			dp[i][j] = prob1 * dp[i+1][j] + prob2 * dp[i][j+1];
		}
	}

	// Test Code
	// for (int i = 1; i <= games; i++){
	// 	for (int j = 1; j <= games; j++){
	// 		printf("%1.3f ",dp[i][j]);
	// 	}
	// 	printf("\n");
	// }
	return 0;
}