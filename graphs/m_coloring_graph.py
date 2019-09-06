#code

class graph:
    def __init__(self, V, E):
        self.V = V
        self.E = E
        self.adj = []
        for v in range(V):
            self.adj.append([])
        
    def add_edge(self, u, v):
        self.adj[u].append(v)
        self.adj[v].append(u)

def is_valid(u, g, color, colors):
    for v in g.adj[u]:
        if colors[v] == color:
            return False
    return True

def is_finished(u, g, colors):
    for v in g.adj[u]:
        if colors[v] == 0:
            return False
    return True
    
def color_graph_dfs_util(u, g, m, colors):
    if colors[u] != 0:
        return True
    # print(u, colors)
    for color in range(1, m + 1):
        if is_valid(u, g, color, colors):
            colors[u] = color
            # print(colors)
            if is_finished(u, g, colors):
                return True
                
            for v in g.adj[u]:
                # if v is already colored:
                if colors[v] != 0: continue
            
                if color_graph_dfs_util(v, g, m, colors):
                    return True
                    
            colors[u] = 0
    
    return False

def color_graph_dfs(g, m, colors):
    for u in range(g.V):
        if not color_graph_dfs_util(u, g, m, colors):
            return False
        # print(colors)
    return True
        
T = int(input())

for t in range(T):
    V = int(input())
    m = int(input())
    E = int(input())
    
    g = graph(V, E)
    
    line_read = input().split(" ")
    edges = []
    for e in line_read:
        if not e.isnumeric(): continue
        edges.append(int(e))
    
    for e in range(E):
        u = edges[2*e] - 1
        v = edges[2*e + 1] - 1
        g.add_edge(u, v)
        # print(u, v)
    
    colors = [0] * V
    
    if color_graph_dfs(g, m, colors):
        print(1)
    else:
        print(0)
    
    # print(colors)

# input:

# 2
# 4
# 3
# 5
# 1 2 2 3 3 4 4 1 1 3
# 3
# 2
# 3
# 1 2 2 3 1 3

# expected output:

# 1
# 0