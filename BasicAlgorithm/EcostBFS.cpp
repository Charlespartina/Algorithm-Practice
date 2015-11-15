// Ecost Problem
// Created by Ziyi Tang

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
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
int cont[1000]; // Record incoming edges for each vertex
int mark[1000];
queue<int> que;

int main(){
	while(cin >> n >> m){
		FILL(longest,-1);
		FILL(cont,0);
		FILL(mark,0);
		all.clear();
		vpi tmp;
		all.assign(n,tmp);
		REP(i,0,m){
			int sta,ter,cost;
			cin >> sta >> ter >> cost;
			all[sta].push_back(make_pair(ter,cost));
			cont[ter]++;
		}
		REP(i,0,n){
			if(cont[i] == 0){
				// Push vertices who doesn't have any incoming edges
				que.push(i);
				longest[i] = 0;
			}
		}
		while(!que.empty()){
			int now = que.front();que.pop();
			int sz = all[now].size();
			REP(i,0,sz){
				// Process each vertex that this vertex points to
				int tmp = all[now][i].first;
				// Update the longest paths for that vertex
				longest[tmp] = max(longest[tmp], all[now][i].second + longest[now]);
				cont[tmp]--;
				// If the vertex doesn't have any incoming edges
				// Push it into the queue
				if(cont[tmp] == 0){
					que.push(tmp);
				}
			}
		}
		
		REP(i,0,n){
			cout << longest[i] << " ";
			cout << endl;
		}
		
	}


	return 0;
}
