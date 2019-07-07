class Bit_tree:
	def __init__(self, A):
		self.n = len(A)
		self.bit_tree = [0] * self.n

		for i in range(self.n):
			self.update(i, A[i])

	def update(self, index, val):
		index += 1

		while index <= self.n:
			self.bit_tree[index - 1] += val
			index += index & -index

	def get_sum(self, index):
		index += 1

		ans = 0
		while index > 0:
			ans += self.bit_tree[index - 1]
			index -= (index & -index)

		return ans


if __name__ == "__main__":
	A = [2, 1, 1, 3, 2, 3, 4, 5, 6, 7, 8, 9]

	BIT = Bit_tree(A)

	print(BIT.bit_tree)

	print(BIT.get_sum(5))

	A[3] += 6
	BIT.update(3, 6)

	print(BIT.get_sum(5))

	print(BIT.get_sum(5) - BIT.get_sum(4))