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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        /*
                     0     2   4
            nums = [-10,-3,0,5,9]
        */
        if(nums.size()==0) return NULL;
        int l=0, r=nums.size()-1;
        int m = l+(r-l)/2;
        TreeNode * root = new TreeNode(nums[m]);
        if(nums.size()==1) return root;
        vector<int> L(nums.begin(), nums.begin()+m);
        vector<int> R(nums.begin()+m+1, nums.end());
        root->left = sortedArrayToBST(L);
        root->right = sortedArrayToBST(R);
        /*
        for(int i : R) cout<<i<<",";
        cout<<endl;
        */
        return root;
    }
};