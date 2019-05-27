import math

class node:
	def __init__(self, value):
		self.val = value
		self.left = None
		self.right = None

def dist_vertical(root, val, h):
	if root == None: return math.inf

	if root.val == val: return h

	left = dist_vertical(root.left, val, h + 1)
	right = dist_vertical(root.right, val, h + 1)

	return min(left, right)

def LCA(root, A, B, lca):
	if root == None: return None

	left = LCA(root.left, A, B, lca)
	right = LCA(root.right, A, B, lca)
	
	if root.val == A or root.val == B:
		if left or right:
			lca.append(root)
		return root

	if left and right:
		lca.append(root)
		return root
	if left:
		return left
	if right:
		return right

	return None

def dist(root, A, B):
	lca = []
	LCA(root, A, B, lca)
	
	dist_A = dist_vertical(root, A, 0)
	dist_B = dist_vertical(root, B, 0)
	dist_LCA = dist_vertical(root, lca[0].val, 0)
	# print("dist_A:", dist_A)
	# print("dist_B:", dist_B)
	# print("dist_LCA:", dist_LCA)
	
	return dist_A + dist_B - 2 * dist_LCA

if __name__ == "__main__":
	root = node(1)
	root.left = node(2)
	root.right = node(3)
	root.left.left = node(4)
	root.left.right = node(5)

	print(dist(root, 4, 5))