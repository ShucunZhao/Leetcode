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
    int curMax = INT_MIN;
    int postorder(TreeNode * root){
        if(!root) return 0;
        int sum = 0;
        int L = postorder(root->left);
        int R = postorder(root->right);
        L = max(L,0);
        R = max(R,0);
        sum =L+R+root->val;
        if(sum>curMax){
            curMax = sum;
        }
        return root->val+max(L,R);
    }
    int maxPathSum(TreeNode* root) {
        if(!root) return 0;
        postorder(root);
        // postorder(root->left);
        // postorder(root->right);
        return curMax;
    }
};