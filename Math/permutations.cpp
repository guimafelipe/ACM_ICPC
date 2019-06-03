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

void permutations_util(vector< vector<int> > &ans, vector<int> &A, int start) {
	if (start == A.size()) {
		ans.push_back(A);
	}
	else {
		for (int i = start; i < A.size(); i++) {
			swap(A[start], A[i]);
			permutations_util(ans, A, start + 1);
			swap(A[start], A[i]);
		}
	}
}

vector< vector<int> > permutations(vector<int> &A) {
	vector< vector<int> > ans;

	permutations_util(ans, A, 0);

	return ans;
}


int main() {
	vector<int> A({1, 2, 3, 4});

	vector< vector<int> > ans = permutations(A);
	print2(ans);

	return 0;
}