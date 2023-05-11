/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 *	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * };
 */
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param proot TreeNode类 
     * @param k int整型 
     * @return int整型
     */
    int ans = -1;
    int cnt = 0;
    void inorder(TreeNode * root, int k){
        if(!root||cnt>k) return;
        inorder(root->left, k);
        cnt++;
        if(cnt==k) ans = root->val;
        inorder(root->right, k);
        return;
    } 
    int KthNode(TreeNode* proot, int k) {
        // write code here
        if(!proot||k==0) return -1;
        inorder(proot, k);
        return ans;
    }
};