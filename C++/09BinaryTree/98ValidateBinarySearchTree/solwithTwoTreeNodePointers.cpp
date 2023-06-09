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
    //vector<int> arr;
    TreeNode * pre = NULL;
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        bool L = isValidBST(root->left);
        if(pre&&pre->val>=root->val) return false;
        pre = root;
        /*
        if(arr.size()>0){
            if(root->val<=arr.back()){
                return false;
            }
        }
        arr.push_back(root->val);
        */
        bool R = isValidBST(root->right);
        return L&&R;
    }
};