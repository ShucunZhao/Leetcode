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
    bool cmpN(TreeNode * a, TreeNode * b){
        if(!a&&!b) return true;
        else if(!a&&b||a&&!b) return false;
        else if(a->val!=b->val) return false;
        return cmpN(a->left,b->right)&&cmpN(a->right, b->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return cmpN(root->left, root->right);
    }
};