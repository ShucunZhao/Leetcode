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
        vector<char> A1, A2;
        ListNode * dum1 = new ListNode(0);
        ListNode * dum2 = new ListNode(0);
        dum1->next = l1;
        dum2->next = l2;
        while(dum1->next){
            A1.push_back(dum1->next->val);
            dum1 = dum1->next;
        }
        while(dum2->next){
            A2.push_back(dum2->next->val);
            dum2 = dum2->next;
        }       
        long long num1 = 0, num2 = 0;
        for(int i=A1.size()-1;i>=0;i--){
            num1=(long long)10*(long long)num1+A1[i];
        } 
        // cout<<"num1:"<<num1<<endl;
        for(int j=A2.size()-1;j>=0;j--){
            num2=(long long)10*num2+(long long)A2[j];
        } 
        // cout<<"num2:"<<num2<<endl;
        long long num3 = num1+num2;
        // cout<<"num3:"<<num3<<endl;
        ListNode * dum3 = new ListNode();
        ListNode * cur = dum3;
        while(num3/10){
            ListNode * N = new ListNode(num3%10);
            cur->next = N;
            cur=cur->next;
            // cout<<num3%10<<endl;
            num3/=10;
        }
        ListNode * N = new ListNode(num3%10);
        cur->next = N;
        // cout<<num3%10<<endl;
        return dum3->next;
    }
};