// Ecost Problem
// Created by Ziyi Tang

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pi> vpi;
typedef vector<vpi> vvpi;
#define REP(i,s,t) for(int i = s; i < t; i++)
#define FILL(a,i) memset(a, i, sizeof(a))

vvpi all;
int n,m;
int longest[1000]; // Record the "longestoutof" for each vertex
int mark[1000];

void dfs(int idx){
	mark[idx] = 1;
	int sz = all[idx].size();
	if(sz == 0){
		// It is a leaf vertex
		longest[idx] = 0;
		return;
	}
	int tmplength = -1;
	REP(i,0,sz){
		int next = all[idx][i].first;
		if(mark[next] == 0){
			dfs(next);
		}
		tmplength = max(tmplength, longest[next] + all[idx][i].second);
	}
	longest[idx] = tmplength;
	return;

}
int main(){
	while(cin >> n >> m){
		FILL(longest,0);
		FILL(mark,0);
		all.clear();
		vpi tmp;
		all.assign(n,tmp);
		REP(i,0,m){
			int sta,ter,cost;
			cin >> sta >> ter >> cost;
			all[sta].push_back(make_pair(ter,cost));
		}
		REP(i,0,n){
			if(mark[i] == 0)
				dfs(i);
		}

		// Test
		REP(i,0,n){
			cout << longest[i] << " ";
			cout << endl;
		}
		
	}


	return 0;
}
