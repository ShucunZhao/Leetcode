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
    bool preorder(TreeNode* root, int targetSum, int sum){
        // cout<<"sum:"<<sum<<endl;
        if(!root->left&&!root->right){
            if(sum+root->val==targetSum){
            // cout<<"flag"<<endl;
                return 1;
            }
            return 0;
        }
        bool L, R;
        if(root->left){
            L = preorder(root->left, targetSum, sum+root->val);
        }
        if(root->right){
            R = preorder(root->right, targetSum, sum+root->val);
        }
        // if(preorder(root->left, targetSum, sum+root->val)) return 1;
        // if(preorder(root->right, targetSum, sum+root->val)) return 1;
        // return preorder(root->left, targetSum, sum+root->val)||preorder(root->right, targetSum, sum+root->val);
        return L||R;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return 0;
        return preorder(root, targetSum, 0);
    }
};