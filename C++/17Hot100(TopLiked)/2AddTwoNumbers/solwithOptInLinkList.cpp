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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        /*
             l1 = [9,9,9,9,9,9,9],

             l2 = [9,9,9,9]

             l3:   8,9,9,9,0,0,0,1
        */
        ListNode * dum = new ListNode(0);
        ListNode * curN = dum;
        int curVal=0,rst=0,mod=0;
        while(l1!=nullptr&&l2!=nullptr){
            curVal = l1->val+l2->val + rst;//9+9+0,9+9+1,
            rst = curVal/10;//1,1,
            mod = curVal%10;//8,9
            curN->next = new ListNode(mod);
            curN = curN->next;
            l1=l1->next;
            l2=l2->next;
        }
        while(l1!=nullptr){
            curVal = l1->val+rst;
            rst = curVal/10;
            mod = curVal%10;
            curN->next = new ListNode(mod);
            curN = curN->next;
            l1=l1->next;
        }
        while(l2!=nullptr){
            curVal = l2->val+rst;
            rst = curVal/10;
            mod = curVal%10;
            curN->next = new ListNode(mod);
            curN = curN->next;
            l2=l2->next;
        }
        if(rst!=0){
            curN->next = new ListNode(rst);
        }
        return dum->next;
    }
};