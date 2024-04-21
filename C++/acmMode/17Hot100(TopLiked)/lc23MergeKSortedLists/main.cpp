#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <queue>

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
    struct myCmp {
    public:
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        /*
            Sol: use a minHeap to store all list head node,
            and pop the top node to construct ans list.
            Then add the next node of the top node to minHeap
            and do the stuff again.
        */
        priority_queue<ListNode*, vector<ListNode*>, myCmp> minHeap;
        for (int i = 0; i < lists.size(); ++i) {
            if(lists[i]) minHeap.push(lists[i]);
        }
        ListNode* dum = new ListNode(0);
        ListNode* cur = dum;
        while (!minHeap.empty()) {
            ListNode * tmp = minHeap.top();
            cur->next = tmp;
            cur = cur->next;
            minHeap.pop();
            if (tmp&&tmp->next) minHeap.push(tmp->next);
        }
        return dum->next;
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
        cout << root->val << ",";
        root = root->next;
    }
}

int main(int argc, char* argv[]) {
    while (true) {
        Solution S1;
        string In;
        cout << "Enter lists:" << endl;
        getline(cin, In);
        if (In == "q") break;
        In = In.substr(1, In.size() - 2);
        vector<ListNode*> lists;
        if (!In.empty()) {
            In = In.substr(1, In.size() - 2);
            size_t pos;
            while ((pos = In.find("],[")) != string::npos) {
                string tmp = In.substr(0, pos);
                In = In.substr(pos + 3);
                vector<int> list;
                stringstream ss(tmp);
                string token;
                while (getline(ss, token, ',')) {
                    size_t l = token.find_first_not_of(" ");
                    size_t r = token.find_last_not_of(" ");
                    list.push_back(stoi(token.substr(l, r - l + 1)));
                }
                ListNode* root = construct(list);
                if (root) lists.push_back(root);
            }
            vector<int> list;
            stringstream ss(In);
            string token;
            while (getline(ss, token, ',')) {
                size_t l = token.find_first_not_of(" ");
                size_t r = token.find_last_not_of(" ");
                list.push_back(stoi(token.substr(l, r - l + 1)));
            }
            ListNode* root = construct(list);
            if (root) lists.push_back(root);
        }
        ListNode* res = S1.mergeKLists(lists);
        cout << "Res: [";
        printList(res);
        cout << "]" << endl;
    }
}