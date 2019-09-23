#include <iostream>
#include <vector>
using namespace std;

#define INF 10000000

void print(vector<int> &A) {
    for (int i = 0; i < A.size(); i++)
        if (A[i] >= INF)
            printf("INF ");
        else
            printf("%d ", A[i]);
    printf("\n");
}

void print_matrix(vector< vector<int> > &m) {
    for (int i = 0; i < m.size(); i++)
        print(m[i]);
    // printf("\n");
}

void floyd_warshall(vector< vector<int> > &g) {
    for (int k = 0; k < g.size(); k++)
        for (int i = 0; i < g.size(); i++)
            for (int j = 0; j < g.size(); j++)
                if (g[i][k] < INF && g[k][j] < INF && g[i][j] > g[i][k] + g[k][j])
                    g[i][j] = g[i][k] + g[k][j];
} 

int main() {
	//code
	int T;
	cin >> T;
	
	for (int t = 0; t < T; t++) {
	    int V;
	    cin >> V;
	    vector< vector<int> > g(V, vector<int>(V));
	    
	    for (int i = 0; i < V; i++)
	        for (int j = 0; j < V; j++)
	            cin >> g[i][j];
	   
	    floyd_warshall(g);
	    
        print_matrix(g);
	}
	
	return 0;
}