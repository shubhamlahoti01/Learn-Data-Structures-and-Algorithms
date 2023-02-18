// https://leetcode.com/problems/symmetric-tree/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool helper(TreeNode* l, TreeNode* r){
        if(!l && !r) return true;
        if((l==NULL && r!=NULL) || (l!=NULL && r==NULL) || (l->val != r->val)) return false;
        bool a = helper(l->left,r->right);
        bool b = helper(l->right,r->left);
        return a && b;
    }
    bool isSymmetric(TreeNode* root) {
        if(!root) return false;
        return helper(root->left, root->right);
    }
};