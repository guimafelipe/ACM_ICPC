#include <bits/stdc++.h>

using namespace std;


void print(vector<int> &A) {
	for (int i = 0; i < A.size(); i++)
		printf("%d ", A[i]);
	printf("\n");
}

void print2(vector< vector<int> > m) {
	for (int i = 0; i < m.size(); i++)
		print(m[i]);
}


class Graph {
	int V;
	
	vector< vector<int> > adj;

	void fill_order(int v, vector<bool> &visited, stack<int> &S) {
		visited[v] = true;

		for (int neighbor : adj[v])
			if ( !visited[neighbor] )
				fill_order(neighbor, visited, S);

		S.push(v);
	}

	void dfs_util(vector<int> &ans, int v, vector<bool> &visited) {
		visited[v] = true;

		ans.push_back(v);

		for (int neighbor : adj[v])
			if ( !visited[neighbor] )
				dfs_util(ans, neighbor, visited);
	}

public:
	Graph (int v) {
		V = v;
		adj = vector< vector<int> >(V, vector<int>());
	}

	void add_edge(int v, int w) {
		adj[v].push_back(w);
	}

	Graph get_transpose() {
		Graph g_t(V);

		for (int v = 0; v < V; v++) {
			for (int i = 0; i < adj[v].size(); i++) {
				g_t.add_edge(adj[v][i], v);
			}
		}

		return g_t;
	}

	vector< vector<int> > SCCs() {
		vector< vector<int> > ans;

		stack<int> S;

		Graph g_t = get_transpose();

		vector<bool> visited(V, false);

		for (int v = 0; v < V; v++)
			if ( !visited[v] )
				fill_order(v, visited, S);

		for (int v = 0; v < V; v++)
			visited[v] = false;

		while ( !S.empty() ) {
			int curr = S.top();
			S.pop();

			vector<int> scc;
			if ( !visited[curr] ) {
				g_t.dfs_util(scc, curr, visited);
				ans.push_back(scc);
			}
		}

		return ans;
	}
};


int main() {
	Graph G(5);
	G.add_edge(0, 2);
	G.add_edge(2, 1);
	G.add_edge(1, 0);
	G.add_edge(0, 3);
	G.add_edge(3, 4);

	vector< vector<int> > ans = G.SCCs();

	print2(ans);

	return 0;
}