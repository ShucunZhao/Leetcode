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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==NULL) return 0;
        return traverse(root, targetSum-root->val);
    }
    bool traverse(TreeNode * cur, int target){
        if(cur->left==NULL&&cur->right==NULL&&target==0) return 1;
        if(cur->left){
            if(traverse(cur->left, target-cur->left->val)){
                return 1;
            }
        }
        if(cur->right){
            if(traverse(cur->right, target-cur->right->val)){
                return 1;
            }
        }
        return 0;
    }
};