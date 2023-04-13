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

         org:    dum->67->0->24->58->null
                 dum->0->24->58->67->null
        */
        ListNode * dum = new ListNode(0);
        dum->next = head;
        vector<int> ans;
        while(dum->next){
            ans.push_back(dum->next->val);
            dum=dum->next;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
