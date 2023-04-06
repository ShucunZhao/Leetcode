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
    /*
        sum: 10, 15,  
        tar: 8
    */
    int cnt = 0;
    void traverse(TreeNode * root, long long target){//
        if(!root) return;
        if(root->val==target){
            cnt++;
        }
        traverse(root->left, target-(long long)root->val);
        traverse(root->right, target-(long long)root->val);
        return;
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(root){
            traverse(root, (long long)targetSum);
            pathSum(root->left, targetSum);
            pathSum(root->right, targetSum);
        }
        return cnt;
    }
};