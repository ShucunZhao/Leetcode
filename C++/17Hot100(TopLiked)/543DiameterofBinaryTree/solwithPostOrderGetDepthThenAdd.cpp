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
    // int maxL = 0;
    // int maxR = 0;
    int ans = 0;
    int getDepth(TreeNode * root){
        if(!root) return 0;
        int L = getDepth(root->left);
        int R = getDepth(root->right);
        ans = max(ans, L+R);
        // maxL = max(L, maxL);
        // maxR = max(R, maxR);
        // cout<<"cur:"<<root->val<<",maxL:"<<maxL<<",maxR:"<<maxR<<endl;
        return max(L,R)+1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        getDepth(root);
        // cout<<"maxL:"<<maxL<<endl;
        // cout<<"maxR:"<<maxR<<endl;
        return ans;
    }
};