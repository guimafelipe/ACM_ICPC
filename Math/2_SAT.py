# No O.J.
class graph:
	def __init__(self, v):
		self.V = v
		self.adj = [[] for i in range(self.V + 1)]

	def neg(self, v):
		n = int(self.V / 2)
		if v <= n: return v + n
		else: return v - n

	def add_edge(self, u, v):
		n = int(self.V / 2)
		if u < 0: u = -u + n
		if v < 0: v = -v + n
		
		self.adj[u].append(v)

	def get_transpose(self):
		g_t = graph(self.V)

		for v in range(self.V):
			for u in self.adj[v]:
				g_t.add_edge(u, v)

		return g_t

	def fill_order(self, v, visited, S):
		visited[v] = True

		for u in self.adj[v]:
			if not visited[u]:
				self.fill_order(u, visited, S)

		S.append(v)

	def dfs_util(self, scc, v, visited):
		visited[v] = True

		for u in self.adj[v]:
			if not visited[u]:
				self.dfs_util(scc, u, visited)

		scc.append(v)

	def SCCs(self):
		ans = []

		S = []

		g_t = self.get_transpose()

		visited = [False] * (self.V + 1)

		for v in range(self.V):
			if not visited[v]:
				self.fill_order(v, visited, S)

		visited = [False] * (self.V + 1)

		while len(S) > 0:
			curr = S.pop()

			scc = []
			if not visited[curr]:
				g_t.dfs_util(scc, curr, visited)
				ans.append(scc)

		return ans


def is_2_SAT(n, m, a, b):
	g = graph(2 * n)

	for i in range(m):
		g.add_edge(-a[i], b[i])
		g.add_edge(-b[i], a[i])

	SCCs = g.SCCs()

	for scc in SCCs:
		scc_set = set(scc)

		for e in scc_set:
			if g.neg(e) in scc_set:
				return False

	return True


if __name__ == "__main__":
	# test #1
	n = 5
	m = 7
	a = [1, -2, -1, 3, -3, -4, -3]
	b = [2, 3, -2, 4, 5, -5, 4]

	print(is_2_SAT(n, m, a, b))

	# test #2
	n = 2
	m = 3
	a = [1, 2, -1]
	b = [2, -1, -2]

	print(is_2_SAT(n, m, a, b))

	# test #3
	n = 2
	m = 4
	a = [1, -1, 1, -1]
	b = [2, 2, -2, -2]

	print(is_2_SAT(n, m, a, b))