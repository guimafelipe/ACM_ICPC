#include <bits/stdc++.h>

using namespace std;


int horner(vector<int> &poly, int x) {
	if (poly.size() == 0) return 0;

	long long mod = 1000000007;
	long long ans = (long long)poly[0];
	for (int i = 1; i < poly.size(); i++) {
		ans = ((ans * (long long)x) % mod + (long long)poly[i]) % mod;
	}

	return (int)ans;
}


int main() {
	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		int N;
		cin >> N;

		vector<int> poly(N);
		for (int n = 0; n < N; n++) {
			cin >> poly[n];
		}

		int x;
		cin >> x;

		printf("%d\n", horner(poly, x));
	}

	return 0;
}