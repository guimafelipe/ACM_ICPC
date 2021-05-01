#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

#define MAXN 10000

vi grafo[MAXN];
vector<bool> vis;
vi tin, tout, low;
int tempo;

vector<pair<int, int>> bridges;
vector<int> cutpoints;

void dfs(int u, int p = -1){
	vis[u] = true;
	tin[u] = tempo++;
	low[u] = tin[u];

	int children = 0;
	for(int v : grafo[u]){
		if(v == p) continue;
		if(vis[v]){
			low[u] = min(low[u], tin[v]);
		} else {
			dfs(v, u);
			low[u] = min(low[u], low[v]);
			if(low[v] > tin[u]){
				bridges.push_back(make_pair(u,v));
			}
			if(low[v] >= tin[u] && p != -1){
				cutpoints.push_back(u);
			}
			children++;
		}
	}

	if(p == -1 && children > 1) cutpoints.push_back(u);

	tout[u] = tempo++;
}

int main(){
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int a, b;
		cin >> a >> b;
		grafo[a].push_back(b);
		grafo[b].push_back(a);
	}

	vis.assign(n, false);
	low.resize(n);
	tin.resize(n);
	tout.resize(n);
	tempo = 0;
	
	dfs(0);
	
	cout << "Pontes:\n";
	for(auto p : bridges){
		cout << p.first << " " << p.second << endl;
	}

	cout << "Pontos de articulação: ";
	for(int x : cutpoints) cout << x << " ";
	cout << endl;
}

/*
entrada:
6 7
0 1
0 2
1 2
2 3
3 4
3 5
4 5

*/ 


