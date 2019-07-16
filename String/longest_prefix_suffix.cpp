#include <bits/stdc++.h>

using namespace std;

void print(vector<int> &A) {
	for (int i = 0; i < A.size(); i++)
		printf("%d ", A[i]);
	printf("\n");
}

int get_max(vector<int> &A) {
	int ans = 0;
	
	for (int i = 0; i < A.size(); i++) {
		ans = max(ans, A[i]);
	}

	return ans;
}

int lps(string str) {
	vector<int> lps(str.size(), 0);

	int i = 1;
	int j = 0;
	while (i < str.size()) {
		if (str[i] == str[j]) {
			j++;
			lps[i] = j;
			i++;
		}
		else {
			if (j > 0)
				j = lps[j - 1];
			else {
				lps[i] = 0;
				i++;
			}
		}
	}

	// print(lps);
	// return get_max(lps);

	return lps[str.size() - 1];
}

int main() {
	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		string str;
		cin >> str;

		printf("%d\n", lps(str));
	}

	return 0;
}