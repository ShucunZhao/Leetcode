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
    bool isBalanced(TreeNode* root) {
        if(root==NULL){
            return 1;
        }
        return getHeight(root)!=-1;
    }
    
    int getHeight(TreeNode * n){
        if(n==NULL) return 0;
        int leftH = getHeight(n->left);
        if(leftH==-1) return -1;
        int rightH = getHeight(n->right);
        if(rightH==-1) return -1;
        if(abs(leftH-rightH)>1) return -1;
        return max(leftH, rightH)+1;
    }
};