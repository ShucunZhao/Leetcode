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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode * newNode = new TreeNode(val);
        if(root==NULL){
            return newNode;
        }
        TreeNode * pre = NULL;
        TreeNode* cur = root;
        while(cur){
            pre = cur;
            if(cur->val>val) cur = cur->left;
            else cur = cur->right;
        }
        if(pre->val>val) pre->left = newNode;
        else pre->right = newNode;
        return root;
    }
};