
/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead) {
        /*
            tar: 1
                c  
               dum {}
        */
        ListNode * dum = new ListNode(0);
        dum->next = pHead;
        ListNode * cur = dum;
        while(cur&&cur->next&&cur->next->next){
            while(cur->next&&cur->next->next&&cur->next->val==cur->next->next->val){
                int tar = cur->next->val;//1
                while(cur->next&&cur->next->val==tar){
                    cur->next = cur->next->next;
                }
                // cur->next = cur->next->next->next;
            }
            cur = cur->next;
        }
        return dum->next;
    }
};