/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {//Different with binary tree: Just travserse all childrens instead of only left and right.
public:
    vector<vector<int>> levelOrder(Node* root) {
        queue<Node*> qt;
        if(root!=NULL){
            qt.push(root);
        }
        else{
            return {};
        }
        vector<vector<int> > ans;
        int size;
        while(!qt.empty()){
            size = qt.size();
            vector<int> tmp;
            while(size--){
                Node * cur = qt.front();
                qt.pop();
                if(cur!=NULL){
                    tmp.push_back(cur->val);
                    for(auto x : cur->children){
                        if(x!=NULL){
                            qt.push(x);
                        }
                    }
                }
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};