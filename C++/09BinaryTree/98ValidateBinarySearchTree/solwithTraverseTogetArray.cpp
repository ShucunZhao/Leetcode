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
    bool isValidBST(TreeNode* root) {
        if(root==NULL) return 1;
        ans.clear();
        getArray(root);
        for(int i=0,j=1;j<ans.size();i++,j++){
            if(ans[i]>=ans[j]) return 0;
        }
        return 1;
    }
    void getArray(TreeNode * root){
        if(root==NULL) return;
        getArray(root->left);
        ans.push_back(root->val);
        getArray(root->right);
    }
};