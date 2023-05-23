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
        /*

        */
        ListNode * c1 = headA, * c2 = headB;
        while(c1&&c2){
            c1=c1->next;
            c2=c2->next;
        }
        int diff = 0;
        bool A = true;
        if(c2) A = false;
        while(c2){
            diff++;
            c2=c2->next;
        }
        while(c1){
            diff++;
            c1=c1->next;
        }
        c1 = headA;
        c2 = headB;
        while(diff--){
            if(A){
                c1 = c1->next;
            }
            else{
                c2 = c2->next;
            }
        }
        while(c1&&c2){
            if(c1==c2) return c1;
            c1 = c1->next;
            c2 = c2->next;
        }
        return NULL;
    }
};