#include<bits/stdc++.h>
using namespace std;

#define MAXN 10000

vector<int> grafo[MAXN];
vector<int> par;
vector<bool> vis;

bool kuhn(int u){
	if(vis[u]) return false;

	vis[u] = true;

	for(int v : grafo[u]){
		// se o v nao tem par ou se encontrei um augmented path
		if(par[v] == -1 || kuhn(par[v])) {
			par[v] = u;
			return true;
		}
	}

	return false;
}

vector<int> ladoA, ladoB;

void bipart(int u, int color){
	vis[u] = true;
	if(color == 0){
		ladoA.push_back(u);
	} else {
		ladoB.push_back(u);
	}
	for(int v : grafo[u]){
		if(vis[v]) continue;

		bipart(v, !color);
	}
}

int main(){
	int n, m;
	cin >> n >> m;

	for(int i = 0; i < m; i++){
		int a, b;
		cin >> a >> b;
		grafo[a].push_back(b);
	}

	vis.assign(n, false);

	for(int i = 0; i < n; i++){
		if(!vis[i]) bipart(i, 0);
	}

	par.assign(n, -1);

	int asz = ladoA.size();
	int bsz = ladoB.size();

	for(int i = 0; i < asz; i++){
		vis.assign(n, false);
		kuhn(ladoA[i]);
	}

	int pares = 0;
	for(int i = 0; i < bsz; i++){
		if(par[ladoB[i]] != -1) pares++;
	}

	cout << pares << endl;

	return 0;
}

/*
6 9
0 1
0 3
3 0
2 3
3 2
4 2
5 4
4 5
3 5

*/

