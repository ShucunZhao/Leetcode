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
    void reorderList(ListNode* head) {
        if(head==NULL||head->next==NULL) return;
        vector<ListNode*> lSet;
        ListNode * cur = head;
        while(cur){
            lSet.push_back(cur);
            cur=cur->next;
        }
        bool even = 1;
        cur = head;
        for(int i=1,j=lSet.size()-1;i<=j;){
            if(even){
                cur->next = lSet[j];
                j--;
                even = 0;
            }
            else{
                cur->next = lSet[i];
                i++;
                even = 1;
            }
            cur = cur->next;
        }
        cur->next = NULL;
    }
};