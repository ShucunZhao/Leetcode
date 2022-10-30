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
    TreeNode* convertBST(TreeNode* root) {
        if(root==NULL) return NULL;
        int sum = 0;
        traverse(root, sum);
        return root;
    }
    void traverse(TreeNode * cur, int & sum){
        if(cur==NULL) return;
        traverse(cur->right, sum);
        cur->val+=sum;
        sum=cur->val;
        traverse(cur->left, sum);
    }
};