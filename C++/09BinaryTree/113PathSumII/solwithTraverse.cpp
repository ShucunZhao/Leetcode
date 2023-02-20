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
    vector<int> path;
    vector<vector<int> > ans;
    void preorder(TreeNode* root, int targetSum, int sum){
        if(!root->left&&!root->right){
            if(root->val+sum==targetSum){
                path.push_back(root->val);
                ans.push_back(path);
                path.pop_back();
            }
        }
        if(root->left){
            path.push_back(root->val);
            preorder(root->left, targetSum, root->val+sum);
            path.pop_back();
        }
        if(root->right){
            path.push_back(root->val);
            preorder(root->right, targetSum, root->val+sum);
            path.pop_back();
        }  
        return;
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(!root) return ans;
        preorder(root, targetSum, 0);
        return ans;
    }
};