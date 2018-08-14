class segment_tree:
	def __init__(self, A):
		self.N = len(A)
		self.st = [0] * 4 * len(A)
		self.lazy = [0] * 4 * len(A)
		self.build(0, 0, len(A)-1, A)


	def build(self, u, l, r, A):
		if l == r:
			self.st[u] = A[l]
			return

		m = int((l + r) / 2)

		self.build(2*u+1, l, m, A)
		self.build(2*u+2, m+1, r, A)

		self.st[u] = self.st[2*u+1] + self.st[2*u+2]


	def update(self, i, v):
		self.update_recursion(0, 0, self.N - 1, i, v)

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
		return self.querry_recursion(0, 0, self.N-1, a, b)

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


	def update_range_recursion(self, u, l, r, si, ei, diff):
		# pending update
		if self.lazy[u] != 0:
			self.st[u] += (r - l + 1) * self.lazy[u]

			if l != r:
				self.lazy[2*u+1] += self.lazy[u]
				self.lazy[2*u+2] += self.lazy[u]

			self.lazy[u] = 0

		# out of range
		if l > r or r < si or ei < l:
			return

		# fully in range:
		if si <= l and r <= ei:
			self.st[u] += (r - l + 1) * diff

			if l != r:
				self.lazy[2*u+1] += diff
				self.lazy[2*u+2] += diff
			return

		# overlaps:
		m = int((l + r) / 2)
		self.update_range_recursion(2*u+1, l, m, si, ei, diff)
		self.update_range_recursion(2*u+2, m+1, r, si, ei, diff)

		self.st[u] = self.st[2*u+1] + self.st[2*u+2]

	def update_range(self, si, ei, diff):
		self.update_range_recursion(0, 0, self.N-1, si, ei, diff)


	def querry_range_recursion(self, u, l, r, a, b):
		# pending update
		if self.lazy[u] != 0:
			self.st[u] += (r - l + 1) * self.lazy[u]

			if l != r:
				self.lazy[2*u+1] += self.lazy[u]
				self.lazy[2*u+2] += self.lazy[u]

			self.lazy[u] = 0

		# out of range
		if l > r or r < a or b < l:
			return 0

		# fully in range
		if a <= l and r <= b:
			return self.st[u]

		# overlaps
		m = int((l + r) / 2)
		return self.querry_range_recursion(2*u+1, l, m, a, b) \
				+ self.querry_range_recursion(2*u+2, m+1, r, a, b)

	def querry_range(self, a, b):
		return self.querry_range_recursion(0, 0, self.N-1, a, b)


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

	print()
	st.update_range(0, 8, 1)

	print(st.querry_range(0, 0))
	print(st.querry_range(2, 5))
	print(st.querry_range(0, 8))
	print(st.querry_range(6, 8))

	# print(st.st)
	# print(st.lazy)

	# A = [1, 3, 5, 7, 9, 11]

	# st = segment_tree(A)

	# print("Sum of values in given range = {}".format(st.querry_range(1, 3)))

	# st.update_range(1, 5, 10)

	# print("Updated sum of values in given range = {}".format(st.querry_range(1, 3)))