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
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()){
            TreeNode * cur = st.top();
            st.pop();
            if(cur!=NULL){
                ans.push_back(cur->val);
                st.push(cur->right);
                st.push(cur->left);
            }
        }
        return ans;
    }
    // void traverse(TreeNode * cur, vector<int> & ans){
    //     if(cur==NULL){
    //         return;
    //     }
    //     ans.push_back(cur->val);
    //     traverse(cur->left, ans);
    //     traverse(cur->right, ans);
    // }
};