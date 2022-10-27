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
        if(nums.size()==1){
            return new TreeNode(nums[0]);
        }
        /*
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > maxValue) {
                maxValue = nums[i];
                maxValueIndex = i;
            }
        }
        */
        //Same as above but faster when using iterator to find maximum.
        vector<int>::const_iterator maxIt = max_element(nums.begin(), nums.end());
        int maxIndex = maxIt-nums.begin();
        // cout<<*maxIt<<endl;
        TreeNode * root = new TreeNode(*maxIt);
        if(maxIndex>0){
        // if(maxIt!=nums.begin()){
            vector<int> leftRange(nums.begin(), nums.begin()+maxIndex);
            root->left = constructMaximumBinaryTree(leftRange);
        }
        if(maxIndex<nums.size()-1){
            vector<int> rightRange(nums.begin()+maxIndex+1, nums.end());
            root->right = constructMaximumBinaryTree(rightRange);
        }
        return root;
    }
};