// Complexity: O(n * p), n = points in the convex_hull,
//						 p = points to add 

#include <bits/stdc++.h>

using namespace std;


class Point {
public:
	int x;
	int y;
	Point (int X, int Y) {x = X; y = Y;}
};

void print(vector<Point> &A) {
	for (int i = 0; i < A.size(); i++)
		printf("%d %d\n", A[i].x, A[i].y);
}

int sqrDist(Point p1, Point p2) {
	return (p2.y - p1.y)*(p2.y - p1.y) + (p2.x - p1.x)*(p2.x - p1.x);
}

int orientation(Point a, Point b, Point c) {
	int tan_op = (c.y - b.y)*(b.x - a.x) - (b.y - a.y)*(c.x - b.x);

	if (tan_op == 0) return 0; // colinear
	if (tan_op < 0) return 1; // clockwise
	if (tan_op > 0) return -1; // anticlockwise
}

bool is_inside(vector<Point> convex_hull, Point P) {
	int n = convex_hull.size();

	// scale change:
	// multiply all operands by n in order to work with ints instead of double
	P.x *= n;
	P.y *= n;

	Point CM = Point(0, 0);
	for (int i = 0; i < n; i++) {
		CM.x += convex_hull[i].x;
		CM.y += convex_hull[i].x;
		convex_hull[i].x *= n;
		convex_hull[i].y *= n;
	}

	for (int i = 0; i < n; i++) {
		int next = (i + 1) % n;
		if (orientation(CM, convex_hull[i], convex_hull[next]) != orientation(P, convex_hull[i], convex_hull[next]))
			return false;
	}

	return true;
}

void addPoint(vector<Point> &convex_hull, Point P) {
	if (is_inside(convex_hull, P)) return; // doesn't change

	int n = convex_hull.size();

	int high = 1;
	int prev = (high - 1 + n) % n;
	int next = (high + 1) % n;
	int o1 = orientation(P, convex_hull[high], convex_hull[next]);
	int o2 = orientation(P, convex_hull[prev], convex_hull[high]); 
	while (true) {
		// printf("high: %d %d %d, %d %d\n", prev, high, next, o1, o2);
		if (o1 == -1 && o2 == 1) break;
		prev = (prev + 1) % n;
		high = (high + 1) % n;
		next = (next + 1) % n;
		o1 = orientation(P, convex_hull[high], convex_hull[next]);
		o2 = orientation(P, convex_hull[prev], convex_hull[high]); 
	}
	
	int low = 1;
	prev = (low - 1 + n) % n;
	next = (low + 1) % n;
	o1 = orientation(P, convex_hull[low], convex_hull[prev]);
	o2 = orientation(P, convex_hull[next], convex_hull[low]); 
	while (true) {
		// printf("low: %d %d %d, %d %d\n", prev, low, next, o1, o2);
		if (o1 == 1 && o2 == -1) break;
		prev = (prev + 1) % n;
		low = (low + 1) % n;
		next = (next + 1) % n;
		o1 = orientation(P, convex_hull[low], convex_hull[prev]);
		o2 = orientation(P, convex_hull[next], convex_hull[low]); 
	}
	
	vector<Point> ans;

	int curr = high;
	while (curr != low) {
		ans.push_back(convex_hull[curr]);
		curr = (curr + 1) % n;
	}
	ans.push_back(convex_hull[curr]); // add low
	ans.push_back(P);

	convex_hull = ans;
}

int main() {
	vector<Point> convex_hull;
	convex_hull.push_back(Point(0, 0));
	convex_hull.push_back(Point(3, -1));
	convex_hull.push_back(Point(4, 5));
	convex_hull.push_back(Point(-1, 4));

	addPoint(convex_hull, Point(100, 100));

	// convex_hull.push_back(Point(3, 0));
	// convex_hull.push_back(Point(4, 2));
	// convex_hull.push_back(Point(3, 4));

	// addPoint(convex_hull, Point(2, 2));

	print(convex_hull);

	// printf("%d\n", is_inside(convex_hull, Point(3, 5)));

	return 0;
}