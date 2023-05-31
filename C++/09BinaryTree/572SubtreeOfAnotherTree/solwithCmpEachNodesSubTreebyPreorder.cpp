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
    bool cmpSub(TreeNode * root, TreeNode * subRoot){
        if(!root&&!subRoot) return true;
        else if(!root&&subRoot) return false;
        else if(root&&!subRoot) return false;
        else if(root->val==subRoot->val){
            return cmpSub(root->left, subRoot->left)&&cmpSub(root->right, subRoot->right);
        }
        return false;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot){
        if(!root&&subRoot) return false;
        bool M = cmpSub(root, subRoot);
        if(M) return true;
        bool L = isSubtree(root->left, subRoot);
        if(L) return true;
        bool R = isSubtree(root->right, subRoot);
        if(R) return true;
        return false;
    }
};