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
        if(!head||!head->next) return NULL;
        ListNode * fast = head, * slow = head;
        while(fast&&fast->next){
            fast = fast->next->next;
            slow = slow->next;
            if(fast==slow){
                break;
            }
        }
        if(!fast||!fast->next) return NULL;
        ListNode * p1 = head, * p2 = fast;
        while(p1&&p2){
            if(p1==p2) return p1;
            p1 = p1->next;
            p2 = p2->next;
        }   
        return NULL;
    }
};