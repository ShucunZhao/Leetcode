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
    int depthMax = INT_MIN;
    int ans;
    int findBottomLeftValue(TreeNode* root) {
        if(root==NULL) return 0;
        traverse(root, 0);
        return ans;
    }
    void traverse(TreeNode* cur, int depth){
        if(cur->left==NULL&&cur->right==NULL){
            if(depth>depthMax){
                depthMax=depth;
                ans = cur->val;
            } 
        }
        if(cur->left!=NULL){
            depth++;
            traverse(cur->left, depth);
            depth--;
        }
        if(cur->right!=NULL){
            depth++;
            traverse(cur->right, depth);
            depth--;
        }    
        return;
    }
};