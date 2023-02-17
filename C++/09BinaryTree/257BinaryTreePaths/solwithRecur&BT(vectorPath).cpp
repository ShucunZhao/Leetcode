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
    void traverse(TreeNode * node, vector<int> & subPath, vector<string> & path){
        subPath.push_back(node->val);
        if(node->left==NULL&&node->right==NULL){
            /*
            string str("");
            */
            stringstream ss;
            for(int i=0;i<subPath.size()-1;i++){
                /*
                str+=to_string(subPath[i]);
                str+="->";
                */
                ss<<subPath[i]<<"->";
            }
            ss<<subPath[subPath.size()-1];
            path.push_back(ss.str());
            /*
            str+=to_string(subPath[subPath.size()-1]);
            path.push_back(str);
            */
            return;
        }
        if(node->left!=NULL){
            traverse(node->left, subPath, path);
            subPath.pop_back();
        }
        if(node->right!=NULL){
            traverse(node->right, subPath, path);
            subPath.pop_back();
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<int> subPath;
        vector<string> path;
        if(root==NULL){
            return path;
        }
        traverse(root, subPath, path);
        return path;
    }
};