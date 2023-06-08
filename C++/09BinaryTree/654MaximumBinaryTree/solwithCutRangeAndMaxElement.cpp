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
    TreeNode * build(vector<int>& nums){
        if(nums.size()==0) return NULL;
        int maxV = *max_element(nums.begin(), nums.end());
        int maxI = max_element(nums.begin(),nums.end()) - nums.begin();
        TreeNode * root = new TreeNode(maxV);
        vector<int> left(nums.begin(), nums.begin()+maxI);
        vector<int> right(nums.begin()+maxI+1, nums.end());
        root->left = build(left);
        root->right = build(right);
        // for(int i : right) cout<<i<<",";
        // cout<<endl;
        // cout<<"maxI:"<<maxI<<endl;
        //  cout<<"maxV:"<<maxV<<endl;
        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return build(nums);
    }
};