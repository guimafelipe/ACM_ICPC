#include <bits/stdc++.h>

using namespace std;


class Node {
public:
	int val;
	Node *left;
	Node *right;
	Node (int Val) {val = Val; left = NULL; right = NULL;}
};


void morris(Node *root) {
	if ( !root ) return;

	Node *curr = root;
	while (curr) {
		if ( !curr->left ) {
			printf("%d ", curr->val);
			curr = curr->right;
		}
		else {
			Node *pre = curr->left;
			
			while (pre->right && pre->right != curr) pre = pre->right;

			if ( !pre->right ) {
				pre->right = curr;
				curr = curr->left;
			}
			else { // pre->right = curr
				pre->right = NULL;
				printf("%d ", curr->val);
				curr = curr->right;
			}
		}
	}
	printf("\n");
}


int main() {
	Node *root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	root->right->left = new Node(6);
	root->right->right = new Node(7);

	morris(root);

	return 0;
}