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
    int getLeftDepth(TreeNode * root){
        if(!root) return 0;
        return getLeftDepth(root->left)+1;
    }
    int getRightDepth(TreeNode * root){
        if(!root) return 0;
        return getRightDepth(root->right)+1;
    }    
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        int L = getLeftDepth(root);
        int R = getRightDepth(root);
        int left = 0, right = 0;
        if(L==R){
            return pow(2,L)-1;
        }
        else{
            left = countNodes(root->left);   
            right = countNodes(root->right);    
        }
        return left + right +1;
    }
};