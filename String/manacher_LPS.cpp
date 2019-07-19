#include <bits/stdc++.h>

using namespace std;

string LPS(string &A) {
	int n = A.size();

	if (n == 0) return "";

	n = 2 * n + 1;

	vector<int> LPS(n, 0);
	LPS[0] = 0;
	LPS[1] = 1;

	int center = 1;
	int cen_right = 2;
	int cur_left;
	int max_LPS_len = 0;
	int max_LPS_center = 0;

	for (int i = 1; i < n; i++) { // i is the cur_right
		cur_left = 2 * center - i;
		LPS[i] = 0;
		int diff = cen_right - i;

		if (diff > 0)
			LPS[i] = min(LPS[cur_left], diff);

		while ((i + LPS[i] < n && i - LPS[i] > 0) && (((i + LPS[i]) % 2 == 1) || (A[(i + LPS[i] + 1) / 2] == A[(i - LPS[i] - 1) / 2])))
			LPS[i]++;

		if (LPS[i] > max_LPS_len) {
			max_LPS_len = LPS[i];
			max_LPS_center = i;
		}

		if (i + LPS[i] > cen_right) {
			cen_right = i + LPS[i];
			center = i;
		}
	}

	int start = (max_LPS_center - max_LPS_len) / 2;

	return A.substr(start, max_LPS_len);
}

int main() {
	// string A = "babcbabcbaccba";
	// cout << LPS(A) << endl;

	// string B = "abaaba";
	// cout << LPS(B) << endl;

	// string C = "abababa";
	// cout << LPS(C) << endl;

	// string D = "abcbabcbabcba";
	// cout << LPS(D) << endl;

	// string E = "forgeeksskeegfor";
	// cout << LPS(E) << endl;

	// string F = "caba";
	// cout << LPS(F) << endl;

	// string G = "abacdfgdcaba";
	// cout << LPS(G) << endl;

	// string H = "abacdfgdcabba";
	// cout << LPS(H) << endl;

	// string I = "abacdedcaba";
	// cout << LPS(I) << endl;

	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		string str;
		cin >> str;
		cout << LPS(str) << endl;
	}

	return 0;
}