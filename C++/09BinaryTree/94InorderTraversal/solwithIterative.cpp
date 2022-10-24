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
    class Node{
    public:
        T val;
        Node * left;
        Node * right;
        Node(T In):val(In){}
        Node(T In, Node * leftIn, Node * rightIn):val(In),left(leftIn),right(rightIn){}
    };
    */
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> st;
        // traverse(root, ans);
        TreeNode * cur = root;
        while(cur!=NULL||!st.empty()){
            if(cur!=NULL){
                st.push(cur);
                cur = cur->left;
            }
            else{
                cur = st.top();
                ans.push_back(cur->val);
                st.pop();
                cur = cur->right;
            }
        }
        return ans;
    }
    // void traverse(TreeNode * cur, vector<int> & ans){
    //     if(cur==NULL){
    //         return;
    //     }
    //     traverse(cur->left, ans);
    //     ans.push_back(cur->val);
    //     traverse(cur->right, ans);
    // }
};