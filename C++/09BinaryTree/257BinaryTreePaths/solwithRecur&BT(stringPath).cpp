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
    void backtracking(TreeNode * cur, vector<string> & path, vector<string> & ans){
        if(!cur->left&&!cur->right){
            stringstream ss;
            for(string s : path){
                // cout<<s<<endl;
                ss<<s;
            }
            ans.push_back(ss.str()+to_string(cur->val));
            return;
        }
        string str = to_string(cur->val)+"->";
        if(cur->left){
            path.push_back(str);//1->, 2->
            backtracking(cur->left, path, ans);
            path.pop_back();
        }
        if(cur->right){
            path.push_back(str);//1->, 2->
            backtracking(cur->right, path, ans);  
            path.pop_back();
        }
        return;
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> path;
        vector<string> ans;
        backtracking(root, path, ans);
        return ans;   
    }
};