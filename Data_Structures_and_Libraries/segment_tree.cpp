#include <bits/stdc++.h>
using namespace std;

const int NEUTRAL = 0;

int comp(int a, int b){
	return a + b;
}

class SegmentTree{
	private:
		vector<int> tree;
		int n;

		void build(int p, int l, int r, vector<int>& arr){
			if(l == r){
				tree[p] = arr[l];
				return;
			}
			int m = (l+r)/2;
			build(2*p, l, m, arr);
			build(2*p+1, m+1, r, arr);
			tree[p] = comp(tree[2*p], tree[2*p+1]);
		}

		void update(int p, int l, int r, int i, int k){
			if(i > r || i < l) return;
			if(l == r){
				//tree[p] += k;
				tree[p] = k;
				return;
			}
			int m = (l+r)/2;
			update(2*p, l, m, i, k);
			update(2*p+1, m+1, r, i, k);
			tree[p] = comp(tree[2*p], tree[2*p+1]);
		}

		int query(int p, int l, int r, int a, int b){
			if(b < l || a > r) return NEUTRAL;
			if(a <= l && b >= r) return tree[p];
			int m = (l+r)/2;
			return comp(query(2*p, l, m, a, b), query(2*p+1, m+1, r, a, b));
		}

	public:
		SegmentTree(vector<int> arr){
			n = arr.size();
			tree.assign(4*n, NEUTRAL);
			build(1, 0, n-1, arr);
		}

		int query(int a, int b){
			return query(1, 0, n-1, a, b);
		}

		void update(int i, int k){
			update(1, 0, n-1, i, k);
		}
};


int main(){
	vector<int> test;
	test.push_back(0);
	test.push_back(3);
	test.push_back(4);
	test.push_back(2);
	test.push_back(1);
	test.push_back(9);
	test.push_back(99);
	test.push_back(5);
	test.push_back(4);
	test.push_back(3);
	test.push_back(1);
	test.push_back(0);
	SegmentTree st(test);
	cout << st.query(1, 4) << endl;
	cout << st.query(3, 7) << endl;
	st.update(6, 1);
	cout << st.query(3, 7) << endl;
	return 0;
}
