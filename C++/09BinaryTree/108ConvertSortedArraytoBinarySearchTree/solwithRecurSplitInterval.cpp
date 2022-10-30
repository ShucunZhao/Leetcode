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
        return construct(nums, 0, nums.size()-1);
    }
    TreeNode * construct(vector<int> & nums, int l, int r){
        if(l>r){
            return NULL;
        }
        int mid = r-(r-l)/2;
        TreeNode * node = new TreeNode(nums[mid]);
        node->left = construct(nums, l, mid-1);
        node->right = construct(nums, mid+1, r);
        return node;
    }
};