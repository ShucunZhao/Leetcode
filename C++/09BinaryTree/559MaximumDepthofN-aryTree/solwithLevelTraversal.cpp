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

class Solution {
public:
    int maxDepth(Node* root) {
        if(!root) return 0;
        queue<Node*> Q;
        Q.push(root);
        int size;
        int ans = 0;
        while(!Q.empty()){
            size = Q.size();
            while(size--){
                Node * cur = Q.front();
                Q.pop();
                for(auto x : cur->children){
                    if(x) Q.push(x);
                }
            }
            ans++;
        }
        return ans;
    }
};