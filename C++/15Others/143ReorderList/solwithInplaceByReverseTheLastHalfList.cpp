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
    ListNode * reverse(ListNode * head){
        ListNode * pre = NULL;
        ListNode * cur = head;
        while(cur){
            ListNode * tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur=tmp;
        }
        return pre;
    }
    void reorderList(ListNode* head) {
        /*
                              f 
                        s 
            head = [1,2,3,4,5]
                                              c1
            head1    = [1, 5   2,  4,  3,  x   
            tmp1 = c1->next;
            tmp2 = c2->next;
            c1->next = c2;
            c2->next = tmp1;
            c2 = tmp2;
            c1 = tmp1
                                   c2
            head2 =    [5,   4   x  
          
            after:     1,   5,   2,   4,   3
        */
        if(!head->next) return;
        ListNode * slow = head, * fast = head->next;
        while(fast&&fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        fast = slow->next;//[4,5
        slow->next = NULL;
        slow = head;//[1,2,3
        fast = reverse(fast);
        ListNode * c1 = slow, * c2 = fast;
        while(c1&&c2){
            ListNode * t1 = c1->next;
            ListNode * t2 = c2->next;
            c1->next = c2;
            c2->next = t1;
            c2 = t2;
            c1 = t1;
        }
    }
};