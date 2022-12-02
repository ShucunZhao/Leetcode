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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int cntA = 0, cntB = 0;
        ListNode * curA = headA;
        ListNode * curB = headB;
        while(curA){
            cntA++;
            curA=curA->next;
        }
        while(curB){
            cntB++;
            curB=curB->next;
        }
        int diff = abs(cntA-cntB);
        if(cntA>cntB){
            while(diff--){
                headA=headA->next;
            }
        }
        else{
            while(diff--){
                headB=headB->next;
            }
        }
        while(headA!=NULL&&headB!=NULL){
            if(headA==headB) return headA;
            headA=headA->next;
            headB=headB->next;
        }
        return NULL;
    }
};