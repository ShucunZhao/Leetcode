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
class Solution {//Postorder
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==NULL){
            return 0;
        }
        return dfs(root, root->val, targetSum);
    }
    bool dfs(TreeNode * cur, int sum, int targetSum){
        if(cur->left==NULL&&cur->right==NULL&&sum==targetSum) return 1;
        if(cur->left==NULL&&cur->right==NULL&&sum!=targetSum) return 0;
        if(cur->left!=NULL){
            sum+=cur->left->val;
            if(dfs(cur->left, sum, targetSum)) return 1;
            sum-=cur->left->val;
        }
        if(cur->right!=NULL){
            sum+=cur->right->val;
            if(dfs(cur->right, sum, targetSum)) return 1;
            sum-=cur->right->val;
        }
        return 0;
    }
};