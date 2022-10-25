/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> qt;
        if(root!=NULL){
            qt.push(root);
        }
        else{
            return NULL;
        }
        int size;
        while(!qt.empty()){
            size = qt.size();
            while(size--){
                Node * cur = qt.front();
                qt.pop();
                if(cur!=NULL){
                    cur->next = size==0 ? NULL : qt.front();
                    if(cur->left!=NULL){
                        qt.push(cur->left);
                    }
                    if(cur->right!=NULL){
                        qt.push(cur->right);
                    }
                }
            }
        }
        return root;
    }
};