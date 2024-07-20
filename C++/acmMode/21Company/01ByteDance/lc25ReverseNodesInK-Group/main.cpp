#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;
    ListNode() :val(0), next(nullptr) {}
    ListNode(int inV) :val(inV), next(nullptr) {}
    ListNode(int inV, ListNode* inN) :val(inV), next(inN) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        /* 
                          p
            Input: head = D [2,1,4,3,5,6], k = 2
                             e s n
                                 
                                
        */
        ListNode* dum = new ListNode(0);
        dum->next = head;
        ListNode* pre = dum;
        while (pre->next) {
            ListNode* start = pre->next;
            ListNode* end = start;
            int cnt = k - 1;
            while (end && cnt--) {
                end = end->next;
            }
            if (end == nullptr) {
                break;
            }
            ListNode* nextN = end->next;
            end->next = nullptr;
            reverse(start);
            start->next = nextN;
            pre->next = end;
            pre = start;
        }
        return dum->next;
    }

    ListNode * reverse(ListNode* head) {
        /*
                 p  c t  
            N [2,1] N
            tmp: 1
            1->2->N
        */
        ListNode* pre = nullptr;
        ListNode* cur = head;
        while (cur) {
            ListNode* tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }
        return pre;
    }
};

ListNode* construct(vector<int>& nums) {
    ListNode* head = new ListNode(nums[0]);
    ListNode* cur = head;
    for (int i = 1; i < nums.size(); ++i) {
        cur->next = new ListNode(nums[i]);
        cur = cur->next;
    }
    return head;
}

int main(int argc, char* argv[]) {
    Solution S;
    vector<int> nums = {1,2,3,4,5};
    int k = 3;
    ListNode* head = construct(nums);
    ListNode* res = S.reverseKGroup(head, k);
    cout << "Res: [";
    while (res) {
        cout << res->val << ",";
        res = res->next;
    }
    cout << "]" << endl;
}