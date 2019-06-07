#include <bits/stdc++.h>

using namespace std;


void print(vector<int> &A) {
	for (int i = 0; i < A.size(); i++)
		printf("%d ", A[i]);
	printf("\n");
}

void print2(vector< vector<int> > &m) {
	for (int i = 0; i < m.size(); i++)
		print(m[i]);
}

bool is_subset_sum(vector<int> input) {
	int sum = 0;
	for (int i = 0; i < input.size(); i++)
		sum += input[i];

	if (sum % 2 != 0) return false;

	int half = sum / 2;

	int n = input.size();
	int s = half;

	vector< vector<int> > dp(n + 1, vector<int>(s + 1));

	for (int i = 0; i <= n; i++) {
		dp[i][0] = true;
	}

	for (int j = 1; j <= s; j++) {
		dp[0][j] = false;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= s; j++) {
			if (j < input[i - 1])
				dp[i][j] = dp[i-1][j];
			else
				dp[i][j] = dp[i-1][j] || dp[i-1][j - input[i - 1]];
		}
	}

	// print2(dp);

	return dp[n][s];
}

int main() {
	// set<int> set_input({3, 34, 4, 12, 5, 2});
	// int sum = 9;

	int T;
	scanf("%d", &T);
	for (int t = 0; t < T; t++) {
		int n;
		scanf("%d", &n);

		vector<int> input(n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &input[i]);
		}

		bool ans = is_subset_sum(input);
	
		if (ans) printf("YES\n");
		else printf("NO\n");
	}

	return 0;
}