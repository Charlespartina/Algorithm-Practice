// Created by Ziyi Tang
// Floyd Enhancement
#include <iostream>
using namespace std;
#define MAXN 100
#define REP(i,s,t) for(int i = s; i < t; i++)
const int INF = (int)1E9;
int grid[MAXN][MAXN];
int Intermediate[MAXN][MAXN];

void printPath(int sta, int ter){
	cout << " " << sta << endl;
	if(sta != ter) printPath(Intermediate[sta][ter], ter);
}
int main(){
	// Initialize the grid
	int n,m,tmp;
	cin >> n >> m; // The number of vertices and edges
	REP(i,0,n) REP(j,0,n){
		Intermediate[i][j] = j; // Initialize Intermediate
		grid[i][j] = INF;
		if(i == j)
			grid[i][j] = 0;
	}
	int sta, ter, cost; // Starting point and ending point
	REP(i,0,m){
		cin >> sta >> ter >> cost;
		grid[sta][ter] = cost;
	}
	REP(k,0,n) REP(i,0,n) REP(j,0,n){
		if(grid[i][k] == INF || grid[k][j] == INF)
			continue;
		if(grid[i][k] + grid[k][j] < grid[i][j]){
			grid[i][j] = grid[i][k] + grid[k][j];
			Intermediate[i][j] = Intermediate[i][k]; 
			// Record the intermediate vertex
		}
	}
	int a,b;
	cin >> a >> b;
	if(a != b){
		printPath(a,b); // Print the path [a,b]
	}

	return 0;
}