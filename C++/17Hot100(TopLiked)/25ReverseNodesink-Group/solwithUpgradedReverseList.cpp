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
 /*
    sol: cut the list into k nodes groups, then reverse each group and 
        splice them together.
 */
class Solution {
public:
    ListNode * reverse(ListNode * head){
        /*  
                   p  c t     p c
            head = N [1,2,3,4,5]

        */
        ListNode * pre = NULL;
        ListNode * cur = head;  
        while(cur){
            ListNode * tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }
        return pre;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        /*
                    l  
                          r-N        
            head = dum [1,2,3,4,5], k = 2
                       lN
                            rN
                         l
                             r       
                   dum 2,1,3,4,5
                        

            Output:    [2,1,4,3,5]
        */
        ListNode * dum = new ListNode();
        dum->next = head;
        ListNode * l = dum;
        ListNode * r = dum;
        while(1){
            for(int i=0;i<k&&r!=NULL;i++) r=r->next;
            if(r==NULL) break;
            ListNode * lNext = l->next; 
            ListNode * rNext = r->next;
            r->next = NULL;
            l->next = reverse(l->next);
            lNext->next = rNext;
            l = lNext;
            r=  lNext;
        }
        return dum->next;
    }
};





