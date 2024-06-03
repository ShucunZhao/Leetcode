#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

class Solution {
public:
	int maxCoins(vector<int>& nums) {
		/*
			1.dp[i][j]: the max coins we can get if burst the ballons from index i to index j
			2.Assume the k is the last balloon to burst in range [i,j]:
				curCoins = nums[left]*nums[k]*nums[right]
				dp[i][j] = max(dp[i][k-1],nums[left]*nums[k]*nums[right], dp[i][k+1]) where k is from i to j
				and the left is i-1(maybe = -1), right is j+1(maybe = nums.size())
			3.
		*/
		if (nums.size() == 0) return 0;
		vector<vector<int> > dp(nums.size(), vector<int>(nums.size()));
		for (int j = 0; j < nums.size(); ++j) {
			for (int i = j; i >= 0; --i) {//According to the inference formula we need to know the dp[i][k+1] first, so the i index should start from j
				for (int k = i; k <= j; ++k) {
					int left = (i - 1) < 0 ? 1 : nums[i - 1];
					int right = (j + 1) >= nums.size() ? 1 : nums[j + 1];
					int leftRes = (k == i) ? 0 : dp[i][k - 1];
					int rightRes = (k == j) ? 0 : dp[k+1][j];
					dp[i][j] = max(dp[i][j], left * nums[k] * right+leftRes+rightRes); //???
				}
			}
		}
		return dp[0][nums.size() - 1];
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
			while (getline(ss,token,',')) {
				size_t l = token.find_first_not_of(" ");
				size_t r = token.find_last_not_of(" ");
				nums.push_back(stoi(token.substr(l, r - l + 1)));
			}
		}
		cout << "Res: " << S1.maxCoins(nums) << endl;
	}
}