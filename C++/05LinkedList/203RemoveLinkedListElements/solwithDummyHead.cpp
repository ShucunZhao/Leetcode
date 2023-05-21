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
    ListNode* removeElements(ListNode* head, int val) {
        /*
              c      c
             dum  [7,7,7,7]
        */
        if(!head) return head;
        ListNode * dum = new ListNode(0);
        dum->next = head;
        ListNode * cur = dum;
        while(cur){
            while(cur->next&&cur->next->val==val){
                cur->next = cur->next->next;
            }
            cur = cur->next;
        }
        return dum->next;
    }
};