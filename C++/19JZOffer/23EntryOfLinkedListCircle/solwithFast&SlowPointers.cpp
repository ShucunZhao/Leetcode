
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
    ListNode* EntryNodeOfLoop(ListNode* pHead) {
        /*
             1->2->3---------
                   |<-5<-4<-|         
        */
        if(!pHead) return NULL;
        ListNode * fast = pHead, * slow = pHead;
        while(fast!=NULL&&fast->next!=NULL){
            fast = fast->next->next;
            slow = slow->next;
            if(fast==slow) break;
        }
        if(fast==NULL||fast->next==NULL) return NULL;
        ListNode * p1 = pHead, * p2 = fast;
        while(p1!=p2){
            p1=p1->next;
            p2=p2->next;
        }
        return p1;
    }
};