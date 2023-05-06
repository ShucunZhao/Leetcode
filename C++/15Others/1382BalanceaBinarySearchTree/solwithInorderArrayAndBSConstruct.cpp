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
    void Inorder(TreeNode * root, vector<int> & arr){
        if(!root) return;
        Inorder(root->left, arr);
        arr.push_back(root->val);
        Inorder(root->right, arr);
        return;
    }
    TreeNode * construct(vector<int> & arr, int l, int r){
        if(l>r) return NULL;
        int m = l + (r-l)/2;
        TreeNode * root = new TreeNode(arr[m]);
        root->left = construct(arr, l, m-1);
        root->right = construct(arr, m+1, r);
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        /*
                   l m
            nums: [1,2,3,4]
                         r
        */
        vector<int> arr;
        Inorder(root, arr);
        return construct(arr, 0, arr.size()-1);
    }
};