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
    pair<ListNode*, ListNode*> reverseNode(ListNode * pre, ListNode * cur){
        /*        p c
            N 1,2,3
        */
        ListNode * tail = cur;
        while(cur){
            ListNode * tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }
        // return pre;//new head
        return make_pair(pre, tail);
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        /*         
                    h
                      t
            head = [1,2,3,4,5], k = 2
        */
        int cnt = k-1;//1
        ListNode * h = head;
        ListNode * t = head;
        while(t!=NULL&&(cnt!=0)){
            t = t->next;
            cnt--;
        }
        // cout<<"t:"<<t->val<<endl;
        if(t==NULL){
            return h;
        }
        ListNode * nextH = t->next;
        t->next = NULL;
        // cout<<"h:"<<h->val<<endl;
        pair<ListNode*, ListNode*> P = reverseNode(NULL, h);
        h = P.first;
        P.second->next = reverseKGroup(nextH, k);
        return h;
        // return NULL;
    }
};










