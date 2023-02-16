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
    TreeNode * helper(TreeNode * cur){
        if(!cur) return NULL;
        TreeNode * l = helper(cur->left);
        TreeNode * r = helper(cur->right);
        if(l==NULL){
            cur->right = r;
        }
        else{
            cur->right = l;
            TreeNode * cur2 = l;
            while(cur2->right){
                cur2=cur2->right;
            }
            cur2->right = r;
            cur->left = NULL;
        }
        return cur;
    }
    void flatten(TreeNode* root) {
        root = helper(root);
        /*
            1.If the left child is not NULL, let the next node of the most right node of this left child to point to right node.
            2.Then let the whole left tree to be right.
            3.Repeat the steps above by traversing the current right tree. 
        */
    }
};