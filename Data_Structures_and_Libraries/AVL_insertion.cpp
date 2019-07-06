#include <bits/stdc++.h>

using namespace std;

class Node {
public:
	int val;
	int height;
	Node *left;
	Node *right;

	Node(int Val) {val = Val; left = NULL; right = NULL; height = 1;}
};

void dfs_print_util(Node *root) {
	if ( !root ) return;

	printf("%d ", root->val);
	dfs_print_util(root->left);
	dfs_print_util(root->right);
}

void dfs_print(Node *root) {
	dfs_print_util(root);
	printf("\n");
}

void pre_order_height(Node *root) {
	if ( !root ) return;

	printf("%d, %d\n", root->val, root->height);
	pre_order_height(root->left);
	pre_order_height(root->right);
}

int get_height(Node *root) {
	if ( !root ) return 0;

	int left = get_height(root->left);
	int right = get_height(root->right);

	return 1 + max(left, right);
}

void update_height(Node *root) {
	root->height = 1 + max(get_height(root->left), get_height(root->right));
}

Node *left_rotate(Node *root) {
	Node *temp = root->right;
	
	root->right = temp->left;
	temp->left = root;

	update_height(root);

	return temp;
}

Node *right_rotate(Node *root) {
	Node *temp = root->left;

	root->left = temp->right;
	temp->right = root;

	update_height(root);

	return temp;
}

Node *insert(Node *root, int val) {
	if ( !root ) return new Node(val);

	if ( val == root->val ) return root;
	if (val < root->val) {
		root->left = insert(root->left, val);
	}
	if (val > root->val) {
		root->right = insert(root->right, val);
	}

	int balance = get_height(root->right) - get_height(root->left);

	// test if tree is no longer balanced

	// left disbalanced

	if (balance < -1) {
		if (val < root->left->val) {
			root = right_rotate(root);
		}
		else {
			root->left = left_rotate(root->left);
			root = right_rotate(root);
		}
	}

	// right disbalanced

	if (balance > 1) {
		if (val > root->right->val) {
			root = left_rotate(root);
		}
		else {
			root->right = right_rotate(root->right);
			root = left_rotate(root);
		}
	}

	update_height(root);

	return root;
}


int main() {
	// test case

	Node *root = NULL;

	root = insert(root, 10);
	root = insert(root, 20);
	root = insert(root, 30);
	root = insert(root, 40);
	root = insert(root, 50);
	root = insert(root, 25);

	/*
					30
				/		\
			20				40
		/		\				\
	10			25				50
	*/

	dfs_print(root);

	// pre_order_height(root);

	// input.txt

	// int T;
	// cin >> T;

	// for (int t = 0; t < T; t++) {
	// 	Node *root = NULL;
	// 	int N;
	// 	cin >> N;

	// 	for (int n = 0; n < N; n++) {
	// 		int val;
	// 		cin >> val;

	// 		root = insert(root, val);
	// 	}

	// 	// pre_order_height(root);
	// 	dfs_print(root);
	// }

	return 0;
}