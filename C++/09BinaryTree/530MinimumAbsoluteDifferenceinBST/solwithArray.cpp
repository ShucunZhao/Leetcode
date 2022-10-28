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
    vector<int> ans;
    int getMinimumDifference(TreeNode* root) {
        if(root==NULL) return 0;
        ans.clear();
        traverse(root);
        int min = INT_MAX;
        for(int i=1;i<ans.size();i++){
            if((ans[i]-ans[i-1])<min){
                min = ans[i]-ans[i-1];
            }
        }
        return min;
    }
    void traverse(TreeNode * cur){
        if(cur==NULL) return;
        traverse(cur->left);
        ans.push_back(cur->val);
        traverse(cur->right);
    }
};