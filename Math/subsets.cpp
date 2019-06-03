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


vector< vector<int> > subsets(vector<int> &A) {
	vector< vector<int> > ans;
	vector<int> empty;
	ans.push_back(empty);

	for (int i = 0; i < A.size(); i++) {
		vector< vector<int> > temp;

		for (int j = 0; j < ans.size(); j++) {
			vector<int> curr = ans[j];
			curr.push_back(A[i]);
			temp.push_back(curr);
		}

		temp.insert(temp.end(), ans.begin(), ans.end());
		// temp.push_back(vector<int>(A[i]));

		ans = temp;
	}

	return ans;
}


int main() {
	vector<int> A({1, 2, 3, 4, 5});

	vector< vector<int> > ans = subsets(A);
	sort(ans.begin(), ans.end());
	
	print2(ans);
	printf("size: %d\n", ans.size());

	return 0;
}