# Idea: the farther node of any node MUST BE one of the 2 end points of the diameter

import math

class node:
	def __init__(self, val):
		self.val = val
		self.left = None
		self.right = None

def bfs(root, neighborns, distances):
	if root == None:
		return

	queue = [root]
	distances[root] = 0

	while len(queue) > 0:
		curr = queue.pop(0)
		dist = distances[curr]

		for n in neighborns[curr]:
			if not n in distances:
				distances[n] = dist + 1
				queue.append(n)

class Solution:
	# @param A : list of integers
	# @return an integer
	def solve(self, A):
		neighborns = {}

		for i in range(len(A)):
			neighborns[i] = []

		root = -1
		for i in range(len(A)):
			if A[i] == -1:
				root = i
			else:
				neighborns[A[i]].append(i)
				neighborns[i].append(A[i])

		distances = {}
		bfs(root, neighborns, distances)

		farther = root
		for key in distances.keys():
			if distances[key] > distances[farther]:
				farther = key

		# print(farther)

		distances = {}
		bfs(farther, neighborns, distances)

		for key in distances.keys():
			if distances[key] > distances[farther]:
				farther = key

		# print(farther)

		return distances[farther]
		

if __name__ == "__main__":
	P = [-1, 0, 0, 0, 3]
	print(Solution.solve(Solution, P))