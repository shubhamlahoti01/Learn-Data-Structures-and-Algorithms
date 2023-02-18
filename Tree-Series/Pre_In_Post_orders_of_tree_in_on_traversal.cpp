// Preorder, Inorder and Postorder Traversal in One Traversal using Single Stack
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
	struct node *left, *right;
};
struct node * newNode(int data) {
	struct node* node = (struct node*) malloc(sizeof(struct node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return (node);
}

void allTraversal(node* root, vector<int> &pre, vector<int> &in, vector<int> &post) {

	stack<pair<node*, int>> st;
	st.push({root, 1});
	if (root == NULL) return;
	while (!st.empty()) {
		auto it = st.top();
		st.pop();
		if (it.second == 1) {
			pre.push_back(it.first->data);
			it.second++;
			st.push(it);
			if (it.first->left) {
				st.push({it.first->left, 1});
			}
		} else if (it.second == 2) {
			in.push_back(it.first->data);
			it.second++;
			st.push(it);
			if (it.first->right) {
				st.push({it.first->right, 1});
			}
		} else {
			post.push_back(it.first->data);
		}
	}
}


int32_t main() {
	fastIO
	fileIO();

	struct node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right->left = newNode(6);
	root->right->right = newNode(7);

	vector<int> pre, in, post;
	allTraversal(root, pre, in, post);
	cout << "The preorder Traversal is: ";
	for (auto nodeVal : pre) {
		cout << nodeVal << " ";
	}
	cout << endl;

	cout << "The inorder Traversal is: ";
	for (auto nodeVal : in) {
		cout << nodeVal << " ";
	}
	cout << endl;

	cout << "The postorder Traversal is: ";
	for (auto nodeVal : post) {
		cout << nodeVal << " ";
	}
	cout << endl;

	return 0;
}
