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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if(nums.size()==0) return NULL;
        int rVal = *max_element(nums.begin(), nums.end());
        // cout<<rVal;
        TreeNode * root = new TreeNode(rVal);
        if(nums.size()==1) return root;
        int rI = max_element(nums.begin(), nums.end())-nums.begin();
        // cout<<rI<<endl;
        vector<int> L(nums.begin(), nums.begin()+rI);
        vector<int> R(nums.begin()+rI+1, nums.end());
        root->left = constructMaximumBinaryTree(L);
        root->right = constructMaximumBinaryTree(R);
        return root;
    }
};