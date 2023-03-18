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
    //vector<int> vec;
    int cnt = 0;
    int ans = -1;
    void traverse(TreeNode* root, int k){
        if(!root||ans!=-1) return;
        traverse(root->left, k);
        cnt++;
        if(cnt==k){
            ans = root->val;
            return;
        }
        //vec.push_back(root->val);
        traverse(root->right, k);
        return;
    }
    
    int kthSmallest(TreeNode* root, int k) {
        traverse(root, k);
        return ans;
        //return vec[k-1];
    }
};