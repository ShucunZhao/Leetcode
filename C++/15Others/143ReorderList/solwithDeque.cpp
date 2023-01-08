class Solution {
public:
    void reorderList(ListNode* head) {
        if(head==NULL||head->next==NULL) return;
        deque<ListNode*> deq;
        ListNode * cur = head->next;
        while(cur){
            deq.push_back(cur);
            cur=cur->next;
        }
        bool even = 1;
        cur = head;
        ListNode * node;
        while(!deq.empty()){
            if(even){
                node = deq.back();
                deq.pop_back();
                even = 0;
            }
            else{
                node = deq.front();
                deq.pop_front();
                even = 1;
            }
            cur->next = node;
            cur = cur->next;
        }
        cur->next = NULL;
        return;
    }
};