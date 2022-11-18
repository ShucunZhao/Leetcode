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
    int rob(TreeNode* root) {
        vector<int> ans = traversal(root);
        return max(ans[0], ans[1]);
    }
    
    vector<int> traversal(TreeNode * cur){//vector[0]: not get; vector[1]: get.
        if(cur==NULL){
            return {0,0};
        }       
        vector<int> left = traversal(cur->left);
        vector<int> right = traversal(cur->right);
        int notCur = max(left[0],left[1])+max(right[0],right[1]);
        int getCur = cur->val + left[0] + right[0]; 
        return {notCur, getCur};
    }
};