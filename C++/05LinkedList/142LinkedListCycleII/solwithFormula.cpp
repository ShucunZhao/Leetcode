/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        /*    
                            r             
                            l 
          dum [3,2,0,-4,5,6,7,8]
                 2,0,-4,5,6,7,8
                x                   y
        ------------------|---------
                          |        |
                         z---------O
        1.First condition:
        if O is the meeting point, we can get the fomula:
            S(slow) = x+y;
            S(fast) = x+y+n(y+z);
        because fast go two steps while slow go one each time, so:
            2*S(slow) = S(fast)
            2*(x+y)   = x+y+n(y+z)
                x+y   = n(y+z)
                if n is 1:
                 x+y  = y+z
           ---->   x  = z 
        2. Second condition:
          if move p1 from O and move p2 from head they will meet in circle entry because
          x is equal to z, then we can get the entry node.
        */
        if(head==NULL||head->next==NULL) return NULL;
        ListNode * p1 = head;
        ListNode * p2 = head;
        while(p1!=NULL&&p2!=NULL&&p2->next!=NULL){
            p1 = p1->next;
            p2 = p2->next->next;
            if(p1==p2){
                break;
            }
        }
        // cout<<"p1:"<<p1->val;
        // cout<<"p2:"<<p2->val;
        p1 = head;
        while(p1!=NULL&&p2!=NULL&&p2->next!=NULL){
            if(p1==p2) return p1;
            p1 = p1->next;
            p2 = p2->next;
        }
        return NULL;
    }
};