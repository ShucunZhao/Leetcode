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
    TreeNode * pre;
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL) return NULL;
        if(root->val > key){
           root->left = deleteNode(root->left, key);
        }
        else if(root->val < key){
           root->right = deleteNode(root->right, key);
        }
        else{
            if(root->left==NULL&&root->right==NULL) {
                delete root;
                root = NULL;
            }
            else if(root->left==NULL&&root->right!=NULL) {
                TreeNode * tmp = root->right;
                delete root;
                root = tmp;
            }
            else if(root->left!=NULL&&root->right==NULL) {
                TreeNode * tmp = root->left;
                delete root;
                root = tmp;
            }
            else if(root->left!=NULL&&root->right!=NULL){
                TreeNode * tmpl = root->left;
                TreeNode * tmpr = root->right;
                TreeNode * tmp = root->right;
                while(tmp->left!=NULL){
                    tmp = tmp->left;
                }
                tmp->left = tmpl;
                delete root;
                root = tmpr;
            }
        }
        return root;
    }
};