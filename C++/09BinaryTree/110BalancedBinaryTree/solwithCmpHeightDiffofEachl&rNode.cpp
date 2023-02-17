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
    int getH(TreeNode * cur){
        if(cur==NULL) return 0;
        return max(getH(cur->left), getH(cur->right)) + 1;
    }
    bool isBalanced(TreeNode* root) {
        // cout<<getH(root)<<endl;
        if(!root) return 1;
        int lH = getH(root->left);
        int rH = getH(root->right);
        if(abs(lH-rH)>1) return 0;
        return isBalanced(root->left)&&isBalanced(root->right);
    }
};