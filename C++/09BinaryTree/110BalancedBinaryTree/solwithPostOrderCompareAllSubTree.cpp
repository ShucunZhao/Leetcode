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
    int getH(TreeNode * root){
        if(!root) return 0;
        int L = getH(root->left);
        int R = getH(root->right);
        return max(L,R)+1;
    }
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        bool left = isBalanced(root->left);
        bool right = isBalanced(root->right);
        if(!left||!right) return false;
        int L = getH(root->left);
        int R = getH(root->right);
        //cout<<"L:"<<L<<",R:"<<R<<endl;
        //if() return false;
        return abs(L-R)<=1;
    }
};