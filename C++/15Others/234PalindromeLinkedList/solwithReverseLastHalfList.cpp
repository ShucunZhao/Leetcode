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
    ListNode * reverse(ListNode * head){
        ListNode * cur = head;
        ListNode * pre = NULL;
        while(cur){
            ListNode * tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }
        return pre;
    }

    bool isPalindrome(ListNode* head) {
        ListNode * slow = head;
        ListNode * fast = head;
        ListNode * pre = head;
        while(fast&&fast->next){
            fast = fast->next->next;
            pre = slow;
            slow = slow->next;
        }
        pre->next = NULL;
        ListNode * cur1 = head;
        ListNode * cur2 = reverse(slow);
        while(cur1){
            if(cur1->val!=cur2->val) return 0;
            cur1 = cur1->next;
            cur2 = cur2->next;
        }
        return 1;
    }
};