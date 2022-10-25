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
    bool isSymmetric(TreeNode* root) {
        return cmp(root->left, root->right);
    }
    bool cmp(TreeNode * n1, TreeNode * n2){
        if(n1==NULL&&n2!=NULL){
            return 0;
        }
        else if(n1!=NULL&&n2==NULL){
            return 0;
        }
        else if(n1==NULL&&n2==NULL){
            return 1;
        }
        else if(n1->val!=n2->val){
            return 0;
        }

        bool out = cmp(n1->left, n2->right);
        bool in = cmp(n1->right, n2->left);
        return out&&in;
    }
};