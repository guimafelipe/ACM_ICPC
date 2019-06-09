#include <bits/stdc++.h>

using namespace std;


class Graph {
public:
	int V;
	vector< vector<int> > adj;
	Graph (int v) {
		V = v;
		adj = vector< vector<int> >(V, vector<int>());
	}

	void add_edge(int u, int v) {
		adj[u].push_back(v);
	}

	void topological_sort_util(int v, vector<bool> &visited, stack<int> &S) {
		visited[v] = true;

		for (int i = 0; i < adj[v].size(); i++)
			if ( !visited[adj[v][i]] )
				topological_sort_util(adj[v][i], visited, S);

		S.push(v);
	}

	void topological_sort() {
		stack<int> S;
		vector<bool> visited(V, false);

		for (int i = 0; i < V; i++)
			if ( !visited[i] )
				topological_sort_util(i, visited, S);

		while ( !S.empty() ) {
			cout << S.top() << " ";
			S.pop();
		}
		printf("\n");
	}
};


int main() {
	Graph G(6);
	G.add_edge(5, 0);
	G.add_edge(5, 2);
	G.add_edge(4, 0);
	G.add_edge(4, 1);
	G.add_edge(2, 3);
	G.add_edge(3, 1);

	G.topological_sort();

	return 0;
}