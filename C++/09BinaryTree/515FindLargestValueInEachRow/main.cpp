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
        Node():val(0),l(NULL),r(NULL){}
        Node(T In):val(In){}
        Node(T In, Node * l, Node * r){}
    };
    */
    vector<int> largestValues(TreeNode* root) {
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
            int temp = INT_MIN;
            while(size--){
                TreeNode * cur = qt.front();
                qt.pop();
                if(cur!=NULL){
                    temp = temp > cur->val ? temp : cur->val;
                    if(cur->left!=NULL){
                        qt.push(cur->left);
                    }
                    if(cur->right!=NULL){
                        qt.push(cur->right);
                    }
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};