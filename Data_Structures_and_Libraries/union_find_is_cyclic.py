class edge:
	def __init__(self, u, v):
		self.u = u
		self.v = v

class graph:
	def __init__(self, V, E):
		self.V = V
		self.E = E
		self.edges = []

	def add_edge(self, u, v):
		self.edges.append(edge(u, v))

def find(parents, i):
	if parents[i] == i:
		return parents[i]
	parents[i] = find(parents, parents[i])
	return parents[i]

def union(parents, x, y):
	x_set = find(parents, x)
	y_set = find(parents, y)

	if x_set != y_set:
		parents[x_set] = y_set

def is_cyclic(gr):
	parents = [i for i in range(gr.V)]

	for i in range(gr.E):
		x = find(parents, gr.edges[i].u)
		y = find(parents, gr.edges[i].v)

		if x == y:
			return True;

		union(parents, x, y)

	return False


if __name__ == "__main__":
	V = 4
	E = 3

	gr = graph(V, E)
	gr.add_edge(0, 1)
	gr.add_edge(1, 2)
	gr.add_edge(0, 2)

	print(is_cyclic(gr))