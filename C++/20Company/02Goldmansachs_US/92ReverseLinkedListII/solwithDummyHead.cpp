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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        /*
                          R
                        L
                    f       p
            head = dum [3,5,6], left = 1, right = 2
                        c

                            p  
                    6    3, 5, N
        */
        if(left==right) return head;
        ListNode * dum = new ListNode(0);
        dum->next = head;
        ListNode * L, * R;
        ListNode * cur = dum;
        for(int i=0;i<left-1;i++){
            cur = cur->next;
        }
        ListNode * first = cur;
        cur = cur->next;
        L = cur;
        for(int i=left;i<right;i++){
            cur = cur->next;
        }
        R = cur;
        ListNode * pre = NULL;
        if(R){
            pre = R->next;
            R->next = NULL;
        }
        cur = L;
        while(cur){
            ListNode * tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }
        first->next = pre;
        return dum->next;
    }
};