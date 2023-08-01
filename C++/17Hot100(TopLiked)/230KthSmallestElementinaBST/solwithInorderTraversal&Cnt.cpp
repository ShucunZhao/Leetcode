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
    int ans = -1;
    int cnt = 0;
    int kthSmallest(TreeNode* root, int k) {
        if(!root) return -1;
        int L = kthSmallest(root->left, k);
        cnt++;
        if(cnt==k){
            ans = root->val;
            return ans;
        }
        int R = kthSmallest(root->right, k);
        if(L!=-1) return L;
        if(R!=-1) return R;
        return ans;
    }
};