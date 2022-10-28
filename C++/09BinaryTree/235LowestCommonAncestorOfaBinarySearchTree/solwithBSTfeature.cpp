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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int pval = p->val;
        int qval = q->val;
        if(root==NULL) return NULL;
        if(qval>pval){
            if(root->val>=pval&&root->val<=qval){
                return root;
            }
        }
        else{
            if(root->val>=qval&&root->val<=pval){
                return root;
            }
        }
        TreeNode * l = lowestCommonAncestor(root->left,p,q);
        if(l!=NULL){
            return l;
        }
        TreeNode * r = lowestCommonAncestor(root->right,p,q);
        if(r!=NULL){
            return r;
        }
        return NULL;
    }
};