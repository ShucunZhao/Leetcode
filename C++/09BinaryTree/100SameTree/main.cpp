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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return cmp(p,q);
    }
    bool cmp(TreeNode * n1, TreeNode * n2){
        if(n1==NULL&&n2==NULL){
            return 1;
        }
        else if(n1==NULL&&n2!=NULL){
            return 0;
        }
        else if(n1!=NULL&&n2==NULL){
            return 0;
        }
        else if(n1->val!=n2->val){
            return 0;
        }
        bool out = cmp(n1->left, n2->left);
        bool in = cmp(n1->right, n2->right);
        return out&&in;
    }
};