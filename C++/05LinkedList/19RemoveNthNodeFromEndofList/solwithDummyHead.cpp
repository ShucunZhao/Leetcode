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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
            /*
                         s
                                    f
                head = dum [1,2,3,4,5], n = 5
            */
            ListNode * dum = new ListNode(0);
            dum->next = head;
            ListNode * fast = dum, * slow = dum;
            while(n--){
                fast = fast->next;
            }
            while(fast->next){
                slow = slow->next;
                fast = fast->next;
            }
            slow->next = slow->next->next;
            return dum->next;
    }
};