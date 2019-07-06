def kadane(A):
	if len(A) == 0: return 0
	
	ans = A[0]
	curr_sum = 0

	for e in A:
		curr_sum += e

		ans = max(ans, curr_sum)

		if curr_sum < 0:
			curr_sum = 0

	return ans

if __name__ == "__main__":
	# test case:

	# A = [-2, -3, 4, -1, -2, 1, 5, -3]

	# print(kadane(A))

	# input.txt:

	T = int(input())
	for t in range(T):
		N = int(input())

		line = input().split(" ")

		A = []
		for e in line:
			if len(e) == 0:
				continue

			# print(e)
			A.append(int(e))

		print(kadane(A))