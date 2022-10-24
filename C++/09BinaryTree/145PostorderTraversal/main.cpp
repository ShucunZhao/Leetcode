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
    template<typename T>
    class Node{
        T val;
        Node * left;
        Node * right;
        Node(T In):val(In){}
        Node(T In, Node * leftIn, Node * rightIn):val(In),left(leftIn),right(rightIn){}
    };
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        traverse(root, ans);
        return ans;
    }
    void traverse(TreeNode * cur, vector<int> & ans){
        if(cur==NULL){
            return;
        }
        traverse(cur->left, ans);
        traverse(cur->right, ans);
        ans.push_back(cur->val);
    }
};