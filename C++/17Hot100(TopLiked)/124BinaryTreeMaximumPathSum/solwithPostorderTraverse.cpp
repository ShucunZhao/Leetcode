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
    int maxP = INT_MIN;
    int dfs(TreeNode * root){
        if(!root){
            return 0;
        }
        int lP = max(dfs(root->left), 0);//2
        int rP = max(dfs(root->right), 0);
        maxP =  max(root->val+lP+rP, maxP);//2, 3, 6,
        return max(lP, rP)+root->val;
    }
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return maxP;
    }
};