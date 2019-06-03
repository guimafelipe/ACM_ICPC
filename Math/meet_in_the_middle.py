def subsets(A):
	sets_A = []
	for i in range(len(A)):
		temp = []

		for j in range(len(sets_A)):
			temp.append(sets_A[j] + [A[i]])

		temp.append([A[i]])
		temp += sets_A

		sets_A = temp
	return [[]] + sets_A

def binary_search(A, e):
	A = [0] + A
	l = 0
	r = len(A) - 1

	while l <= r:
		m = int((l + r) / 2)

		if A[m] == e: return A[m]

		elif A[m] < e: l = m + 1

		elif A[m] > e: r = m - 1

	if A[m] > e: return A[m - 1]
	return A[m]

def meet_in_the_middle(Input, S):
	Input = list(Input)
	
	mid = int(len(Input) / 2)
	A = Input[:mid]
	B = Input[mid:]
	
	sets_A = subsets(A)
	sums_A = [sum(s) for s in sets_A]
	# print("A:", A)
	# print(sets_A)
	# print(sums_A)

	sets_B = subsets(B)
	sums_B = [sum(s) for s in sets_B]
	sums_B.sort()
	# sums_B =
	# print(B)
	# print(sets_B)
	# print(sums_B)

	ans = 0
	for s_A in sums_A:
		s_B = binary_search(sums_B, S - s_A)

		if s_A + s_B <= S:
			ans = max(ans, s_A + s_B)

	return ans

if __name__ == "__main__":
	Input = set([45, 34, 4, 12, 5, 2])
	S = 42
	# Expected output : 41 (summing 34, 5 and 2.)
	print(meet_in_the_middle(Input, S))

	Input = set([3, 34, 4, 12, 5, 2])
	S = 10
	# Expected output : 10 (summing 2, 3 and 5.)
	print(meet_in_the_middle(Input, S))