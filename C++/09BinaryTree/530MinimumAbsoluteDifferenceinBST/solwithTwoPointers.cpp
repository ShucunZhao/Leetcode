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
    int ans = INT_MAX;
    TreeNode * pre = NULL;
    int getMinimumDifference(TreeNode* root) {
        if(root==NULL) return 0;
        traverse(root);
        return ans;
    }
    void traverse(TreeNode * cur){
        if(cur==NULL) return;
        traverse(cur->left);
        if(pre!=NULL) ans = ans > (cur->val-pre->val) ? (cur->val-pre->val) : ans;
        pre=cur;
        traverse(cur->right);
    }
};