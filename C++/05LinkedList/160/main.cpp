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
        ListNode * curA = headA;
        ListNode * curB = headB;
        int lenA = 0, lenB = 0;
        while(curA!=NULL){
            lenA++;
            curA = curA->next;
        }
        while(curB!=NULL){
            lenB++;
            curB = curB->next;
        }    
        curA = headA;
        curB = headB;
        bool flag = 1 ? lenA > lenB : 0;
        int diff;
        if(flag){
            diff=lenA-lenB;
            while(diff--){
                curA=curA->next;
            }
        }
        else{
            diff=lenB-lenA;
            curB = headB;
            while(diff--){
                curB=curB->next;
            }
        }
        while(curA!=NULL){
            if(curA==curB){
                return curA;
            }
            curA = curA->next;
            curB = curB->next;
        }
        return NULL;
    }
};