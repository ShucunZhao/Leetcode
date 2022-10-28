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
    TreeNode * pre = NULL;
    bool isValidBST(TreeNode* root) {
        if(root==NULL) return 1;
        bool l = isValidBST(root->left);
        if(pre!=NULL&&pre->val>=root->val){
            return 0;
        }
        pre=root;
        bool r = isValidBST(root->right);
        return l&&r;
    }
};