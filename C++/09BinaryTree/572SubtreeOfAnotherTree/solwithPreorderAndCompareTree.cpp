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
    bool isSame(TreeNode * p, TreeNode * q){
        if(!p&&!q) return 1;
        else if(!p&&q) return 0;
        else if(p&&!q) return 0;
        else if(p->val!=q->val) return 0;
        return isSame(p->left, q->left)&&isSame(p->right, q->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root==NULL&&subRoot!=NULL) return 0;
        bool M = isSame(root, subRoot);
        bool L = isSubtree(root->left, subRoot);
        bool R = isSubtree(root->right, subRoot);
        return M||L||R;
    }
};