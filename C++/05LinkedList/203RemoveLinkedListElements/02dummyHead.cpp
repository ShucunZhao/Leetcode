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
/*
 * This is the dummy head method.
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode * dum = new ListNode();
        dum->next = head;
        ListNode * cur = dum;
        while(cur->next!=NULL){
            if(cur->next->val==val){
                ListNode * temp = cur->next;
                cur->next = cur->next->next;
                delete temp;
            }
            else{
                cur = cur->next;
            }
        }
        head = dum->next;
        delete dum;
        return head;
    }
};