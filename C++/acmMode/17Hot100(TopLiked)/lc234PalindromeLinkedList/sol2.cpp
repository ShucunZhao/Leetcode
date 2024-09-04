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
    bool isPalindrome(ListNode* head) {
        /*
                  s
           dum [1,2,2,1]
                      f
                   s         
            dum [1,2,1]
                       f
        */
        ListNode* dum = new ListNode();
        dum->next = head;
        ListNode* f = dum, * s = dum;
        while (s && f && f->next) {
            s = s->next;
            f = f->next->next;
        }
        bool isOdd = (f == nullptr);
        ListNode* l2 = s->next;
        s->next = nullptr;
        ListNode* l1 = reverse(dum->next);
        if (isOdd) l1 = l1->next;
        while (l1 && l2) {
            if (l1->val != l2->val) return false;
            l1 = l1->next;
            l2 = l2->next;
        }
        return true;
    }
    ListNode* reverse(ListNode* head) {
        /*
                   p c
           N 1,2,2,1
                     t
        */
        if (!head) return nullptr;
        ListNode* pre = nullptr;
        ListNode* cur = head;
        while (cur) {
            ListNode* tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }
        return pre;
    }
};