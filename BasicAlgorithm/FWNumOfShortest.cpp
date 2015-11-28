// Created by Ziyi Tang
// Floyd Warshall Number of Shortest paths
#include <iostream>
using namespace std;
#define MAXN 100
#define REP(i,s,t) for(int i = s; i < t; i++)
const int INF = (int)1E9;
int grid[MAXN][MAXN];
int num[MAXN][MAXN];
int main(){
	// Initialize the grid
	int n,m,tmp;
	cin >> n >> m; // The number of vertices and edges
	REP(i,0,n) REP(j,0,n){
		grid[i][j] = INF;
		num[i][j] = 0;
	}
	int sta, ter, cost; // Starting point and ending point
	REP(i,0,m){
		cin >> sta >> ter >> cost;
		grid[sta][ter] = cost;
		num[sta][ter] = 1;
	}
	REP(k,0,n) REP(i,0,n) REP(j,0,n){
		if(grid[i][k] == INF || grid[k][j] == INF)
			continue;
		if(grid[i][k] + grid[k][j] < grid[i][j]){
			grid[i][j] = grid[i][k] + grid[k][j];
			num[i][j] = 1;
		}
		else if(grid[i][k] + grid[k][j] == grid[i][j]){
			num[i][j] ++;
		}
	}
	
	// Test
	REP(i,0,n){
		REP(j,0,n){
			cout << num[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}