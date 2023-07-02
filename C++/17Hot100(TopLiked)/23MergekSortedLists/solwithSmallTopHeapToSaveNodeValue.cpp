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
    class myCmp{
        public:
            // bool operator()(ListNode * a, ListNode * b){KeyPoint! You should not add the node here because there will be many nodes behind of it!
            bool operator()(int a, int b){//Should convert to all integer instead.
                return a > b;
            }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0||(lists.size()==1&&lists[0]==NULL)) return NULL;
        priority_queue<int, vector<int>, myCmp> pq;
        for(int i=0;i<lists.size();i++){
            ListNode * cur = lists[i];
            while(cur){
                pq.push(cur->val);
                cur = cur->next;
            }
        }
        ListNode * dum = new ListNode(0);
        // dum->next = pq.t
        ListNode * cur = dum;
        while(!pq.empty()){
            int curVal = pq.top();
            // ListNode * c = pq.top();
            pq.pop();
            cur->next = new ListNode(curVal);
            // cout<<cur->next->val<<",";
            cur = cur->next;
            // cout<<c->val<<",";
            // cout<<"dum:"<<dum<<",cur:"<<cur<<endl;
        }
        // cout<<"dum->next:"<<dum->next<<endl;
        // cout<<endl;
        // return NULL;
        return dum->next;
    }
};