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
    void traverse(TreeNode * cur, queue<TreeNode*> & Q){
        if(cur==NULL) return;
        Q.push(cur);
        traverse(cur->left, Q);
        traverse(cur->right, Q);
        return;
    }
    void flatten(TreeNode* root) {
        /*
            【1,2,3,4,5,6
        */   
        if(!root) return;
        queue<TreeNode*> Q;
        traverse(root, Q);
        TreeNode * dum = new TreeNode();
        TreeNode * cur = dum;
        while(!Q.empty()){
            cur->left = NULL;
            cur->right = Q.front();
            Q.pop();
            cur=cur->right;
        }
        return;
    }
};