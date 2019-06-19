// O(n^2) -> worse than graham

#include <bits/stdc++.h>

using namespace std;


class Point {
public:
	int x;
	int y;
	Point (int X=0, int Y=0) {x = X; y = Y;}

	friend bool operator< (const Point &p, const Point &q) {
		return p.x < q.x
		|| (p.x == q.x && p.y <= q.y);
	}

	friend bool operator== (const Point &p, const Point &q) {
		return p.x == q.x && p.y == q.y;
	}
};

void print_points(vector<Point> &A) {
	for (int i = 0; i < A.size() - 1; i++)
		printf("%d %d, ", A[i].x, A[i].y);
	printf("%d %d\n", A[A.size()-1].x, A[A.size()-1].y);
}

int orientation(Point &p, Point &q, Point &r) {
	int tan_op = (r.y - q.y) * (q.x - p.x) - (q.y - p.y) * (r.x - q.x);

	if (tan_op < 0) return 1; // clockwise
	if (tan_op == 0) return 0; // colinear
	if (tan_op > 0) return -1; // counter-clockwise
}

vector<Point> remove_duplicates(vector<Point> &A) {
	vector<Point> ans;
	if (A.size() == 0) return ans;

	for (int i = 0; i < A.size() - 1; i++) {
		if (A[i] == A[i + 1]) continue;

		ans.push_back(A[i]);
	}
	ans.push_back(A[A.size() - 1]);

	return ans;
}

int sqr_distance(Point &p1, Point &p2) {
	return (p2.y - p1.y) * (p2.y - p1.y) + (p2.x - p1.x) * (p2.x - p1.x);
}

vector<Point> conver_hull(vector<Point> &A) {
	sort(A.begin(), A.end());

	A = remove_duplicates(A);

	int n = A.size();
	set<Point> ans;

	if (n < 3) return vector<Point>();

	int leftmost = 0;
	for (int i = 0; i < n; i++) {
		if (A[i].x < A[leftmost].x)
			leftmost = i;
	}

	int p = leftmost;
	int q = (p + 1) % n;
	// ans.insert(A[p]);

	while (true) {
		// while (ans.find(A[q]) != ans.end())
		// 	q = (q + 1) % n;

		for (int i = 0; i < n; i++) {
			if (ans.find(A[i]) != ans.end()) continue;
			if (i == p || i == q) continue;

			// get most counter-clockwise point
			if (orientation(A[p], A[i], A[q]) == -1)
				q = i;

			if (orientation(A[p], A[i], A[q]) == 0 && sqr_distance(A[p], A[i]) > sqr_distance(A[p], A[q]))
				q = i;
		}

		ans.insert(A[q]);

		p = q;
		q = (q + 1) % n;

		if (A[p] == A[leftmost]) break;
	}

	if (ans.size() < 3) return vector<Point>();
	return vector<Point>(ans.begin(), ans.end());
}


int main() {
	// test case

	// Point p1, p2, p3, p4, p5, p6, p7;
	// p1 = Point(0, 3);
	// p2 = Point(2, 2);
	// p3 = Point(1, 1);
	// p4 = Point(2, 1);
	// p5 = Point(3, 0);
	// p6 = Point(0, 0);
	// p7 = Point(3, 3);

	// vector<Point> A({p1, p2, p3, p4, p5, p6, p7});

	// vector<Point> ans = conver_hull(A);

	// if (ans.size() == 0)
	// 	printf("-1\n");
	// else
	// 	print_points(ans);

	// input.txt

	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		int N;
		cin >> N;

		vector<Point> A;
		for (int n = 0; n < N; n++) {
			int x, y;
			cin >> x >> y;

			Point p(x, y);
			A.push_back(p);
		}

		vector<Point> ans = conver_hull(A);

		if (ans.size() == 0)
			printf("-1\n");
		else
			print_points(ans);
	}

	return 0;
}