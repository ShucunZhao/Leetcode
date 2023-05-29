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
    int getDepth(TreeNode * root){
        if(!root->left&&!root->right) return 1;
        int L = INT_MAX, R = INT_MAX;
        if(root->left){
            L = getDepth(root->left);
        }
        if(root->right){
            R = getDepth(root->right);
        }
        return min(L,R)+1;
    }
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        return getDepth(root);
    }
};