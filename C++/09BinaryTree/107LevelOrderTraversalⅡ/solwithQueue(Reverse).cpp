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
        Node * r;
        Node(T In):val(In){}
        Node(T In, Node * left, Node * right):val(In),l(left),r(right){}
    };
    */
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        queue<TreeNode*> qt;
        vector<vector<int> > rst;
        if(root!=NULL){
            qt.push(root);
        }
        else{
            return {};
        }
        int size;
        while(!qt.empty()){
            size = qt.size();
            vector<int> tmp;
            while(size--){
                TreeNode * cur = qt.front();
                qt.pop();
                if(cur!=NULL){
                    tmp.push_back(cur->val);
                    if(cur->left!=NULL){
                        qt.push(cur->left);
                    }
                    if(cur->right!=NULL){
                        qt.push(cur->right);
                    }
                }
            }
            rst.push_back(tmp);
        }
        reverse(rst.begin(), rst.end());
        return rst;
    }
};