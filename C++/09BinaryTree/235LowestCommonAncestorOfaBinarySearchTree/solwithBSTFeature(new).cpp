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
    TreeNode * traverse(TreeNode * root, TreeNode * l, TreeNode * r){
        if(!root) return NULL;
        if(root->val<l->val){
            return traverse(root->right, l, r);
        }
        else if(root->val>r->val){
            return traverse(root->left, l, r);
        }
        return root;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p->val<q->val){
            return traverse(root, p, q);
        }
        return traverse(root, q, p);
    }
};