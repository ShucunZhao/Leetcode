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
    void backtracking(TreeNode * root, int Sum){
        //if(!root) return;
        if(!root->left&&!root->right){
            if(Sum-root->val==0){
                path.push_back(root->val);
                ans.push_back(path);
                path.pop_back();
            }
        }
        if(root->left){
            path.push_back(root->val);
            backtracking(root->left, Sum-root->val);
            path.pop_back();
        }
        if(root->right){
            path.push_back(root->val);
            backtracking(root->right, Sum-root->val);
            path.pop_back();
        }
        return;
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(!root) return {};
        backtracking(root, targetSum);
        return ans;
    }
};