// Created by Ziyi Tang
// Floyd Warshall Recovery
#include <iostream>
using namespace std;
#define MAXN 100
#define REP(i,s,t) for(int i = s; i < t; i++)
const int INF = (int)1E9;
int grid[MAXN][MAXN];
int recovery[MAXN][MAXN];

void printPath(int sta, int ter){
	if(recovery[sta][ter] != 0){
		printPath(sta,recovery[sta][ter]);
		printPath(recovery[sta][ter],ter);
	}
	else{
		cout << sta << endl;
	}
}
int main(){
	// Initialize the grid
	int n,m,tmp;
	cin >> n >> m; // The number of vertices and edges
	REP(i,0,n) REP(j,0,n){
		if(i == j){
			grid[i][j] = 0;
			recovery[i][j] = 0;
		}
		else{
			grid[i][j] = INF;
			recovery[i][j] = INF;
		}
	}
	int sta, ter, cost; // Starting point and ending point
	REP(i,0,m){
		cin >> sta >> ter >> cost;
		grid[sta][ter] = cost;
		recovery[sta][ter] = 0; // There is a path
	}
	REP(k,0,n) REP(i,0,n) REP(j,0,n){
		if(grid[i][k] == INF || grid[k][j] == INF)
			continue;
		if(grid[i][k] + grid[k][j] < grid[i][j]){
			grid[i][j] = grid[i][k] + grid[k][j];
			recovery[i][j] = k; // Record the intermidiate vertex
		}
	}
	int a,b;
	cin >> a >> b;
	if(recovery[a][b]!= INF){
		printPath(a,b); // Print the path [a,b)
		cout << b << endl;
	}

	return 0;
}