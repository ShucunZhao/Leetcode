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

/*
    sol with pre and cur pointer, using preorder to traverse whole tree, and let the 
    pre pointer node's left child be null and the right node be cur pointer node, then 
    do this operations when traversing.
*/

class Solution {
public:
    TreeNode * pre = NULL;
    TreeNode * cur = NULL;
    void preorder(TreeNode * root){
        if(!root) return;
        TreeNode * tmpLeft = root->left;//KeyPoint1: We need to save the temporary left and right node here because 
                                        //the operation step below will change left and right children of current root.
        TreeNode * tmpRight = root->right;
        //Operation step:
        if(pre){
            pre->left = NULL;
            pre->right = cur;
            pre = pre->right;
        }
        else{
            pre = cur;//N,1,
        }
        cur = root;//1,2,
        preorder(tmpLeft);
        preorder(tmpRight);
        return;
    }
    void flatten(TreeNode* root) {
        preorder(root);
        if(cur&&pre){//KeyPoint2: if the cur is not null and pre is also not null, which means the tree is only two nodes so we
                        //also need to do the operation once. If the cur is null but pre is not null means there is only one node,
                        //just do nothing.
            pre->left = NULL;
            pre->right = cur;
            pre = pre->right;
        }
    }
};