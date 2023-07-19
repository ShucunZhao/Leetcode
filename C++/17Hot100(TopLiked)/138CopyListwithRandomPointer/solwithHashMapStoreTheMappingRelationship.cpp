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
        Node * c1 = head;
        while(c1){
            ms[c1] = new Node(c1->val);
            c1 = c1->next;
        }
        c1 = head;
        while(c1){
            ms[c1]->next = ms[c1->next];
            ms[c1]->random = ms[c1->random];
            c1 = c1->next;
        }
        return ms[head];
    }
};