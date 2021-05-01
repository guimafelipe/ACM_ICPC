#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Edge {
public:
    int u, v, w;
    Edge(int _u, int _v, int _w) {u = _u; v = _v; w = _w;}
};

// Retorna se tem ou não ciclo
bool bellman_ford(vector<Edge> &edges, int n, int src) {
    vector<int> dist(n, INT_MAX);
    dist[src] = 0;
    
    for (int j = 0; j < n - 1; j++)
        for (int i = 0; i < edges.size(); i++) {
            Edge e = edges[i];
            int u = e.u, v = e.v, w = e.w;
            
            if (dist[u] != INT_MAX && dist[u] + w < dist[v])
                dist[v] = dist[u] + w;
        }
    
    for (int i = 0; i < edges.size(); i++) {
            Edge e = edges[i];
            int u = e.u, v = e.v, w = e.w;
            
            if (dist[u] != INT_MAX && dist[u] + w < dist[v])
                return 1;
        }
        
    return 0;
}

int main() {
	//code
	int T;
	cin >> T;
	
	for (int t = 0; t < T; t++) {
	    int n, m;
	    cin >> n >> m;
	    
	    vector<Edge> edges;
	    for (int i = 0; i < m; i++) {
	        int u, v, w;
	        cin >> u >> v >> w;
	        edges.push_back(Edge(u, v, w));
	    }
	    
	    cout << bellman_ford(edges, n, 0) << endl;
	}
	
	return 0;
}

// Input:
// 2
// 5 8
// 0 1 -1 0 2 4 1 2 3 1 3 2 1 4 2 3 2 5 3 1 1 4 3 -3
// 3 3
// 0 1 -5 1 2 -6 2 0 -9
// Output:
// 0
// 1
