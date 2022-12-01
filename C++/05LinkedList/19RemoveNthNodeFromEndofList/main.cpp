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
    ListNode * removeNthFromEnd(ListNode* head, int n) {
        ListNode * dum = new ListNode();
        dum->next = head;
        ListNode * f = dum;
        ListNode * s = dum;
        n++;//You need to let the fast pointer to move one step further:
            //Because we need find the previous node(before target node) of the target node
            //Then you can delete the target by change the next node by present node
        while(n--){//Let fast node move forward n steps.
            f = f->next;
        }
        while(f!=NULL){//Let the fast and slow pointer move together until the fast pointer get the end(NULL)
            f=f->next;
            s=s->next;
        }
        ListNode * temp = s->next;
        s->next = s->next->next;
        delete temp;
        return dum->next;
    }
};