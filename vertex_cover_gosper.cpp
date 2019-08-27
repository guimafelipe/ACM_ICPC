#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void print(vector<int> &A) {
	for (int i = 0; i < A.size(); i++)
		printf("%d ", A[i]);
	printf("\n");
}

void add_edge(vector< vector<int> > &g, int u, int v) {
	g[u].push_back(v);
	g[v].push_back(u);
}

bool is_cover(vector< vector<int> > &g, int V, int E, int k) {
	int set = (1 << k) - 1;
	int limit = (1 << V);

	while (set < limit) {
		vector< vector<bool> > visited(V, vector<bool>(V, false));
		int count = 0;

		int u = 0;
		for (int i = 1; i < limit && u < V; i <<= 1) {
			if (set & i) {
				for (int j = 0; j < g[u].size(); j++) {
					int v = g[u][j];
					if (g[u][j] && !visited[u][v]) {
						visited[u][v] = true;
						visited[v][u] = true;
						count++;
					}
				}
			}
			u++;
		}

		if (count == E)
			return true;

		int last = set & -set;
		int r = set + last;
		set = (((r ^ set) >> 2) / last) | r;
	}

	return false;
}

int bin_search(vector< vector<int> > &g, int V, int E) {
	int l = 1;
	int r = V;

	while (l < r) {
		int m = (l + r) / 2;

		if (is_cover(g, V, E, m))
			r = m;
		else
			l = m + 1;
	}

	return l;
}

int main() {
	// int V = 6;
	// int E = 6;
	// vector< vector<int> > g(V + 1, vector<int>());
	// add_edge(g, 0, 1);
	// add_edge(g, 1, 2);
	// add_edge(g, 0, 2);
	// add_edge(g, 0, 3);
	// add_edge(g, 0, 4);
	// add_edge(g, 0, 5);

	// cout << bin_search(g, V, E) << endl;

	int V = 6;
	int E = 7;
	vector< vector<int> > g(V, vector<int>());
	add_edge(g, 0, 1);
	add_edge(g, 0, 2);
	add_edge(g, 1, 2);
	add_edge(g, 1, 3);
	add_edge(g, 2, 4);
	add_edge(g, 3, 4);
	add_edge(g, 3, 5);
	cout << bin_search(g, V, E) << endl;

	return 0;
}