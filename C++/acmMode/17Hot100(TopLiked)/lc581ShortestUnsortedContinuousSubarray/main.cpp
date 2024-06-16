#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
	int findUnsortedSubarray(vector<int>& nums) {
		/*
			left: 1
			right: 5
						     l r 
			Input: nums = [2,6,4,8,10,9,15]
			Output: 5

			   r
			[1,3,2,2,2]
			   1
			ascSt: 0,2
					l: 1
			desSt: 1,
					r: 4
			       r
			[1,3,5,4,2]
			ascSt:
			l:2
			desSt:
			r:4
		*/
		if (nums.size() == 1) return 0;
		stack<int> ascSt;
		stack<int> decSt;
		int left = INT_MAX, right = INT_MIN;
		ascSt.push(0);
		for (int l = 1; l < nums.size(); ++l) {
			while (!ascSt.empty()&&nums[l] < nums[ascSt.top()]) {
				left = min(left, ascSt.top());
				ascSt.pop();
			}
			ascSt.push(l);
		}
		if (left == INT_MAX) return 0;
		decSt.push(nums.size() - 1);
		for (int r = nums.size() - 2; r >= 0; --r) {
			while (!decSt.empty() && nums[r] > nums[decSt.top()]) {
				right = max(right, decSt.top());
				decSt.pop();
			}
			decSt.push(r);
		}
		return right - left + 1;
	}
};

int main(int argc, char* argv[]) {
	while (true) {
		Solution S1;
		cout << "Enter the nums:" << endl;
		string In;
		getline(cin, In);
		if (In == "q") break;
		In = In.substr(1, In.size() - 2);
		vector<int> nums;
		if (!In.empty()) {
			stringstream ss(In);
			string token;
			while (getline(ss, token, ',')) {
				size_t l = token.find_first_not_of(" ");
				size_t r = token.find_last_not_of(" ");
				nums.push_back(stoi(token.substr(l, r - l + 1)));
			}
		}
		cout << "Res: " << S1.findUnsortedSubarray(nums) << endl;
	}
}