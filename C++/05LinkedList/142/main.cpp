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
        ListNode * f = head;
        ListNode * s = head;
        //bool find = 0;
        while(f!=NULL&&f->next!=NULL){
            s = s->next;
            f = f->next->next;
            if(s==f){
                // find = 1;
                // break;
                //ListNode * h =head;
                s = head;
                while(s!=f){
                    s=s->next;
                    f=f->next;
                }
                return s;
            }
        }
        return NULL;
        // if(!find){
        //     return NULL;
        // }
        // ListNode * h = head;
        // while(h!=s){
        //     h = h->next;
        //     s = s->next;
        // }
        // return h;
    }
};