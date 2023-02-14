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
    void getDepth(TreeNode * cur, int & sum, int & maxN){
        maxN = max(maxN, sum);
        if(cur->left==NULL&&cur->right==NULL) return;
        if(cur->left){
            sum++;
            getDepth(cur->left, sum, maxN);
            sum--;
        }
        if(cur->right){
            sum++;
            getDepth(cur->right, sum, maxN);
            sum--;
        }
        return;
    }
    int maxDepth(TreeNode* root) {
        int maxN = 0;
        int sum = 1;
        if(!root) return maxN;
        getDepth(root, sum, maxN);
        return maxN;
    }
};