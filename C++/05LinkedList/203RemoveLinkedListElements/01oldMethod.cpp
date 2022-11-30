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
 * This is the old method that divide the problem into element occur in head and
 * not in head two situations.
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        while(head!=NULL&&head->val==val){
            ListNode * temp = head;
            head = head->next;
            delete temp;
        }
        ListNode * cur = head;
        while(cur!=NULL&&cur->next!=NULL){
            if(cur->next->val==val){
                ListNode * temp = cur->next;
                cur->next = cur->next->next;
                delete temp;
            }
            else{
                cur = cur->next;
            }
        }
        return head;
    }
};