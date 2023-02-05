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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode * c1 = list1;
        ListNode * c2 = list2;
        ListNode * dum3 = new ListNode();
        ListNode * c3 = dum3;
        /*
          list1 = [-9,3], 
                        c1 
          list2 = [5,7]
                   c2
          d3 -9 3
                c3
        */
        while(c1!=NULL&&c2!=NULL){
            if(c1->val<c2->val){
                c3->next = c1;
                c1 = c1->next;
            }
            else{
                c3->next = c2;
                c2 = c2->next;
            }
            c3 = c3->next;
        }
        while(c1){
            c3->next = c1;
            c1=c1->next;
            c3 = c3->next;
        }
        while(c2){
            // cout<<c2->val;
            c3->next = c2;
            c2=c2->next;
            c3 = c3->next;
        }        
        return dum3->next;
    }
};