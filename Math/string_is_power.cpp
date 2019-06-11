#include <bits/stdc++.h>

using namespace std;


int str_mod(string A, int m) {
	int r = 0;

	for (int i = 0; i < A.size(); i++) {
		r = 10 * r + (A[i] - '0');
		r %= m;
	}

	return r;
}

string str_div(string A, int d) {
	string ans = "";

	int q = 0;
	int rem = 0;
	for (int i = 0; i < A.size(); i++) {
		rem = 10 * rem + (A[i] - '0');
		q = rem / d;
		rem = rem % d;
		ans += q + '0';
	}

	int start = 0;
	while (start < ans.size() && ans[start] == '0') start += 1;
	if (start != ans.size()) ans = ans.substr(start);

	return ans;
}


int power(string A, int pow) {
	while (A != "1" && A != "0") {
		if (str_mod(A, pow) == 1) return 0;
		A = str_div(A, pow);
		// cout << A << endl;
	}

	return 1;
}


int main() {
	string A = "27";
	// cout << str_div(A, 2) << endl;
	// cout << str_mod(A, 2) << endl;
	cout << power(A, 3) << endl;

	return 0;
}
