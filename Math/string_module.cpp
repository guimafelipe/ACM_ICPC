#include <bits/stdc++.h>

using namespace std;

int string_module(string str, int m) {
	int r = 0;

	for (int i = 0; i < str.size(); i++) {
		r = 10 * r + (str[i] - '0');
		r %= m;
	}

	return r;
}

int main() {
	printf("%d\n", string_module("19", 5));
	printf("%d\n", string_module("12", 7));

	return 0;
}