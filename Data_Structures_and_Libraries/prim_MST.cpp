{
#include <bits/stdc++.h>
using namespace std;
int spanningTree(int V,int E,vector<vector<int> > graph);
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int V,E;
        cin>>V>>E;
        vector< vector<int> > graph(V,vector<int>(V,INT_MAX));
        while(E--)
        {
            int u,v,w;
            cin>>u>>v>>w;
            u--,v--;
            graph[u][v] = w;
            graph[v][u] = w;
        }
        cout<<spanningTree(V,E,graph)<<endl;
    }
    return 0;
}

}
/*This is a function problem.You only need to complete the function given below*/
// Function to construct and print MST for
// a graph represented using adjacency
// matrix representation, with V vertices.
// graph[i][j] = weight if edge exits else INT_MAX

int get_next(vector<bool> &in_mst) {
    for (int i = 0; i < in_mst.size(); i++) {
        if (in_mst[i] == false)
            return i;
    }
    return -1;
}

int sum(vector<int> &parent, vector< vector<int> < &graph) {
    int ans = 0;
    for (int i = 0; i < parent.size(); i++)
        ans += graph[parent[i]][i];
    return ans;
}

int spanningTree(int V,int E,vector<vector<int> > graph)
{
    vector<bool> in_mst(V, false);
    vector<int> value(V, INT_MAX);
    vector<int> parent(V, -1);
    
    parent[0] = -1;
    value[0] = 0
    in_mst[0] = true;
    for (int i = 1; i < V; i++) {
        int u = get_next(in_mst);
        in_mst[u] = true;
        
        for (int v = 0; v < V; v++) {
            if (graph[u][v] && graph[u][v] < value[v]) {
                value[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }
    
    return sum(parent, graph);
}

/* variation using priority_queue with graph stored as adjacency lists
int Solution::solve(int A, vector<vector<int> > &B) {
    vector< vector< pair<int, int> > > graph(A, vector< pair<int, int> >());
    for (int i = 0; i < B.size(); i++) {
        int u = B[i][0] - 1;
        int v = B[i][1] - 1;
        int w = B[i][2];
        graph[u].push_back(make_pair(v, w));
        graph[v].push_back(make_pair(u, w));
    }
    
    vector<bool> in_mst(A, false);
    vector<int> value(A, INT_MAX);
    
    priority_queue< pair<int, int> > pq;
    
    pq.push(make_pair(0, 0));

    while ( !pq.empty() ) {
        auto curr = pq.top();
        pq.pop();
        int curr_w = -curr.first;
        int u = curr.second;
        
        in_mst[u] = true;
        value[u] = min(value[u], curr_w);
        
        for (int i = 0; i < graph[u].size(); i++) {
            int v = graph[u][i].first;
            int w = graph[u][i].second;
            
            if ( !in_mst[v] && w < value[v]) {
                value[v] = w;
                pq.push(make_pair(-w, v));
            }
        }
    }
    
    int ans = 0;
    for (int i = 0; i < value.size(); i++)
        ans += value[i];
        
    return ans;
}
*/
