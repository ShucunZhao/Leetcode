#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode() :val(0), next(nullptr) {}
	ListNode(int inV) :val(inV), next(nullptr) {}
	ListNode(int inV, ListNode* inN) :val(inV), next(inN) {}
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

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		/*            1
			l1 = [2,4,9]
			          2
			l2 = [5,6,4,9]
		*/
		int tmp = 0;
		ListNode* cur1 = new ListNode();
		ListNode* cur2 = new ListNode();
		cur1->next = l1;
		cur2->next = l2;
		while (cur1->next && cur2->next) {
			int sum = cur1->next->val + cur2->next->val + tmp;
			tmp = sum / 10;
			cur2->next->val = sum % 10;
			cur1 = cur1->next;
			cur2 = cur2->next;
		}
		if (cur1->next) {
			cur2->next = cur1->next;
		}
		while (cur2->next) {
			int sum = cur2->next->val + tmp;
			tmp = sum / 10;
			cur2->next->val = sum % 10;
			cur2 = cur2->next;
		}
		if (tmp != 0) {
			cur2->next = new ListNode(tmp);
		}
		return l2;
	}
};

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
		cout << "Enter list1: " << endl;
		getline(cin, L1);
		if (L1 == "q") break;
		string L2;
		cout << "Enter list2: " << endl;
		getline(cin, L2);
		if (L1 == "q") break;
		L1 = L1.substr(1, L1.size() - 2);
		L2 = L2.substr(1, L2.size() - 2);
		ListNode* l1 = nullptr;
		ListNode* l2 = nullptr;
		if (!L1.empty()) {
			stringstream ss(L1);
			string token;
			vector<int> nums;
			while (getline(ss, token, ',')) {
				size_t l = token.find_first_not_of(" ");
				size_t r = token.find_last_not_of(" ");
				nums.push_back(stoi(token.substr(l, r - l + 1)));
			}
			l1 = construct(nums);
		}
		if (!L2.empty()) {
			stringstream ss(L2);
			string token;
			vector<int> nums;
			while (getline(ss, token, ',')) {
				size_t l = token.find_first_not_of(" ");
				size_t r = token.find_last_not_of(" ");
				nums.push_back(stoi(token.substr(l, r - l + 1)));
			}
			l2 = construct(nums);
		}
		ListNode* res = S1.addTwoNumbers(l1, l2);
		cout << "Res: [";
		printList(res);
		cout << "]" << endl;
	}
}