
/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
    vector<vector<int> > Print(TreeNode* pRoot) {
        if(!pRoot){
            return {};
        }
        queue<TreeNode*> Q;
        Q.push(pRoot);
        int size;
        bool flag = true;
        vector<int> path;
        vector<vector<int> > ans;
        while(!Q.empty()){
            size = Q.size();
            while(size--){
                TreeNode * cur = Q.front();
                Q.pop();
                if(cur->left){
                    Q.push(cur->left);
                }
                if(cur->right){
                    Q.push(cur->right);
                }
                path.push_back(cur->val);
            }
            if(flag){
                ans.push_back(path);
                flag = false;
            }
            else{
                reverse(path.begin(), path.end());
                ans.push_back(path);
                flag = true;
            }
            path.clear();
        }
        return ans;
    }
    
};