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
    int ans = 0;
    int postTraverse(TreeNode * root){
        if(!root) return 0;
        int L = postTraverse(root->left);
        int R = postTraverse(root->right);
        ans = max(ans, L+R);
        return max(L,R)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        postTraverse(root);
        return ans;
    }
};