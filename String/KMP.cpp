// lucas1jorge

#include <bits/stdc++.h>

using namespace std;


void print(vector<int> A) {
	for (int i = 0; i < A.size(); i++)
		printf("%d ", A[i]);
	printf("\n");
}

vector<int> LPS(string pat) {
	vector<int> ans(pat.size());

	ans[0] = 0;
	int j = 0;
	int i = 1;

	while (i < pat.size()) {
		if (pat[i] == pat[j])
			ans[i++] = ++j;
		else if (j == 0)
			ans[i++] = 0;
		else
			j = ans[j-1];
	}

	return ans;
}

int KMP(string txt, string pat) {
	vector<int> lps = LPS(pat);
	// print(lps);

	int i = 0;
	int j = 0;

	while (i < txt.size()) {
		if (j == pat.size()) return i - j;

		if (txt[i] == pat[j]) {
			i++;
			j++;
		}
		else {
			if (j == 0)
				i++;
			else
				j = lps[j-1];
		}
	}
	if (j == pat.size()) return i - j;

	return -1;
}


int main() {
	string txt = "ABABDABACDABABCABAB";
	string pat = "ABABCABAB";

	int ans = KMP(txt, pat);

	printf("%d\n", ans);

	return 0;
}
