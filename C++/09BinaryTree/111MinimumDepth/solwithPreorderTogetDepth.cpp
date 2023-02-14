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
    void getDepth(TreeNode * cur, int depth, int & minN){
        if(cur->left==NULL&&cur->right==NULL){
            minN = min(minN, depth);
            return;
        }
        if(cur->left){
            getDepth(cur->left, depth+1, minN);
        }
        if(cur->right){
            getDepth(cur->right, depth+1, minN);
        }
        return;
    }
    int minDepth(TreeNode* root) {
        int minN = INT_MAX;
        int depth = 1;
        if(!root) return 0;
        getDepth(root, depth, minN);
        return minN;
    }
};