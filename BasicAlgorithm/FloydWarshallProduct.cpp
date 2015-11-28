// Created by Ziyi Tang
// Floyd Warshall Long Edge
#include <iostream>
using namespace std;
#define MAXN 100
#define REP(i,s,t) for(int i = s; i < t; i++)
const int INF = (int)1E9;
int grid[MAXN][MAXN];

int main(){
	// Initialize the grid
	int n,m,tmp;
	cin >> n >> m; // The number of vertices and edges
	REP(i,0,n) REP(j,0,n){
		// Set each vertex's self-distance as 1 instead of 0
		grid[i][j] = (i == j) ? 1 : INF;
	}
	int sta, ter, cost; // Starting point and ending point
	REP(i,0,m){
		cin >> sta >> ter >> cost;
		grid[sta][ter] = cost;
	}
	REP(k,0,n) REP(i,0,n) REP(j,0,n){
		if(grid[i][k] == INF || grid[k][j] == INF)
			continue;
		// Find the longest edge out of the two edges
		if(grid[i][k]*grid[k][j] < grid[i][j])
			grid[i][j] = grid[i][k]*grid[k][j];
	}

	// Test
	REP(i,0,n){
		REP(j,0,n){
			cout << grid[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}