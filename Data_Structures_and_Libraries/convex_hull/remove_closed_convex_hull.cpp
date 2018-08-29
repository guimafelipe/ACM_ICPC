#include <bits/stdc++.h>

using namespace std;

#define INF 1 << 30

struct point {
	int x, y;
};

void print(vector<point> &vp) {
	for (int i = 0; i < vp.size(); i++) {
		point p = vp[i];
		printf("%d %d\n", p.x, p.y);
	}
}

// Global
point p0;

// 0 --> colinear
// 1 --> clockwise
// 2 --> counterclockwise
int orientation(point p, point q, point r) {
	double diff = (r.y - q.y)*(q.x - p.x) - (q.y - p.y)*(r.x - q.x);

	if (diff == 0) return 0;
	if (diff < 0) return 1;
	if (diff > 0) return 2;
}

int distSqr(point p, point q) {
	return sqrt(pow((q.x - p.x), 2) + pow((q.y - p.y), 2));
}

double tan(point p) {
	return ((double)(p.y - p0.y) / (double)(p.x - p0.x));
}

struct compare {
	inline bool operator() (point p1, point p2) {
		int o = orientation(p0, p1, p2);

		if (o == 0) {
			if (distSqr(p0, p2) >= distSqr(p0, p1)) return true;
			else return false;
		}

		if (o == 1) return false;
		if (o == 2) return true;
	}
};

// bool compare (point p1, point p2) {
// 	int o = orientation(p0, p1, p2);

// 	if (o == 0) {
// 		if (dist(p0, p2) >= dist(p0, p1)) return true;
// 		else return false;
// 	}

// 	if (o == 1) return false;
// 	if (o == 2) return true;
// }

// int compare(const void *vp1, const void *vp2)
// {
//    point *p1 = (point *)vp1;
//    point *p2 = (point *)vp2;
 
//    // Find orientation
//    int o = orientation(p0, *p1, *p2);
//    if (o == 0)
//      return (dist(p0, *p2) >= dist(p0, *p1))? -1 : 1;
 
//    return (o == 2)? -1: 1;
// }

point next_to_top(stack<point> &S) {
	point p = S.top();
	S.pop();
	point ans = S.top();
	S.push(p);

	return ans;
}

bool stack_gte2(stack<point> &S) {
	int size = 0;
	point aux1, aux2;

	if ( !S.empty() ) {
		size++;
		aux1 = S.top();
		S.pop();
	} else return false;

	if ( !S.empty() ) {
		size++;
		aux2 = S.top();
		S.pop();
	} else {
		S.push(aux1);
		return false;
	}

	S.push(aux2);
	S.push(aux1);

	return true;
}

vector<point> remove_convex_hull(vector<point> &vp, int *layers) {
	vector<point> ans;
	if (vp.size() < 3) {
		// printf("Dropped 1\n");
		return ans;
	}
	
	int i_min = 0;

	for (int i = 1; i < vp.size(); i++) {
		if (vp[i].y < vp[i_min].y ||
			(vp[i].y == vp[i_min].y && vp[i].x < vp[i_min].x))
			i_min = i;
	}

	swap(vp[0], vp[i_min]);

	// global p0
	p0 = vp[0];
	sort(vp.begin() + 1, vp.end(), compare());
	// qsort(&vp[1], vp.size()-1, sizeof(point), compare);

	double max_tan = -INF;
	double min_tan = INF;

	int m = 1;
	for (int i = 1; i < vp.size(); i++) {
		max_tan = max(max_tan, tan(vp[i]));
		min_tan = min(min_tan, tan(vp[i]));

		while (i < vp.size()-1 && orientation(p0, vp[i], vp[i+1]) == 0)
			i++;

		swap(vp[m], vp[i]);
		
		m++;
	}

	if (m < 3) {
		// printf("Dropped 2\n");
		return ans;
	}

	stack<point> S;
	S.push(vp[0]);
	S.push(vp[1]);
	S.push(vp[2]);

	for (int i = 3; i < m; i++) {
		// while (stack_gte2(S) && orientation(next_to_top(S), S.top(), vp[i]) != 2) {
		while (orientation(next_to_top(S), S.top(), vp[i]) == 1) {
			ans.push_back(S.top());
			S.pop();
		}
		S.push(vp[i]);
	}

	for (int i = m; i < vp.size(); i++) {
		if (tan(vp[i]) == max_tan || tan(vp[i]) == min_tan) {
			swap(vp[m], vp[i]);
			m++;
		}
		else ans.push_back(vp[i]);
	}

	int hull_size = 0;
	// printf("Convex Hull:\n");
	while ( !S.empty() ) {
		point p = S.top();
		S.pop();
		hull_size++;
		// printf("%d %d\n", p.x, p.y);
	}

	// if (hull_size > 2)
		(*layers)++;

	return ans;
}


int main() {
	int N;

	scanf("%d", &N);
	while (N != 0) {
		int layers = 0;
		vector<point> vp;

		for (int n = 0; n < N; n++) {
			point p;
			scanf("%d %d", &p.x, &p.y);
			vp.push_back(p);
		}

		while (vp.size() > 0) {
			vector<point> new_vp;
			new_vp = remove_convex_hull(vp, &layers);
			vp = new_vp;
		}

		if (layers % 2 == 0)
			printf("Do not take this onion to the lab!\n");
		else
			printf("Take this onion to the lab!\n");

		scanf("%d", &N);
	}

	// vector<point> VP({{0, 3}, {1, 1}, {2, 2}, {4, 4},
 //                      {0, 0}, {1, 2}, {3, 1}, {3, 3}});

	// remove_convex_hull(VP);

	return 0;
}
