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
    TreeNode* deleteNode(TreeNode* root, int key) {
        /*
            In target node, let all left node to be the most left one of right node.
            And then let this right node be the child node of target's parent.
        */
        if(!root) return NULL;
        if(root->val==key){
            TreeNode * left = root->left;
            TreeNode * cur = root->right;
            if(!cur){
                return left;
            }
            while(cur->left){
                cur = cur->left;
            }
            cur->left = left;
            return root->right;
        }
        else if(root->val<key){
            root->right = deleteNode(root->right, key);
        }
        else{
            root->left = deleteNode(root->left, key);
        }
        return root;
    }
};