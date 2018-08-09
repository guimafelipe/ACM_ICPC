class segment_tree:
	def __init__(self, A):
		self.A = A
		self.st = [0] * 4 * len(A)
		self.build(0, 0, len(A)-1, A)


	def build(self, u, l, r, A):
		print(u, l, r)
		if l == r:
			self.st[u] = A[l]
			return

		m = int((l + r) / 2)

		self.build(2*u+1, l, m, A)
		self.build(2*u+2, m+1, r, A)

		self.st[u] = self.st[2*u+1] + self.st[2*u+2]


	def update(self, i, v):
		self.update_recursion(0, 0, len(self.A) - 1, i, v)

	def update_recursion(self, u, l, r, i, v):
		if i < l or r < i: return

		if l == r:
			self.st[u] = v
			return

		m = int((l + r) / 2)

		self.update_recursion(2*u+1, l, m, i, v)
		self.update_recursion(2*u+2, m+1, r, i, v)

		self.st[u] = self.st[2*u+1] + self.st[2*u+2]


	def querry(self, a, b):
		return self.querry_recursion(0, 0, len(self.A)-1, a, b)

	def querry_recursion(self, u, l, r, a, b):
		if b < l or r < a: return 0

		if a <= l and r <= b: return self.st[u]

		m = int((l + r) / 2)

		if b < m:
			return self.querry_recursion(2*u+1, l, m, a, b)

		elif m < a:
			return self.querry_recursion(2*u+2, m+1, r, a, b)

		else:
			left = self.querry_recursion(2*u+1, l, m, a, b)
			right = self.querry_recursion(2*u+2, m+1, r, a, b)
			return left + right


if __name__ == "__main__":
	A = [1, 2, 2, 3, 5, 4, 1, 0, 4]

	st = segment_tree(A)
	print(st.st)

	st.update(0, 5)
	print(st.st)

	print(st.querry(0, 0))
	print(st.querry(2, 5))
	print(st.querry(0, 8))
	print(st.querry(6, 8))