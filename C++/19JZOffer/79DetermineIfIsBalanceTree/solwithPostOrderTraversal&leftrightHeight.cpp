class Solution {
public:
    int getHeight(TreeNode * root){
        if(!root) return 0;
        int L = getHeight(root->left);
        if(L==-1) return -1;
        int R = getHeight(root->right);
        if(R==-1) return -1;
        if(abs(L-R)>1) return -1;
        return max(L,R)+1;
    }
    bool IsBalanced_Solution(TreeNode* pRoot) {
        if(!pRoot) return true;
        return getHeight(pRoot)!=-1;
    }
};