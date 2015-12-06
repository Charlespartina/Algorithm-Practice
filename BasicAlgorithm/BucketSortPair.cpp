#include <iostream>
#include <vector>
using namespace std;
typedef pair<int,int> pi;
typedef vector<pi> vpi;
typedef vector<vector<int> > vvi;
typedef vector<vector<pi> > vvpi;
#define MAXN 1000

vpi edges; // Containing edge-pairs
vvpi bucket;
vvi graph; // Adjcency list that we want to create
int n; // The number of vertices
int m; // The number of edges
int main(){
	cin >> n >> m;
	vpi ttmp;
	bucket.assign(n, ttmp);
	for(int i = 0; i < m; i++){
		// Input for each edge: starting vertex, ending vertex
		// Starting Index is 1
		int sta,ter;
		cin >> sta >> ter;
		edges.push_back(make_pair(sta-1,ter-1));
	}

	// Bucket Sort 1st Round
	for(int i = 0; i < m; i++){
		pi now = edges[i];
		int v = now.second; // The ending vertex of an edge
		bucket[v].push_back(now);
	}
	edges.clear();
	for(int i = 0; i < n; i++){
		int sz = bucket[i].size();
		for(int j = 0; j < sz; j++){
			pi now = bucket[i][j];
			edges.push_back(now);
		}
	}

	// Bucket Sort 2nd Round
	bucket.clear(); // Clear the bucket
	bucket.assign(n, ttmp);
	for(int i = 0; i < m; i++){
		pi now = edges[i];
		int v = now.first; // The starting vertex of an edge
		bucket[v].push_back(now);
	}
	edges.clear();
	for(int i = 0; i < n; i++){
		int sz = bucket[i].size();
		for(int j = 0; j < sz; j++){
			pi now = bucket[i][j];
			edges.push_back(now);
		}
	}
	cout << endl;
	for(int i = 0; i < m; i++){
		cout << edges[i].first+1 << " " << edges[i].second+1 << endl;
	}

}