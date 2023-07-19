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
        /*         
            head =dum [7,null] - [13,0] - [11,4] - [10,2] - [1,0]
        */
        if(!head) return NULL;
        unordered_map<Node*, int> ms;
        Node * dum1 = new Node(0);
        dum1->next = head;
        int index = 0;
        ms[head] = index;
        index++;
        Node * dum2 = new Node(0);
        dum2->next = new Node(head->val);
        Node * c1 = dum1->next->next;
        Node * c2 = dum2->next;
        while(c1){
            ms[c1] = index;
            index++;
            c2->next = new Node(c1->val);
            c1 = c1->next;
            c2 = c2->next;
        }
        c2 = dum2->next;
        c1 = dum1->next;//c1: head.
        while(c2){
            if(c1->random){
                int i = ms[c1->random];
                Node * tmp = dum2->next;
                while(i--){
                    tmp = tmp->next;
                }
                c2->random = tmp;
            }
            c2 = c2->next;
            c1 = c1->next;
        }
        return dum2->next;
    }
};

























