#include <bits/stdc++.h>

typedef long long int ll;

using namespace std;


void print(int *A, int N) {
	for (int i = 0; i < N; i++)
		printf("%d ", A[i]);
	printf("\n");
}

ll merge(int *A, int l, int mid, int r) {
	int a = mid - l + 1;
	int b = r - mid;
	
	int temp_A[a];
	for (int i = 0; i < a; i++) {
		temp_A[i] = A[l + i];
	}

	int i, j, k;
	ll count = 0;
	for (i = 0, j = mid + 1, k = l; i < a && j <= r;) {
		if (temp_A[i] <= A[j])
			A[k++] = temp_A[i++];
		else {
			count += (ll)((mid - l) - i + 1);
			A[k++] = A[j++];
		}
	}

	while (i < a)
		A[k++] = temp_A[i++];

	while (j <= r)
		A[k++] = A[j++];

	return count;
}

ll merge_sort(int *A, int l, int r) {
	if (l >= r) return 0;
	int mid = (l + r) / 2;

	ll l_count = merge_sort(A, l, mid);
	ll r_count = merge_sort(A, mid + 1, r);
	ll merge_count = merge(A, l, mid, r);

	return l_count + r_count + merge_count;
}


int main() {
	// test case

	// vector<int> input({1, 7, 9, 2, 5, 0, 4, 13, 3});
	// merge_sort(input, 0, input.size() - 1);

	// print(input);


	// input.txt

	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		int N;
		cin >> N;

		int *A;
		A = (int *)malloc(N * sizeof(int));

		for (int n = 0; n < N; n++) {
			cin >> A[n];
		}

		ll ans = merge_sort(A, 0, N - 1);
		// print(A, N);
		printf("%lld\n", ans);
	}

	return 0;
}
