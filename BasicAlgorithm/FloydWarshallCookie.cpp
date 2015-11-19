// Created by Ziyi Tang
#include <iostream>
using namespace std;
#define MAXN 100
#define REP(i,s,t) for(int i=s;i<t;i++)
const int INF = (int)1E9;
int cookie[MAXN];
int Ecost[MAXN][MAXN];

int FindCookie[MAXN][MAXN]; 
// Record the amount of cookies along each path

int main(){
	
	int n,m; // n vertices and m edges
	cin >> n >> m;

	// Initialize the number of cookies
	REP(i,0,n){
		int tmp;
		cin >> tmp;
		cookie[i] = tmp;
	}
	// Initialize the graph
	REP(i,0,n) REP(j,0,n){
		Ecost[i][j] = INF;
		if(i == j)
			Ecost[i][j] = 0;
	}

	// Initialize the cookie counting table
	memset(FindCookie, 0, sizeof(FindCookie));
	REP(i,0,m){
		int sta,ter,cost;
		cin >> sta >> ter >> cost;
		Ecost[sta][ter] = cost;
		FindCookie[sta][ter] = cookie[sta] + cookie[ter];
	}
	

	// Floyd Warshall with cookie
	REP(k,0,n) REP(i,0,n) REP(j,0,n){
		if(Ecost[i][k] == INF || Ecost[k][j] == INF)
			continue;
		if(Ecost[i][j] > Ecost[i][k] + Ecost[k][j]){
			Ecost[i][j] = Ecost[i][k] + Ecost[k][j];
			FindCookie[i][j] = FindCookie[i][k] + FindCookie[k][j] - cookie[k];
		}
		if(Ecost[i][j] == Ecost[i][k] + Ecost[k][j]){
			FindCookie[i][j] = 
			max(FindCookie[i][j], FindCookie[i][k]+FindCookie[k][j]-cookie[k]);
		}
	}
	REP(i,0,n) {
		REP(j,0,n){
			cout << FindCookie[i][j] << " ";
		}
		cout << endl;
	}
	


	return 0;
}