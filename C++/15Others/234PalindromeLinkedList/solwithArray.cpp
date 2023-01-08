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
    bool isPalindrome(ListNode* head) {
        ListNode * cur = head;
        int length = 0;
        while(cur){
            cur=cur->next;
            length++;
        }
        vector<int> ans(length);
        cur = head;
        for(int i=0;i<length;i++){
            ans[i] = cur->val;
            cur = cur->next;
        }
        for(int i=0,j=length-1;i<=j;i++,j--){
            if(ans[i]!=ans[j]) return 0;
        }
        return 1;
    }
};