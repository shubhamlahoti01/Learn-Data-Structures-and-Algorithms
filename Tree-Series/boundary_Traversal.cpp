// https://takeuforward.org/data-structure/boundary-traversal-of-a-binary-tree/
/* Shubham lahoti */
#include <bits/stdc++.h>
#define ll long long int
using namespace std;
#define	fastIO	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

void fileIO() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

/* --------------------------( Shubham Lahoti )-------------------------- */



struct node {
	int data;
	struct node * left, * right;
};


struct node * newNode(int data) {
	struct node * node = (struct node * ) malloc(sizeof(struct node));
	node -> data = data;
	node -> left = NULL;
	node -> right = NULL;

	return (node);
}

bool isLeaf(node * root) {
	return !root -> left && !root -> right;
}

void addLeftBoundary(node * root, vector < int > & res) {
	node* curr = root->left;
	while (curr != NULL) {
		if (!isLeaf(curr)) res.push_back(curr->data);
		if (curr->left) curr = curr->left;
		else curr = curr->right;
	}
}
void addRightBoundary(node * root, vector < int > & res) {
	vector<int> temp;
	node* curr = root->right;
	while (curr != NULL) {
		if (!isLeaf(curr)) temp.push_back(curr->data);
		if (curr->right) curr = curr->right;
		else curr = curr->left;
	}
	for (int i = temp.size() - 1; i >= 0; i--) {
		res.push_back(temp[i]);
	}
}

void addLeaves(node * root, vector < int > & res) {
	if (isLeaf(root)) {
		res.push_back(root->data);
		return;
	}
	if (root->left) addLeaves(root->left, res);
	if (root->right) addLeaves(root->right, res);
}

vector<int> printBoundary(node * root) {
	vector<int> res;
	if (!root) return res;
	if (!isLeaf(root)) res.push_back(root->data);
	addLeftBoundary(root, res);
	addLeaves(root, res);
	addRightBoundary(root, res);
	return res;
}


int32_t main() {
	fastIO
	fileIO();

	struct node * root = newNode(1);
	root -> left = newNode(2);
	root -> left -> left = newNode(3);
	root -> left -> left -> right = newNode(4);
	root -> left -> left -> right -> left = newNode(5);
	root -> left -> left -> right -> right = newNode(6);
	root -> right = newNode(7);
	root -> right -> right = newNode(8);
	root -> right -> right -> left = newNode(9);
	root -> right -> right -> left -> left = newNode(10);
	root -> right -> right -> left -> right = newNode(11);

	vector<int> boundaryTraversal;
	boundaryTraversal = printBoundary(root);

	cout << "The Boundary Traversal is : ";
	for (int i = 0; i < boundaryTraversal.size(); i++) {
		cout << boundaryTraversal[i] << " ";
	}
	return 0;
}