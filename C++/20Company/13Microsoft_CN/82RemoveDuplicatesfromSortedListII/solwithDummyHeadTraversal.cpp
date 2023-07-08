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
    ListNode* deleteDuplicates(ListNode* head) {
        /*            
                        c    
                   p  s
            head= dum 1,1,N
                                     c
                      p                 s         
            head = dum [1,2,3,3,4,4,4,4,5]
                                  c
                          p s     
            head = dum [1,2,4,4,4,4,5]        
        */
        if(!head) return head;
        ListNode * dum = new ListNode(0);
        dum->next = head;
        ListNode * pre = dum, * s = head;
        while(s&&s->next){
            while(s->next&&(s->val!=s->next->val)){
                pre = pre->next;
                s = s->next;
            }
            if(s->next){
                ListNode * c = s;
                while(c->next&&c->val==c->next->val){
                    c = c->next;
                }
                // ListNode * tmp = c->next;
                s = c->next;
                pre->next = s;
            }
        }
        return dum->next;
    }
};