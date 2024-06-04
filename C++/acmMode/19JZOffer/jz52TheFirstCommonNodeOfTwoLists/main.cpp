#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;
    ListNode() :val(0),next(nullptr) {}
    ListNode(int inV) :val(inV), next(nullptr) {}
    ListNode(int inV, ListNode* inN) :val(inV), next(inN) {}
};

class Solution {
public:
    ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2) {
        int len1 = 0, len2 = 0;
        ListNode* cur = pHead1;
        while (cur) {
            len1++;
            cur = cur->next;
        }
        cur = pHead2;
        while (cur) {
            len2++;
            cur = cur->next;
        }
        bool oneLonger = (len1 > len2) ? true : false;
        ListNode* c1 = pHead1, * c2 = pHead2;
        int diff = abs(len1 - len2);
        while (oneLonger&&(diff--)) {
            c1 = c1->next;
        }
        while(!oneLonger&&(diff--)) {
            c2 = c2->next;
        }
        while (c1 && c2 && c1->val != c2->val) {
            c1 = c1->next;
            c2 = c2->next;
        }
        return c1;
    }
};

ListNode* construct(string & In) {
    stringstream ss(In);
    string token;
    ListNode* root = nullptr;
    ListNode* dum = new ListNode();
    dum->next = root;
    ListNode* cur = dum;
    while (getline(ss, token, ',')) {
        size_t l = token.find_first_not_of(" ");
        size_t r = token.find_last_not_of(" ");
        cur->next = new ListNode(stoi(token.substr(l, r - l + 1)));
        cur = cur->next;
    }
    return dum->next;;
}

int main(int argc, char* argv[]) {
    while (true) {
        Solution S1;
        cout << "Enter the list1: " << endl;
        string L1;
        getline(cin, L1);
        if (L1 == "q") break;
        L1 = L1.substr(1, L1.size() - 2);
        cout << "Enter the list2: " << endl;
        string L2;
        getline(cin, L2);
        if (L2 == "q") break;
        L2 = L2.substr(1, L2.size() - 2);
        ListNode* l1 = construct(L1);
        ListNode* l2 = construct(L2);
        ListNode* res = S1.FindFirstCommonNode(l1, l2);
        cout << "Res: ";
        if (res) cout << res->val;
        else cout << "null";
        cout << endl;
    }
}