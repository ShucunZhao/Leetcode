#include <iostream>
#include <vector>
#include <string>
#include <sstream>

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
        *                 s  
            Input: head =  [1,2,3,4,5], k = 2
                              e
            Output: [2,1,4,3,5]
            We need to record the dum, start, initialStart, end and intitialEnd
            When we reverse the range-list we need to set the end->next to be null first.
        */
        ListNode* dum = new ListNode();
        dum->next = head;
        ListNode* start = dum;
        ListNode* end = dum;
        while (true) {
            for (int i = 0; i < k&&end; ++i) {
                end = end->next;
            }
            if (!end) break;
            ListNode* endNext = end->next;
            end->next = nullptr;
            ListNode* startNext = start->next;
            start->next = reverse(start->next);
            startNext->next = endNext;
            start = startNext;
            end = startNext;
        }
        return dum->next;
    }

    ListNode* reverse(ListNode*head) {
        /*
                   p  c
            N [1,2,3] 
                 t
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
    if (nums.size() == 0) return nullptr;
    ListNode* root = new ListNode(nums[0]);
    ListNode* cur = root;
    for (int i = 1; i < nums.size(); ++i) {
        cur->next = new ListNode(nums[i]);
        cur = cur->next;
    }
    return root;
}

void printList(ListNode* root) {
    while (root) {
        cout << root->val << "";
        root = root->next;
    }
    return;
}

int main(int argc, char* argv[]) {
    while (true) {
        Solution S1;
        string H;
        cout << "Enter the head:" << endl;
        getline(cin, H);
        if (H == "q") break;
        string K;
        cout << "Enter the k:" << endl;
        getline(cin, K);
        if (K == "q") break;
        H = H.substr(1, H.size() - 2);
        ListNode* head = nullptr;
        if (!H.empty()) {
            stringstream ss(H);
            string token;
            vector<int> nums;
            while (getline(ss, token, ',')) {
                size_t l = token.find_first_not_of(" ");
                size_t r = token.find_last_not_of(" ");
                nums.push_back(stoi(token.substr(l, r - l + 1)));
            }
            head = construct(nums);
        }
        int k = stoi(K);
        ListNode* res = S1.reverseKGroup(head, k);
        cout << "Res: [";
        printList(res);
        cout << "]" << endl;
    }
}