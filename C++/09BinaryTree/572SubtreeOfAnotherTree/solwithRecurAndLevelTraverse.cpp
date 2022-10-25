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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        queue<TreeNode*> qt;
        if(root!=NULL){
            qt.push(root);
        }
        else{
            return root==subRoot;
        }
        TreeNode * cur = NULL;
        int size;
        while(!qt.empty()){
            size = qt.size();
            while(size--){
                TreeNode * cur = qt.front();
                qt.pop();
                if(cmp(cur,subRoot)){
                    return 1;
                }
                if(cur!=NULL){
                    if(cur->left)qt.push(cur->left);
                    if(cur->right)qt.push(cur->right);
                }
            }
        }
        return 0;
    }
    bool cmp(TreeNode * n1, TreeNode * n2){
        if(n1==NULL&&n2==NULL) return 1;
        else if(n1==NULL&&n2!=NULL) return 0;
        else if(n1!=NULL&&n2==NULL) return 0;
        else if(n1->val!=n2->val) return 0;
        return cmp(n1->left, n2->left)&&cmp(n1->right,n2->right);
    }
};