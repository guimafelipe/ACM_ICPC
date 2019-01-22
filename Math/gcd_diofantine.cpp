#include <bits/stdc++.h>

using namespace std;

// ***************************************************
// gcd Greatest Common Divisor - diophantine equation
// 最大公约数 - 丢番图方程
// ***************************************************

int gcd(int a, int b, int &x, int &y) {
	if (a == 0) {
		x = 0;
		y = 1;
		return b;
	}

	int x1;
	int y1;
	int c = gcd(b % a, a, x1, y1);
	y = x1;
	x = y1 - (b / a) * x1;

	return c;
}

int GCD(int a, int b) {
	if (a == 0) return b;

	return GCD(b % a, a);
}

// *************************
// lcm Least Common Multiple
// 最小公倍数
// *************************

int lcm(int a, int b) {
	return a * b / GCD(a, b);
}

int main() {
	printf("%d\n", GCD(6, 0));
	printf("%d\n", GCD(0, 6));
	printf("%d\n", lcm(6, 0));
	printf("%d\n", lcm(0, 6));
}
