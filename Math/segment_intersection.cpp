#include <bits/stdc++.h>

using namespace std;


class Point {
public:
	int x;
	int y;
	Point (int X=0, int Y=0) {x = X; y = Y;}
};


int orientation(Point p, Point q, Point r) {
	int tan_op = (r.y - q.y) * (q.x - p.x) - (q.y - p.y) * (r.x - q.x);

	if (tan_op > 0) return -1; // anti-clockwise
	if (tan_op == 0) return 0; // colinear
	if (tan_op < 0) return 1; // clockwise
}

bool on_segment(Point p, Point q, Point r) {
	return (min(p.x, r.x) <= q.x) && (q.x <= max(p.x, r.x)) && (min(p.y, r.y) <= q.y) && (q.y <= max(p.y, r.y));
}

bool is_instersection(Point p1, Point q1, Point p2, Point q2) {
	int o1 = orientation(p1, q1, p2);
	int o2 = orientation(p1, q1, q2);
	int o3 = orientation(p2, q2, p1);
	int o4 = orientation(p2, q2, q1);

	if (o1 != o2 && o3 != o4) return true;

	if (o1 == 0)
		if (on_segment(p1, p2, q1)) return true;

	if (o2 == 0)
		if (on_segment(p1, q2, q1)) return true;

	if (o3 == 0)
		if (on_segment(p2, p1, q2)) return true;

	if (o4 == 0)
		if (on_segment(p2, q1, q2)) return true;

	return false;
}


int main() {
	Point p1, q1, p2, q2;
	
	// test cases

	// p1 = Point(1, 1);
	// q1 = Point(10, 1);
	// p2 = Point(1, 2);
	// q2 = Point(10, 2);
	// cout << is_instersection(p1, q1, p2, q2) << endl;

	// p1 = Point(10, 0);
	// q1 = Point(0, 10);
	// p2 = Point(0, 0);
	// q2 = Point(10, 10);
	// cout << is_instersection(p1, q1, p2, q2) << endl;

	// p1 = Point(-5, -5);
	// q1 = Point(0, 0);
	// p2 = Point(1, 1);
	// q2 = Point(10, 10);
	// cout << is_instersection(p1, q1, p2, q2) << endl;

	// input.txt

	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		cin >> p1.x;
		cin >> p1.y;
		cin >> q1.x;
		cin >> q1.y;

		cin >> p2.x;
		cin >> p2.y;
		cin >> q2.x;
		cin >> q2.y;

		cout << is_instersection(p1, q1, p2, q2) << endl;
	}

	return 0;
}