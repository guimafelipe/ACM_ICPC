#include <bits/stdc++.h>

using namespace std;


vector<int> factorial(int n) {
	vector<int> ans(n);

	ans[0] = 1;
	for (int i = 1; i < n; i++)
		ans[i] = i * ans[i - 1];

	return ans;
}

int lex_rank(string A) {
	int ans = 0;
	int n = A.size();

	vector<int> fact = factorial(n);

	for (int i = 0; i < n; i++) {
		
		int smaller = 0;
		for (int j = i + 1; j < n; j++) {
			if (A[j] < A[i]) smaller++;
		}

		ans += smaller * fact[n - i - 1];
	}

	return ans + 1;
}


int main() {
	cout << lex_rank("acb") << endl;

	return 0;
}