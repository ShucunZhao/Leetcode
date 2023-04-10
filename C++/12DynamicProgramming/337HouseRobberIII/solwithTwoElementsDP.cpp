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
    /*
        Use a two-D dp vector to represent the situations that rob current node house or not.
        vector<int> dp;(whose size is 2)
        Use the postorder traversal to get the left and right childNode answer and compare in
        middle parent node:
        dp[0]: get cur, dp[1]: don't get cur.
        if(!root) return;
        vector<int> L = ......
        vector<int> R = ......
        1.Use current node value:
                      dp[0] = root->val + L[1] + R[1]
        2.Don't use current node value:
                      dp[1] = max(L[0], L[1])+max(R[0], R[1]);
        return {dp[0], dp[1]};
    */
    vector<int> postTraverse(TreeNode * root){
        if(!root){
            return {0,0};
        }
        vector<int> L = postTraverse(root->left);
        vector<int> R = postTraverse(root->right);
        int getCur = root->val+L[1]+R[1];
        int notCur = max(L[0], L[1])+max(R[0], R[1]);
        return {getCur, notCur};
    }
    int rob(TreeNode* root) {
        if(!root) return 0;
        vector<int> dp = postTraverse(root);
        return max(dp[0], dp[1]);
    }
};