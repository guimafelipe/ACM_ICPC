#include<bits/stdc++.h>
using namespace std;

#define MAXN 10000

vector<int> grafo[MAXN];
vector<int> parv, paru;
vector<bool> vis;

vector<bool> zu, zv;
vector<int> coveru, coverv;

bool kuhn(int u){
	if(vis[u]) return false;

	vis[u] = true;

	for(int v : grafo[u]){
		// se o v nao tem par ou se encontrei um augmented path
		if(parv[v] == -1 || kuhn(parv[v])) {
			parv[v] = u;
			return true;
		}
	}

	return false;
}


void reach(int u){
	if(u == -1 || zu[u]) return;
	zu[u] = true;
	for(int v : grafo[u]){
		if(parv[v] == u) continue;

		zv[v] = true;
		reach(parv[v]);
	}
}

int main(){
	int n, m;
	cin >> n >> m;

	for(int i = 0; i < n; i++){
		grafo[i].clear();
		for(int j = 0; j < m; j++){
			int p;
			cin >> p;
			if(p == 1){
				grafo[i].push_back(j);
			}
		}
	}

	parv.assign(m, -1);
	for(int u = 0; u < n; u++){
		vis.assign(n, false);
		kuhn(u);
	}

	int pairs = 0;
	paru.assign(n, -1);
	for(int v = 0; v < m; v++){
		if(parv[v] != -1){
			paru[parv[v]] = v;
			pairs++;
		}
	}

	cout << pairs << endl;

	zu.assign(n, false);
	zv.assign(n, false);

	for(int u = 0; u < n; u++){
		if(paru[u] == -1){
			reach(u);
		}
	}

	for(int u = 0; u < n; u++){
		if(!zu[u]){
			coveru.push_back(u);
			cout << u << " ";
		}
	}
	cout << endl;

	for(int v = 0; v < m; v++){
		if(zv[v]){
			coverv.push_back(v);
			cout << v << " ";
		}
	}
	cout << endl;

	return 0;
}

/*

in:
4 5
1 1 0 0 0
0 0 1 1 1
0 0 1 0 0
0 0 1 0 0

*/

