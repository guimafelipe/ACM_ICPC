#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
#define MAXN 10000

vi grafo[MAXN], grafot[MAXN];
set<int> grafoc[MAXN];

vector<bool> vis;
vector<int> topological;
vector<int> comp;
int c;

void dfs1(int u){
	vis[u] = true;

	for(int v : grafo[u]){
		if(!vis[v]){
			dfs1(v);
		}
	}

	topological.push_back(u);
}

void dfs2(int u){
	vis[u] = true;
	comp[u] = c;
	for(int v : grafot[u]){
		if(!vis[v]){
			dfs2(v);
		}
	}
}

int main(){
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int a, b;
		cin >> a >> b;
		grafo[a].push_back(b);
		grafot[b].push_back(a);
	}

	vis.assign(n, false);

	for(int i = 0; i < n; i++){
		if(!vis[i]){
			dfs1(i);
		}
	}

	reverse(topological.begin(), topological.end());

	comp.resize(n);
	vis.assign(n, false);
	c = 0;

	for(int i = 0; i < n; i++){
		int u = topological[i];
		if(!vis[u]){
			dfs2(u);
			c++;
		}
	}

	// montando grafo das componentes
	for(int u = 0; u < n; u++){
		for(int v : grafo[u]){
			if(comp[v] == comp[u]) continue;

			grafoc[comp[u]].insert(comp[v]);
			// pode repetir
		}
	}

	cout << endl;
	for(int i = 0; i < n; i++){
		cout << i << " " << comp[i] << endl;
	}
	cout << endl;

	for(int i = 0; i < c; i++){
		cout << i << ": ";
		for(int x : grafoc[i]){
			cout << x << " ";
		}
		cout << endl;
	}

	return 0;
}

