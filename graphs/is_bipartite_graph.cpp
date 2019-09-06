bool is_bipartite_util(int G[][MAX], int V, int u, vector<int> &colors) {
    for (int v = 0; v < MAX; v++)
        if (G[u][v])
            if (colors[v] == colors[u])
                return false;
            else if (colors[v] == -1) {
                colors[v] = 1 - colors[u];
                if ( !is_bipartite_util(G, V, v, colors) )
                    return false;
            }
    
    return true;
}

bool isBipartite(int G[][MAX],int V)
{
    //Your code here
    vector<int> colors(V, -1);
    
    for (int i = 0; i < V; i++) {
        if (colors[i] == -1)
            colors[i] = 0;
        if ( !is_bipartite_util(G, V, i, colors))
            return false;
    }
        
    return true;
}