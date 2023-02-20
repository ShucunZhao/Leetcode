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
    int ans;
    int maxDepth = 0;
    void getHeight(TreeNode * root, int depth){
        if(!root) return;
        if(!root->left&&!root->right){
            return;
        } 
        if(depth>maxDepth){
            if(root->left){
                ans = root->left->val;
            }
            else{
                ans = root->right->val;
            }
            maxDepth = depth;
        }
        getHeight(root->left, depth+1);
        getHeight(root->right, depth+1);
        return;
    }
    int findBottomLeftValue(TreeNode* root) {
        if(!root->left&&!root->right) return root->val;
        getHeight(root, 1);
        return ans;
    }
};