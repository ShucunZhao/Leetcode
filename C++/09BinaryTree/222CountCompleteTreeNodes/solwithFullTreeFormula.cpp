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
    int countNodes(TreeNode* root) {
        return getNum(root);
    }
    int getNum(TreeNode * n){
        if(n==NULL) return 0;
        TreeNode * l = n->left;
        TreeNode * r = n->right;
        int numL, numR = 0;
        while(l){
            numL++;
            l=l->left;
        }
        while(r){
            numR++;
            r=r->right;
        }
        if(numL==numR){
            return (2<<numL)-1;
        }
        int left = getNum(n->left);
        int right = getNum(n->right);
        return left+right+1;
    }
};