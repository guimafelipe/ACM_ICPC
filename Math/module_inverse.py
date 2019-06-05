def mod_inverse(a, m):
	if m == 0: return a

	if m == 1: return 0

	ans = 0
	for i in range(m):
		if (a * i) % m == 1:
			return i % m

	return -1


if __name__ == "__main__":
	T = int(input())

	for t in range(T):
		line = input().split(" ")
		for i in range(len(line)):
			line[i] = int(line[i])

		a, m = line[0], line[1]

		print(mod_inverse(a, m))