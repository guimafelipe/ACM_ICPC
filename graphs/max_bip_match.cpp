bool bpm(bool bpGraph[M][N], int u, vector<int> &matching, vector<bool> &visited) {
    for (int v = 0; v < matching.size(); v++) {
        if (bpGraph[u][v] && !visited[v]) {
            visited[v] = true;
            
            if (matching[v] == -1 || bpm(bpGraph, matching[v], matching, visited)) {
                matching[v] = u;
                return true;
            }
        }
    }
    
    return false;
}

int maxBPM(bool bpGraph[M][N],int m,int n)
{
//add code here.
    vector<int> matching(n, -1);
    
    int ans = 0;
    for (int i = 0; i < m; i++) {
        vector<bool> visited(m, false);
        
        if (bpm(bpGraph, i, matching, visited))
            ans++;
    }
    
    return ans;
}