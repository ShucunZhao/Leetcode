/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        /*
                  pre  cur
            org:  null 67->0->24->58->null
        */
        ListNode * pre = NULL;
        ListNode * cur = head;
        while(cur){
            ListNode * tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }
        vector<int> ans;
        while(pre){
            ans.push_back(pre->val);
            pre = pre->next;
        }
        return ans;
    }
};
