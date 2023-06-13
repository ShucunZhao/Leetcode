/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    /*
    bool ifShow(TreeNode * root, TreeNode * p, TreeNode * q){
        if(!root) return false;


    }
    */
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return NULL;
        TreeNode * L = lowestCommonAncestor(root->left, p, q);
        TreeNode * R = lowestCommonAncestor(root->right, p, q);
        if(L&&R) return root;
        else if((L||R)&&(root==p||root==q)) return root;
        else if(root==p||root==q){
            return root;
        }
        return L!=NULL?L:R;
    }
};