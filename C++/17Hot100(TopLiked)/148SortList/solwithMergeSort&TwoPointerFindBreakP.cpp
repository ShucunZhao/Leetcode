/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        /*
                         l
                      b       r
            head = [1,4,|2,3]
                    h 
                                 
                    1,4          2,3
                     L  R
                    1, 4
                    dum-1-4    
                          l
                        b      r
             head = [-1,5,3,4,0]
                    -1,5  3 , 4,0
                              4, 0
        */
        if(!head||!head->next) return head;
        ListNode * brk;
        ListNode * l = head, * r = head;
        for(l,r;r!=NULL&&r->next!=NULL;l=l->next){
            r=r->next->next;
            if(!r||!r->next) brk = l;
        }
        brk->next = NULL;
        ListNode * L = sortList(head);
        ListNode * R = sortList(l);
        ListNode * dum = new ListNode(0);
        ListNode * cur = dum;
        while(L||R){
            if(!R||(L&&R&&L->val<R->val)){
                cur->next = L;
                cur = cur->next;
                L = L->next;
            }
            else{
                cur->next = R;
                cur = cur->next;
                R = R->next;
            }
        }
        return dum->next;
    }
};