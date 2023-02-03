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
        //Step 1: Iterate lists and add the corresponding bit:
        ListNode * cur1 = l1;
        ListNode * cur2 = l2;
        //1: 7
        //2: 5  1
        //1: 12  
        // 2  2
        //Step1.1: combine each both exist bits:
        while(cur1){
            if(cur2){
                cur1->val = cur1->val+cur2->val;//8
                cur2=cur2->next;//1
            }
            cur1=cur1->next;
        }   
        //Step1.2: combine sigle bits:
        cur1 = l1;
        cur2 = l2;
        ListNode * dum = new ListNode();
        ListNode * cur3 = dum;
        while(cur1||cur2){
            if(cur1==NULL&&cur2!=NULL){
                cur3->next = cur2;
                cur2 = cur2->next;
            }
            else if(cur1!=NULL&&cur2==NULL){
                cur3->next = cur1;
                cur1 = cur1->next;
            }
            else{
                cur3->next = cur1;
                cur1 = cur1->next;
                cur2 = cur2->next;
            }
            cur3 = cur3->next;
        }
        /*
        cur3 = dum;
        // cout<<"Added:";
        while(cur3->next){
            cout<<cur3->next->val<<",";
            cur3 = cur3->next;
         }
        // cout<<endl;
        */
        //Step2: Carry
        //Added:  dum  7,10,7,
        //Carry:  dum  7,  
        cur3 = dum;
        // cout<<"Carry:";
        while(cur3->next){
            if(cur3->next->val>=10){
                int Val = cur3->next->val;
                cur3->next->val = Val%10;
                if(cur3->next->next){
                    cur3->next->next->val += Val/10;
                }
                else{
                    cur3->next->next = new ListNode(Val/10);
                }
            }
            // cout<<cur3->next->val<<",";
            cur3=cur3->next;
        }
        // cout<<endl;
        //[9]
        //[1,9,9,9,9,9,9,9,9,9]
        //10,9,9,9,9,9,9,9,9,9,
        //[0,0,0,0,0,0,0,0,0,0,1]
        // while(dum->next){
        //     cout<<dum->next->val<<endl;
        //     dum = dum->next;
        // }
        return dum->next;
    }
};