/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> ms;
        for(Node * cur=head;cur;cur=cur->next){
            ms[cur] = new Node(cur->val);
        }
        for(Node * cur=head;cur;cur=cur->next){
            if(cur->next) ms[cur]->next = ms[cur->next];
            if(cur->random) ms[cur]->random = ms[cur->random];
        }
        return ms[head];
    }
};