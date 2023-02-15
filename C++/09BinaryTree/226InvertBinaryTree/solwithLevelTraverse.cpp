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
    TreeNode* invertTree(TreeNode* root) {
        /*
                    4
                7      2
              9  6   3   1
        */
        if(!root) return NULL;
        queue<TreeNode*> Q;
        Q.push(root);
        int size;
        while(!Q.empty()){
            size = Q.size();
            while(size--){
                TreeNode * cur = Q.front();
                Q.pop();
                swap(cur->left, cur->right);
                if(cur->left) Q.push(cur->left);
                if(cur->right) Q.push(cur->right);
            }
        }
        return root;
    }
};