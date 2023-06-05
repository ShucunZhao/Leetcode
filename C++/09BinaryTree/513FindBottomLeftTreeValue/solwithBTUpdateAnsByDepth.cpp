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
    int maxDepth = 0;
    int ans = -1;
    int findBottomLeftValue(TreeNode* root) {
        if(!root) return ans;
        traverse(root, 1);
        return ans;
    }
    void traverse(TreeNode * root, int curDepth){
        if(curDepth>maxDepth){
            maxDepth = curDepth;
            ans = root->val;
        }
        //int L=0,R=0;
        if(root->left){
            traverse(root->left, curDepth+1);
        }
        if(root->right){
            traverse(root->right, curDepth+1);
        }
        return;
    }
};