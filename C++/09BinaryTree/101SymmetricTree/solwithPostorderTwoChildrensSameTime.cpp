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
    bool cmpFunc(TreeNode * left, TreeNode * right){
        if(left==NULL&&right==NULL) return 1;
        else if((left&&!right)||(!left&&right)) return 0;
        else if(left->val!=right->val) return 0;
        return cmpFunc(left->left, right->right)&&cmpFunc(left->right, right->left);;
    }
    bool isSymmetric(TreeNode* root) {
        if(!root) return 1;
        return cmpFunc(root->left, root->right);
    }
};