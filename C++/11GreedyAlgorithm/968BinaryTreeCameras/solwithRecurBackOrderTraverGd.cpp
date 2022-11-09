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
/*
 * 0: no cover
 * 1: has camera
 * 2: has cover
*/ 
class Solution {
public:
    int ans;
    int traversal(TreeNode * cur){
        if(cur==NULL) return 2;
        int left = traversal(cur->left);
        int right = traversal(cur->right);
        if(left==2&&right==2) return 0;
        if(left==0||right==0){
            ans++;
            return 1;
        }
        if(left==1||right==1) return 2;
        return -1;
    }
    int minCameraCover(TreeNode* root) {
        ans = 0;
        if(traversal(root)==0){
            ans++;
        }
        return ans;
    }
};