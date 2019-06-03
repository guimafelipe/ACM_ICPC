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
	printf("\n");
}

void combinations_util(vector< vector<int> > &ans, vector<int> &curr, vector<int> &A, int k, int start) {
	if (curr.size() == k) {
		ans.push_back(curr);
	}
	else {
		for (int i = start; i < A.size(); i++) {
			curr.push_back(A[i]);
			combinations_util(ans, curr, A, k, i + 1);
			curr.pop_back();
		}
	}
}

vector< vector<int> > combinations(vector<int> &A, int k) {
	vector< vector<int> > ans;

	vector<int> curr;
	combinations_util(ans, curr, A, k, 0);

	return ans;
}


int main() {
	vector<int> A({1, 2, 3, 4, 5});

	vector< vector<int> > ans = combinations(A, 3);
	print2(ans);

	return 0;
}