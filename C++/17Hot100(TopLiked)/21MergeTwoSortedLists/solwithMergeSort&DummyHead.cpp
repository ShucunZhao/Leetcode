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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode * l1 = list1, * l2 = list2;
        ListNode * dum = new ListNode(0);
        ListNode * cur = dum;
        while(l1&&l2){
            if(l1->val<l2->val){
                cur->next = l1;
                l1=l1->next;
                cur = cur->next;
            }
            else{
                cur->next = l2;
                l2=l2->next;
                cur = cur->next;
            }
        }
        while(l1){
            cur->next = l1;
            l1=l1->next;
            cur=cur->next;
        }
        while(l2){
            cur->next = l2;
            l2=l2->next;
            cur=cur->next;
        }        
        return dum->next;
    }
};