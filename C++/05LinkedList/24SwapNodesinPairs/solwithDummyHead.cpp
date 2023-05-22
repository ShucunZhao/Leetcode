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
    ListNode* swapPairs(ListNode* head) {
        /*
                      c        
               dum [2,1,3,4]
               tmp1 = c->next->next->next;( 3,4)
               tmp2 = c->next 
               c->next = c->next->next
               dum 2
               c->next->next = tmp2;
               tmp2->next = tmp1;

                c = c->next->next;

        */
        ListNode * dum = new ListNode(0);
        dum->next = head;
        ListNode * cur = dum;
        while(cur&&cur->next&&cur->next->next){
            ListNode * tmp = cur->next->next;
            cur->next->next = cur->next->next->next;
            tmp->next = cur->next;
            cur->next = tmp; 
            cur = cur->next->next;
        }
        return dum->next;
    }
};/**
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
    ListNode* swapPairs(ListNode* head) {
        /*
                      c        
               dum [2,1,3,4]
               tmp1 = c->next->next->next;( 3,4)
               tmp2 = c->next 
               c->next = c->next->next
               dum 2
               c->next->next = tmp2;
               tmp2->next = tmp1;

                c = c->next->next;

        */
        ListNode * dum = new ListNode(0);
        dum->next = head;
        ListNode * cur = dum;
        while(cur&&cur->next&&cur->next->next){
            ListNode * tmp = cur->next->next;
            cur->next->next = cur->next->next->next;
            tmp->next = cur->next;
            cur->next = tmp; 
            cur = cur->next->next;
        }
        return dum->next;
    }
};