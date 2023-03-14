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
    int pre = 0;
    TreeNode* convertBST(TreeNode* root) {
        /*
            Input:  [4, 1, 6, 0, 2, 5, 7,  null, null, null, 3, null,null,null, 8]
            Output: [30,36,21,36,35,26,15, null, null, null, 33,null,null,null, 8]
        */
        if(!root) return NULL;
        root->right = convertBST(root->right);
        root->val+=pre;
        pre = root->val;
        root->left = convertBST(root->left);
        return root;
    }
};