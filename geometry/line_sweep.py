import functools

max_n = 100001

class point:
	def __init__(self, x, y):
		self.x = x
		self.y = y

	def print(self, end="\n"):
		print(self.x, self.y, end=end)

class rectangle:
	def __init__(self, bl, tr):
		self.bl = bl
		self.tr = tr

	def print(self):
		self.bl.print(end=", ")
		self.tr.print()

class event:
	def __init__(self, pt, i, t):
		self.pt = pt
		self.ind = i
		self.type = t

	def print(self):
		self.pt.print(", ")
		print(self.type)

def cmp_v(e1, e2):
	p1 = e1.pt
	p2 = e2.pt
	if p1.x < p2.x:
		return -1
	if p1.x > p2.x:
		return 1
	return 0

def update(st, cnt, i, l, r, a, b, val):
	len_range = (r - l + 1)

	if r < a or b < l: return

	if l == r:
		cnt[i] += val
		if cnt[i] == 0:
			st[i] += val
		else:
			st[i] = len_range
		return

	if a <= l and r <= b:
		cnt[i] += val
		if cnt[i] == 0:
			st[i] = st[2*i+1] + st[2*i+2]
		else:
			st[i] = len_range
		return

	m = int((l + r) / 2)

	update(st, cnt, 2*i + 1, l, m, a, b, val)
	update(st, cnt, 2*i + 2, m + 1, r, a, b, val)

	if cnt[i] == 0:
		st[i] = st[2*i + 1] + st[2*i + 2]

def query(st, cnt, i, l, r, a, b):
	if r < a or b < l: return 0

	# if l == r:
	# 	if st[i] > 0: return 1
	# 	else: return 0
	if a <= l and r <= b:
		return st[i]

	m = int((l + r) / 2)

	l = query(st, cnt, 2*i + 1, l, m, a, b)
	r = query(st, cnt, 2*i + 2, m+1, r, a, b)

	return l + r

def area(recs, ev, left, right):
	ans = 0

	st = [0] * 4*max_n
	cnt = [0] * 4*max_n

	ev.sort(key=functools.cmp_to_key(cmp_v))

	curr = ev[0]
	pt_down = curr.pt
	pt_up = right[curr].pt
	update(st, cnt, 0, 1, max_n, pt_down.y, pt_up.y - 1, 1)

	# vertical sweep line
	for i in range(1, len(ev)):
		prev = curr
		curr = ev[i]

		pr = None
		if curr.type == "bl":
			pr = recs[curr.ind].bl
		else:
			pr = recs[curr.ind].tr

		pl = None
		if prev.type == "bl":
			pl = recs[prev.ind].bl
		else:
			pl = recs[prev.ind].tr
		
		delta_x = pr.x - pl.x

		if delta_x > 0:
			# horizontal sweep line

			# delta_y = st[1]
			delta_y = query(st, cnt, 0, 1, max_n, 1, max_n)
			ans += delta_x * delta_y
			# print("v:", pl.x, pr.x)
			# print("delta_y", delta_y)
			# print(st)
		
		if curr.type == "bl":
			pt_down = curr.pt
			pt_up = right[curr].pt
			update(st, cnt, 0, 1, max_n, pt_down.y, pt_up.y - 1, 1)
		else:
			pt_up = curr.pt
			pt_down = left[curr].pt
			update(st, cnt, 0, 1, max_n, pt_down.y, pt_up.y - 1, -1)

	return ans


N = int(input())

recs = [None] * N
events = [None] * 2*N

left = {}
right = {}
for n in range(N):
	# bottom_left = input().split(" ")
	# x, y = int(bottom_left[0]), int(bottom_left[1])
	# bl = point(x, y)

	# top_right = input().split(" ")
	# x, y = int(top_right[0]), int(top_right[1])
	# tr = point(x, y)
	line = input().split(" ")
	x, y = int(line[0]), int(line[1])
	bl = point(x, y)

	x, y = int(line[2]), int(line[3])
	tr = point(x, y)

	rec = rectangle(bl, tr)

	recs[n] = rec

	ev_bl = event(bl, n, "bl")
	ev_tr = event(tr, n, "tr")
	events[2*n] = ev_bl
	events[2*n + 1] = ev_tr
	left[ev_tr] = ev_bl
	right[ev_bl] = ev_tr

# for ev in ev_h:
# 	ev.print()
# print()
# for ev in ev_v:
# 	ev.print()

print(area(recs, events, left, right))