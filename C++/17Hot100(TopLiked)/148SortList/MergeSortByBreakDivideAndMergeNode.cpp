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
    ListNode* sortList(ListNode* head) {
        /*
                      s
                           f   
            head = [4,2, 1,3]
           left:
            4,2                 right:
                                    1,3 
        */
        if(!head||!head->next) return head;//Recursion end.
        ListNode * slow = head;
        ListNode * fast = head->next;
        while(fast&&fast->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        /*
        cout<<"slow: "<<slow->val<<", fast: "<<fast->val<<endl;
        slow: 2, fast: 3
        slow: 4, fast: 2
        slow: 1, fast: 3
        */
        ListNode * rHead = slow->next;
        slow->next = NULL;
        ListNode * lHead = head;
        // cout<<"lHead: "<<lHead->val<<", rHead: "<<rHead->val<<endl;
        ListNode * left = sortList(lHead);
        ListNode * right = sortList(rHead);
        // cout<<"left: "<<left<<", right: "<<right<<endl;
        ListNode * dum = new ListNode(0);
        ListNode * cur = dum;
        while(left!=NULL||right!=NULL){
            if(left==NULL){
                cur->next = right;
                cur = cur->next;
                right = right->next;
            }
            else if(right==NULL){
                cur->next = left;
                cur = cur->next;
                left = left->next;
            }
            else if(left->val<right->val){
                cur->next = left;
                cur = cur->next;
                left = left->next;
            }
            else{
                cur->next = right;
                cur = cur->next;
                right = right->next;
            }
        }
        // cout<<"dum->next: "<<dum->next<<endl;
        return dum->next;
    }
};