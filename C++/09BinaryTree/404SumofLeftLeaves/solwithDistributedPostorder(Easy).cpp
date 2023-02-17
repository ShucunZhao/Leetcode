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
    int sum = 0;
    int sumOfLeftLeaves(TreeNode* root) {
        if(root!=NULL) traverse(root);
        return sum;
    }
    void traverse(TreeNode * cur){
        if(cur==NULL) return;
        // if(cur->left==NULL||cur->right==NULL) return;
        traverse(cur->left);
        traverse(cur->right);
        if(cur->left!=NULL&&cur->left->left==NULL&&cur->left->right==NULL){
            sum+=cur->left->val;
        }
        return;
    }
};