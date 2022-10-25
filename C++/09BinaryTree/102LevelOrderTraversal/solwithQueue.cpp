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
        Node * l;
        Ndde * r;
        Node(T In):val(In){}
        Node(T In, Node * left, Node * right):val(In),left(l),right(r){}
    };
    */
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> qt;
        vector<vector<int> > rst;
        if(root!=NULL){
            qt.push(root);
        }
        else{//When root is NULL return {}.
            return {};
        }
        int size;
        while(!qt.empty()){
            size = qt.size();
            vector<int> temp;
            while(size--){
                TreeNode * cur = qt.front();
                if(cur!=NULL){
                    temp.push_back(cur->val);
                    if(cur->left!=NULL){
                        qt.push(cur->left);
                    }
                    if(cur->right!=NULL){
                        qt.push(cur->right);
                    }
                }
                qt.pop();
            }
            rst.push_back(temp);
        }
        return rst;
    }
};