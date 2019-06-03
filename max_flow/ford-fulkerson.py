import math

class Graph:
	def __init__(self, graph):
		self.graph = graph
		self.V = len(graph)

	def bfs(self, source, sink, parents):
		visited = [False] * self.V

		queue = [source]
		# visited[source] = True
		while len(queue) > 0:
			u = queue.pop(0)
			visited[u] = True

			for v, w in enumerate(self.graph[u]):
				if w > 0 and not visited[v]:
					parents[v] = u
					# visited[v] = True
					queue.append(v)

		# print(visited)
		# print(parents)
		return visited[sink]

	def ford_fulkerson(self, source, sink):
		parents = [None] * self.V

		max_flow = 0
		
		while self.bfs(source, sink, parents):
			path_flow = math.inf

			curr = sink
			while curr != source:
				path_flow = min(path_flow, self.graph[parents[curr]][curr])
				curr = parents[curr]

			max_flow += path_flow

			curr = sink
			while curr != source:
				self.graph[parents[curr]][curr] -= path_flow
				self.graph[curr][parents[curr]] += path_flow
				curr = parents[curr]

		# yield max_flow
		return max_flow


if __name__ == "__main__":
	# graph = [[0, 16, 13, 0, 0, 0], 
	# 		[0, 0, 10, 12, 0, 0], 
	# 		[0, 4, 0, 0, 14, 0], 
	# 		[0, 0, 9, 0, 0, 20], 
	# 		[0, 0, 0, 7, 0, 4], 
	# 		[0, 0, 0, 0, 0, 0]]

	# G = Graph(graph)

	# print(G.ford_fulkerson(0, 5))

	T = int(input())
	for t in range(T):
		NM = input().split(" ")
		N, M = int(NM[0]), int(NM[1])

		graph = [[0 for j in range(N + 1)] for i in range(N + 1)]

		triplets = input().split(" ")
		for m in range(M):
			i = 3 * m
			u, v, w = int(triplets[i]), int(triplets[i + 1]), int(triplets[i + 2])

			graph[u][v] += w
			graph[v][u] += w

		# for line in graph:
		# 	print(line)

		G = Graph(graph)

		# print("max_flow:", G.ford_fulkerson(1, N))
		# print()
		print(G.ford_fulkerson(1, N))