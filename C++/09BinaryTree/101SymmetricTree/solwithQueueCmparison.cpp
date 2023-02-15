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
    bool isSymmetric(TreeNode* root) {
        if(!root) return 1;
        queue<TreeNode*> Q;
        Q.push(root->left);
        Q.push(root->right);
        while(!Q.empty()){
            TreeNode * left = Q.front();
            Q.pop();
            TreeNode * right = Q.front();
            Q.pop();
            if(!left&&!right) continue;
            else if(!left&&right||left&&!right||left->val!=right->val) return 0;
            Q.push(left->left);
            Q.push(right->right);
            Q.push(left->right);
            Q.push(right->left);
        }
        return 1;
    }
};