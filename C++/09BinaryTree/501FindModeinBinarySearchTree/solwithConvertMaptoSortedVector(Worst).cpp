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
class Solution {//This solution usually use in the normal binary tree, but binary search tree has more effective method!
public:
    unordered_map<int, int> mt;
    static bool cmp(const pair<int,int> & p1, const pair<int,int> & p2){
            return p1.second > p2.second;
        }
    void traverse(TreeNode * cur){
        if(cur==NULL) return;
        traverse(cur->left);
        mt[cur->val]++;
        traverse(cur->right);
        return;
    }
    vector<int> findMode(TreeNode* root) {
        if(root==NULL) return {};
        traverse(root);
        vector<pair<int,int> > sortVec(mt.begin(), mt.end());
        // for(auto x : sortVec){
        //     cout<<x.first<<","<<x.second<<endl;
        // }
        sort(sortVec.begin(), sortVec.end(), cmp);
        int index = 0;
        vector<int> ans;
        ans.push_back(sortVec[0].first);
        for(int i=1;i<sortVec.size();i++){
            if(sortVec[i].second==sortVec[i-1].second){
                ans.push_back(sortVec[i].first);
            }
            else{
                break;
            }
        }
        return ans;
    }
};