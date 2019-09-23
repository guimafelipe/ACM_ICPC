#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Edge {
public:
    int u, v, w;
    Edge(int _u, int _v, int _w) {u = _u; v = _v; w = _w;}
};

bool bellman_ford(vector<Edge> &g, int V, int src) {
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;
    
    for (int v = 0; v < V - 1; v++)
        for (int i = 0; i < g.size(); i++) {
            Edge e = g[i];
            int u = e.u, v = e.v, w = e.w;
            
            if (dist[u] != INT_MAX && dist[u] + w < dist[v])
                dist[v] = dist[u] + w;
        }
    
    for (int i = 0; i < g.size(); i++) {
            Edge e = g[i];
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
	    int V, e;
	    cin >> V >> e;
	    
	    vector<Edge> g;
	    for (int i = 0; i < e; i++) {
	        int u, v, w;
	        cin >> u >> v >> w;
	        g.push_back(Edge(u, v, w));
	    }
	    
	    cout << bellman_ford(g, V, 0) << endl;
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