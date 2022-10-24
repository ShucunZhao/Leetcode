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
    /*
    template<typename T>
    class TreeN{
    public:
        T val;
        TreeN * left;
        TreeN * right;
        TreeN(T in):val(in),left(NULL),right(NULL){}
        TreeN(T in, TreeN * leftIn, TreeN * rightIn):val(in),left(leftIn),right(rightIn){}
    };
    */
    vector<int> preorderTraversal(TreeNode * root) {
        vector<int> ans;
        traverse(root, ans);
        return ans;
    }
    void traverse(TreeNode * cur, vector<int> & ans){
        if(cur==NULL){
            return;
        }
        ans.push_back(cur->val);
        traverse(cur->left, ans);
        traverse(cur->right, ans);
    }
};