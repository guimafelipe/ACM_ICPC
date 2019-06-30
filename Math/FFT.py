import cmath

def FFT(pol):
	n = len(pol)

	if n == 1: return [pol[0]]

	w = [0] * n
	for i in range(n):
		theta = 2 * cmath.pi * i / n
		w[i] = complex(cmath.cos(theta), cmath.sin(theta))

	even = [0] * int(n / 2)
	odd = [0] * int(n / 2)
	for i in range(len(even)):
		even[i] = pol[2 * i]
		odd[i] = pol[2 * i + 1]
	if n % 2 == 1: even.append(pol[-1])

	fft_0 = FFT(even)
	fft_1 = FFT(odd)

	fft = [0] * n
	for i in range(int(n / 2)):
		fft[i] = fft_0[i] + w[i] * fft_1[i]
		fft[i + int(n / 2)] = fft_0[i] + w[i + int(n / 2)] * fft_1[i]

	return fft



if __name__ == "__main__":
	pol = [1, 2, 3, 4]

	fft = FFT(pol)
	
	for e in fft:
		print(f"{e}")