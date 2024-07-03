#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <queue>

using namespace std;

class Solution {
public:
	int findKthLargest(vector<int>& nums, int k) {
		/*
			big top heap
		*/
		priority_queue<int, vector<int>, less<int> > pq;
		for (int& i : nums) pq.push(i);
		k--;
		while (k--) pq.pop();
		return pq.top();
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
		cout << "Enter the k:" << endl;
		string K;
		getline(cin, K);
		if (K == "q") break;
		int k = stoi(K);
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
		cout << "Res: " << S1.findKthLargest(nums, k) << endl;
	}
}