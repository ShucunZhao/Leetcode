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
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        getLeftSum(root, sum);
        return sum;
    }
    
    void getLeftSum(TreeNode * cur, int & sum){
        if(cur==NULL) return;
        if(cur->left==NULL&&cur->right==NULL) return;
        if(cur->left!=NULL&&cur->left->left==NULL&&cur->left->right==NULL){
            sum = sum + cur->left->val;
            return;
        }
        getLeftSum(cur->left, sum);
        getLeftSum(cur->right, sum);
    }
};