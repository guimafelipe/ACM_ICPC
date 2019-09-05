class edge:
	def __init__(self, u, v, w):
		self.u = u
		self.v = v
		self.w = w

class graph:
	def __init__(self, V, E):
		self.V = V
		self.E = E
		self.edges = []

	def add_edge(self, u, v, w):
		self.edges.append(edge(u, v, w))

def edges_cmp(e1, e2):
	if e1.w < e2.w:
		return -1
	if e1.w > e2.w:
		return 1
	return 0

def cmp_to_key(mycmp):
    'Convert a cmp= function into a key= function'
    class K(object):
        def __init__(self, obj, *args):
            self.obj = obj
        def __lt__(self, other):
            return mycmp(self.obj, other.obj) < 0
        def __gt__(self, other):
            return mycmp(self.obj, other.obj) > 0
        def __eq__(self, other):
            return mycmp(self.obj, other.obj) == 0
        def __le__(self, other):
            return mycmp(self.obj, other.obj) <= 0
        def __ge__(self, other):
            return mycmp(self.obj, other.obj) >= 0
        def __ne__(self, other):
            return mycmp(self.obj, other.obj) != 0
    return K

def find(e, parents):
	if parents[e] != e:
		parents[e] = find(parents[e], parents)
	return parents[e]

def union(x, y, parents, rank):
	if rank[x] < rank[y]:
		parents[x] = y
	elif rank[x] > rank[y]:
		parents[y] = x
	else:
		parents[x] = y
		rank[y] += 1

def kruskal_mst(g):
	g.edges.sort(key=cmp_to_key(edges_cmp))

	parents = [i for i in range(g.V)]
	rank = [0 for i in range(g.V)]

	ans = []
	for edge in g.edges:
		x = find(edge.u, parents)
		y = find(edge.v, parents)
		# print("edge:", edge.u, edge.v, edge.w, "x, y:", x, y)
		if x != y:
			ans.append(edge)
			union(x, y, parents, rank)

		if len(ans) == g.V - 1:
			break

	return ans

if __name__ == "__main__":
	# test 1

	# V = 4
	# E = 5
	# g = graph(V, E)

	# g.add_edge(0, 1, 10)
	# g.add_edge(0, 2, 6)
	# g.add_edge(0, 3, 5)
	# g.add_edge(1, 3, 15)
	# g.add_edge(2, 3, 4)


	# test 2

	V = 9
	E = 14
	g = graph(V, E)

	g.add_edge(7, 6, 1)
	g.add_edge(8, 2, 2)
	g.add_edge(6, 5, 2)
	g.add_edge(0, 1, 4)
	g.add_edge(2, 5, 4)
	g.add_edge(8, 6, 6)
	g.add_edge(2, 3, 7)
	g.add_edge(7, 8, 7)
	g.add_edge(0, 7, 8)
	g.add_edge(1, 2, 8)
	g.add_edge(3, 4, 9)
	g.add_edge(5, 4, 10)
	g.add_edge(1, 7, 11)
	g.add_edge(3, 5, 14)

	ans = kruskal_mst(g)

	for edge in ans:
		print(edge.u, edge.v, edge.w)