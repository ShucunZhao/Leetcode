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
    int sum = 0;
    int nodeSum = 0;
    // int traverse(TreeNode * root){
    //     if(!root) return 0;

    // }
    TreeNode* convertBST(TreeNode* root) {
        if(!root) return NULL;
        root->right = convertBST(root->right);
        // cout<<"root:"<<root->val<<endl;
        // cout<<"sum:"<<sum<<endl;
        // cout<<"nodeSum:"<<nodeSum<<endl;
        nodeSum+=root->val;//8,15,
        root->val+=sum;//8,15
        sum=nodeSum;//8,,
        root->left = convertBST(root->left);
        return root;
    }
};