// Created by Ziyi Tang
// Floyd Warshall - Two Edges Path
#include <iostream>
using namespace std;
#define MAXN 100
#define REP(i,s,t) for(int i = s; i < t; i++)
const int INF = (int)1E9;
int grid1[MAXN][MAXN]; // Record cost for each road
int grid2[MAXN][MAXN]; // Record each two-edge path's cost 
int mark[MAXN][MAXN];
int main(){
	// Initialize the grid
	int n,m,tmp;
	cin >> n >> m; // The number of vertices and edges
	REP(i,0,n) REP(j,0,n){
			grid1[i][j] = INF;
			grid2[i][j] = INF;
			// Mark every vertex as infinite (0).
			mark[i][j] = 0;
	}
	int sta, ter, cost; // Starting point and ending point
	REP(i,0,m){
		cin >> sta >> ter >> cost;
		grid1[sta][ter] = cost;
		// The path is non-infinite if at least one end has cookies
		if(cookie[sta] > 0 || cookie[ter] > 0)
			mark[sta][ter] = 1;
	}
	REP(k,0,n) REP(i,0,n) REP(j,0,n){
		if(grid1[i][k] == INF && grid1[k][j] == INF)
			continue;
		// If at least one path is non-infinite
		if(mark[i][k] == 1 || mark[k][i] == 1)
			grid2[i][j] = min(grid2[i][j], grid1[i][k] + grid1[k][j]);
	}

	// Test
	REP(i,0,n){
		REP(j,0,n){
			cout << grid2[i][j] << " ";
		}
		cout << endl;
	}
	


	return 0;
}