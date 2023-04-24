
/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
    bool cmp(TreeNode * left, TreeNode * right){
        if(left==NULL&&right==NULL){
            return true;
        }
        else if(left==NULL&&right!=NULL){
            return false;
        }
        else if(left!=NULL&&right==NULL){
            return false;
        }
        else if(left->val!=right->val){
            return false;
        }
        return cmp(left->left, right->right)&&cmp(left->right, right->left);
    }
    bool isSymmetrical(TreeNode* pRoot) {
        if(!pRoot) return 1;
        return cmp(pRoot->left, pRoot->right);
    }

};