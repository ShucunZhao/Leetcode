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
                              f  
                        s  
            head = [1,2,2,2,2,1]
                        s    
                              f
            head = [1,2,3,3,2,1]
                          f
                          3,2,1] 
                    s
                  p
                    [1,2,3
        */
        if(!head->next) return true;
        ListNode * dum = new ListNode(0);
        dum->next = head;
        ListNode * slow = dum, * fast = dum;
        while(fast&&fast->next){
            slow = slow->next;
            fast = fast->next->next;
        } 
        bool even;
        if(fast) even = 1;
        else even = 0; 
        fast = slow->next; 
        slow->next = NULL;
        slow = head;
        ListNode * pre = NULL;
        while(slow){
            ListNode * tmp = slow->next;
            slow->next = pre;
            pre = slow;
            slow = tmp;
        }
        /*
        cout<<"pre:"<<pre->val<<endl;
        cout<<"fast:"<<fast->val<<endl;
        */
        if(!even) pre = pre->next;
        while(pre&&fast){
            if(pre->val!=fast->val) return false;
            pre = pre->next;
            fast = fast->next;
        }
        return !pre&&!fast;
    }
};