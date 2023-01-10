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
    int ans = 0;//Ans
    int sum = 0;//Path
    int sumNumbers(TreeNode* root) {
        sum = 10*sum+root->val;//4,49,495,491,(Deal with the mid node first)
        // cout<<"sum"<<sum<<endl;
        if(root->left==NULL&&root->right==NULL){//If meet leaf, save the result.
            ans+=sum;//495,495+491,
            return ans;
        }
        if(root->left){//Recursive left
            sumNumbers(root->left);
            sum-=root->left->val;//490,490 (Backtracking: Because the sum is add by root->left so need to subtract it)
            sum/=10;//49,49
        } 
        if(root->right){
            sumNumbers(root->right);
            sum-=root->right->val;//490,490 (Backtracking: Because the sum is add by root->right so need to subtract it)
            sum/=10;//49,49
        } 
        return ans;//Return result.
    }
};