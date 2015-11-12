/*
 *	Center Problem
 *	Created by Ziyi Tang
 *	
 */


#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
#define REP(i,s,t) for(int i=(s);i<(t);i++)
#define FILL(x,v) memset(x,v,sizeof(x))


vvi all; 
int n,m;
queue<int> que;
int cont[1000]; // The number of edges connected to a certain edge
int mark[1000];
int main(){
	int n,m;
	// n is the number of vertices
	// m is the number of edges
	while(cin >> n >> m){
		int remain = n;
		FILL(cont,0);
		FILL(mark,0);
		all.clear();
		vi tmp;
		all.assign(n,tmp);
		REP(i,0,m){
			int sta,ter;
			cin >> sta >> ter; 
			all[sta].push_back(ter);
			all[ter].push_back(sta);
			cont[sta]++;
			cont[ter]++;
		}
		REP(i,0,n){
			if(cont[i] == 1){
				mark[i] = 1;
				// Mark when this vertex is ready to be removed
				// As it only has one edge (a leaf)
				que.push(i);
			}
		}
		int first = -1 ,second;
		while(!que.empty()){
			int tmp = que.front();que.pop();
			second = first;
			first = tmp;
			int sz = all[tmp].size();
			REP(i,0,sz){
				if(mark[all[tmp][i]] == 0){
					cont[all[tmp][i]]--;
					if(cont[all[tmp][i]] == 1){
						mark[all[tmp][i]] = 1;
						// Mark when this vertex is ready to be removed
						que.push(all[tmp][i]);
						n--;
						// Count how many vertices left
					}
				}
			}
		}
		if(first == second)
			// There are two centers
			cout << "The two centers are: "<< first << " and "<< second <<endl;
		else
			// There are only one center
			cout << "The center is: " << first << endl;
	}

	return 0;
}
