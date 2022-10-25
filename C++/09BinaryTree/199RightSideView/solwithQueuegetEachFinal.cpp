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
        T val;
        Node * l;
        Node * r;
        Node(T & In):val(In){}
        Node(T & In, Node * left, Node * right):val(In),l(left),r(right){}
    };
    */
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> qt;
        vector<int> ans;
        if(root!=NULL){
            qt.push(root);            
        }
        else{
            return {};
        }
        int size;
        while(!qt.empty()){
            size = qt.size();
            while(size--){
                TreeNode * cur = qt.front();
                if(cur!=NULL){
                    if(cur->left!=NULL){
                         qt.push(cur->left);
                    }
                    if(cur->right!=NULL){
                        qt.push(cur->right);
                    }
                }
                if(size==0){
                    ans.push_back(cur->val);
                }
                qt.pop();
            }
        }
        return ans;
    }
};