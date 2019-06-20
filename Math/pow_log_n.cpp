#include <bits/stdc++.h>

using namespace std;


float power(float x, int y) {
	if (y == 0) return 1;

	float half = power(x, y / 2);

	if (y % 2 == 0)
		return half * half;
	else {
		if (y > 0) return x * half * half;
		if (y < 0) return half * half / x;
	}
}

int main() {
	float x = 2;
	int y = -3;
	cout << power(x, y) << endl;

	x = 2;
	y = 3;
	cout << power(x, y) << endl;

	x = 7;
	y = 2;
	cout << power(x, y) << endl;

	return 0;
}