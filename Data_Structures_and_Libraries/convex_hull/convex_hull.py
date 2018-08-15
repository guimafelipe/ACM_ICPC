import functools
import math

def compare(p1, p2):
	if orientation(p0, p1, p2) == 0:
		if dist(p0, p2) >= dist(p0, p1):
			return -1
		else:
			return 1
	if orientation(p0, p1, p2) == 1:
		return 1
	if orientation(p0, p1, p2) == 2:
		return -1

class point:
	def __init__(self, x, y):
		self.x = x
		self.y = y

p0 = point(0, 0)

def next_to_top(S):
	p = S.pop()
	ans = S[-1]
	S.append(p)
	return ans

def dist(p1, p2):
	return math.sqrt((p2.x - p1.x)**2 + (p2.y - p1.y)**2)

# 0 --> colinear
# 1 --> clockwise
# 2 --> couterclockwise
def orientation(p, q, r):
	diff = (r.y - q.y)*(q.x - p.x) \
			- ((q.y - p.y)*(r.x - q.x))

	if diff == 0: return 0
	if diff < 0: return 1
	if diff > 0: return 2

def convex_hull(points):
	i_min = 0

	for i in range(len(points)):
		if points[i].y < points[i_min].y or \
		(points[i].y == points[i_min].y
		and points[i].x < points[i_min].x):
			i_min = i

	points[0], points[i_min] = points[i_min], points[0]

	global p0
	p0 = points[0]
	points = sorted(points, key=functools.cmp_to_key(compare))

	for p in points:
		print("(", p.x, ",", p.y, ")")

	m = 1
	for i in range(1, len(points)):
		while i < len(points)-1 and orientation(p0, points[i], points[i+1]) == 0:
			i += 1

		points[m] = points[i]
		m += 1

	if m < 3: return

	S = []
	S.append(points[0])
	S.append(points[1])
	S.append(points[2])

	for i in range(3, m):
		while orientation(next_to_top(S), S[-1], points[i]) != 2:
			S.pop()
		S.append(points[i])

	while len(S) > 0:
		p = S.pop()
		print(p.x, p.y)


if __name__ == "__main__":
	p1 = point(0, 3)
	p2 = point(1, 1)
	p3 = point(2, 2)
	p4 = point(4, 4)
	p5 = point(0, 0)
	p6 = point(1, 2)
	p7 = point(3, 1)
	p8 = point(3, 3)

	points = [p1, p2, p3, p4, p5, p6, p7, p8]

	convex_hull(points)

	pass