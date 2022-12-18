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
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if(root==NULL) return root;
        if(root->left)  root->left = trimBST(root->left, low, high);
        if(root->right) root->right = trimBST(root->right, low, high);
        if(root->val<low||root->val>high){
            if(root->left==NULL&&root->right==NULL){
                // delete root;
                return NULL;
            }
            else if(root->left==NULL&&root->right!=NULL){
                TreeNode * tmp = root->right;
                // delete root;
                return tmp;
            }
            else if(root->left!=NULL&&root->right==NULL){
                TreeNode * tmp = root->left;
                // delete root;
                return tmp;
            }
            else{
                TreeNode * cur = root->right;
                while(cur->left){
                    cur = cur->left;
                }
                cur->left = root->left;
                TreeNode * tmp = root->right;
                // delete root;
                return tmp;
            }
        }
        return root;
    }
};