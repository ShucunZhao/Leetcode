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
    int findBottomLeftValue(TreeNode* root) {
        if(!root) return -1;
        queue<TreeNode*> Q;
        Q.push(root);
        int size;
        int ans;
        while(!Q.empty()){
            size = Q.size();
            ans = (Q.front())->val;
            while(size--){
                TreeNode * cur = Q.front();
                Q.pop();
                if(cur->left) Q.push(cur->left);
                if(cur->right) Q.push(cur->right);
            }
        }
        return ans;
    }
};