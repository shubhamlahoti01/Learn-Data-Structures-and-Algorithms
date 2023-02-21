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

bool getPath(node * root, vector < int > & arr, int x) {
	if (!root) return false;
	arr.push_back(root -> data);

	if (root->data == x) return true;

	if (getPath(root -> left, arr, x) || getPath(root -> right, arr, x)) return true;

	arr.pop_back();
	return false;
}


int32_t main() {
	fastIO
	fileIO();

	struct node * root = newNode(1);
	root -> left = newNode(2);
	root -> left -> left = newNode(4);
	root -> left -> right = newNode(5);
	root -> left -> right -> left = newNode(6);
	root -> left -> right -> right = newNode(7);
	root -> right = newNode(3);

	vector<int> arr;

	bool res;
	res = getPath(root, arr, 7);

	cout << "The path is ";
	for (auto it : arr) {
		cout << it << " ";
	}

	return 0;
}
