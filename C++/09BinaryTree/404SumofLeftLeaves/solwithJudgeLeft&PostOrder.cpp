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
    int sumOfLeftLeaves(TreeNode* root) {
       if(!root) return 0;
       int L = 0, R = 0;
       if(root->left==NULL){
            L = 0;
       }
       else if(root->left->left==NULL&&root->left->right==NULL){
           L = root->left->val;
       }
       else{
           L = sumOfLeftLeaves(root->left);
       }
       R = sumOfLeftLeaves(root->right);
       return L+R;
    }
};