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
    ListNode(int inV, ListNode * inN) :val(inV), next(inN) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        /*
            Input: list1 = d1 [1,2,4], list2 = d2 [1,3,4]
            Output: [1,1,2,3,4,4]
        */
        if (!list1 && !list2) return nullptr;
        else if (!list1) return list2;
        else if (!list2) return list1;
        ListNode* d1 = new ListNode();
        ListNode* d2 = new ListNode();
        ListNode* ans = nullptr;
;       d1->next = list1;
        d2->next = list2;
        if (d1->next->val > d2->next->val) {
            ans = new ListNode(d2->next->val);
            d2 = d2->next;
        }
        else {
            ans = new ListNode(d1->next->val);
            d1 = d1->next;
        }
        ListNode* cur = ans;
        while (d1->next && d2->next) {
            if (d1->next->val > d2->next->val) {
                cur->next = new ListNode(d2->next->val);
                d2 = d2->next;
            }
            else {
                cur->next = new ListNode(d1->next->val);
                d1 = d1->next;
            }
            cur = cur->next;
        }
        if (d1->next) {
            cur->next = d1->next;
        }
        if (d2->next) {
            cur->next = d2->next;
        }
        return ans;
    }
};

ListNode* construct(vector<int>& nums) {
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
        cout << root->val << ",";
        root = root->next;
    }
}

int main(int argc, char* argv[]) {
    while (true) {
        Solution S1;
        string L1;
        cout << "Enter the list1:" << endl;
        getline(cin, L1);
        if (L1 == "q") break;
        string L2;
        cout << "Enter the list2:" << endl;
        getline(cin, L2);
        if (L2 == "q") break;
        L1 = L1.substr(1, L1.size() - 2);
        L2 = L2.substr(1, L2.size() - 2);
        ListNode * list1 = nullptr;
        ListNode* list2 = nullptr;
        if (!L1.empty()) {
            stringstream ss(L1);
            string token;
            vector<int> l1;
            while (getline(ss, token, ',')) {
                size_t l = token.find_first_not_of(" ");
                size_t r = token.find_last_not_of(" ");
                l1.push_back(stoi(token.substr(l, r - l + 1)));
            }
            list1 = construct(l1);
        }
        if (!L2.empty()) {
            stringstream ss(L2);
            string token;
            vector<int> l2;
            while (getline(ss, token, ',')) {
                size_t l = token.find_first_not_of(" ");
                size_t r = token.find_last_not_of(" ");
                l2.push_back(stoi(token.substr(l, r - l + 1)));
            }
            list2 = construct(l2);
        }
        ListNode* res = S1.mergeTwoLists(list1, list2);
        cout << "Res: [";
        printList(res);
        cout << "]" << endl;
    }
}