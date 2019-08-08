#include <bits/stdc++.h>

using namespace std;

bool is_cyclic_util(int i, vector< vector<int> > &graph, vector<bool> &visited, vector<bool> &in_stack) {
    cout << "curr: " << i << endl;
    if ( !visited[i] ) {
        visited[i] = true;
        in_stack[i] = true;
        
        for (int j = 0; j < graph[i].size(); j++) {
            int child = graph[i][j];
            cout << "child: " << child << endl;
            if (visited[child] && in_stack[child])
                return true;
            else if (!visited[child] && is_cyclic_util(child, graph, visited, in_stack))
                return true;
        }
    }
    
    in_stack[i] = false;
    return false;
}

bool is_cyclic(int A, vector< vector<int> > &graph) {
    vector<bool> visited(A, false);
    vector<bool> in_stack(A, false);
    
    for (int i = 0; i < A; i++)
        if (is_cyclic_util(i, graph, visited, in_stack))
            return true;
    
    return false;
}

int solve(int A, vector<int> &B, vector<int> &C) {
    vector< vector<int> > graph(A, vector<int>(A, 0));
    
    for (int i = 0; i < B.size(); i++) {
        graph[B[i] - 1][C[i] - 1] = 1;
    }
    
    return !is_cyclic(A, graph);
}

int main() {
    int A = 5;
    vector<int> B({1, 3, 4, 5});
    vector<int> C({2, 1, 5, 3});

    cout << solve(A, B, C) << endl;

    return 0;
}