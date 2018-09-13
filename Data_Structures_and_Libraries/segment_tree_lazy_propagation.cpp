#include <bits/stdc++.h>

using namespace std;

#define INF 1000000000
#define INFLL 0x3f3f3f3f3f3f3f3fLL 
#define EPS 10e-9
#define MOD 1000000007
#define mp make_pair
#define mt make_tuple
#define pb push_back
// #define st first
#define nd second
#define sz(v) int(v.size())
#define all(X) (X).begin(), (X).end()

typedef long long ll;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<iii> viii;
typedef vector<ll> vll;


class segment_tree {
public:
	int N;
	vi st;
	vi lazy;

	segment_tree(vi A) {
		N = A.size();
		st = vi(4 * N);
		lazy = vi(4 * N);
		build(0, 0, N - 1, A);
	};

	void build(int u, int l, int r, vi A) {
		if (l == r) {
			st[u] = A[l];
			return;
		}

		int m = (l + r) / 2;

		build(2*u+1, l, m, A);
		build(2*u+2, m+1, r, A);

		st[u] = st[2*u+1] + st[2*u+2];
	}

	void update(int i, int v) {
		update_recursion(0, 0, N-1, i, v);
	}

	void update_recursion(int u, int l, int r, int i, int v) {
		if (i < l || r < i) return;

		if (l == r) {
			st[u] = v;
			return;
		}

		int m = (l + r) / 2;

		update_recursion(2*u+1, l, m, i, v);
		update_recursion(2*u+2, m+1, r, i, v);

		st[u] = st[2*u+1] + st[2*u+2];
	}

	int query(int a, int b) {
		return query_recursion(0, 0, N-1, a, b);
	}

	int query_recursion(int u, int l, int r, int a, int b) {
		if (b < l || r < a) return 0;

		if (a <= l && r <= b) return st[u];

		int m = (l + r) / 2;

		int left = query_recursion(2*u+1, l, m, a, b);
		int right = query_recursion(2*u+2, m+1, r, a, b);

		if (b < m) return left;
		else if (m < a) return right;
		else return left + right;
	}

	// lazy propagation:

	void update_range(int si, int ei, int diff) {
		return update_range_recursion(0, 0, N-1, si, ei, diff);
	}

	void update_range_recursion(int u, int l, int r, int si, int ei, int diff) {
		// pending update
		if (lazy[u] != 0) {
			st[u] += (r - l + 1) * lazy[u];

			if (l != r) {
				lazy[2*u+1] += lazy[u];
				lazy[2*u+2] += lazy[u];
			}

			lazy[u] = 0;
		}

		// out of range
		if (l > r || r < si || ei < l) return;

		// fully in range
		if (si <= l && r <= ei) {
			st[u] += (r - l + 1) * diff;

			if (l != r) {
				lazy[2*u+1] += diff;
				lazy[2*u+2] += diff;
				return;
			}
		}

		// overlaps:
		int m = (l + r) / 2;
		update_range_recursion(2*u+1, l, m, si, ei, diff);
		update_range_recursion(2*u+2, m+1, r, si, ei, diff);

		st[u] = st[2*u+1] + st[2*u+2];
	}

	int query_range(int a, int b) {
		return query_range_recursion(0, 0, N-1, a, b);
	}

	int query_range_recursion(int u, int l, int r, int a, int b) {
		// pending update
		if (lazy[u] != 0) {
			st[u] += (r - l + 1) * lazy[u];

			if (l != r) {
				lazy[2*u+1] += lazy[u];
				lazy[2*u+2] += lazy[u];
			}

			lazy[u] = 0;
		}

		// out of range
		if (l > r || r < a || b < l) return 0;

		// fully in range
		if (a <= l && r <= b) return st[u];

		// overlaps
		int m = (l + r) / 2;
		return query_range_recursion(2*u+1, l, m, a, b)
				+ query_range_recursion(2*u+2, m+1, r, a, b);
	}
};

void print(vi A) {
	for (int i = 0; i < A.size(); i++)
		printf("%d ", A[i]);
	printf("\n");
}

int main(){
	vi A({1, 2, 2, 3, 5, 4, 1, 0, 4});

	segment_tree st = segment_tree(A);
	print(st.st);
	printf("\n");

	st.update(0, 5);
	print(st.st);
	printf("\n");

	printf("%d\n", st.query(0, 0));
	printf("%d\n", st.query(2, 5));
	printf("%d\n", st.query(0, 8));
	printf("%d\n", st.query(6, 8));
	printf("\n");

	st.update_range(0, 8, 1);
	print(st.st);
	printf("\n");

	printf("%d\n", st.query_range(0, 0));
	printf("%d\n", st.query_range(2, 5));
	printf("%d\n", st.query_range(0, 8));
	printf("%d\n", st.query_range(6, 8));
	printf("\n");

	return 0;
}