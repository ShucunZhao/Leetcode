#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

class cmp {
public:
	bool operator()(int a, int b) {
		string first = to_string(a) + to_string(b);
		string second = to_string(b) + to_string(a);
		return stoi(first) < stoi(second);
	}
};

class Solution {
public:
	string PrintMinNumber(vector<int>& numbers) {
		// write code here
		if (numbers.size() == 0) return "";
		sort(numbers.begin(), numbers.end(), cmp());
		string ans;
		for (int& i : numbers) {
			ans += to_string(i);
		}
		return ans;
	}
};

int main(int argc, char* argv[]) {
	while (true) {
		Solution S1;
		cout << "Enter the numbers:" << endl;
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
				token = token.substr(l, r - l + 1);
				nums.push_back(stoi(token));
			}
		}
		cout << "Res: " << S1.PrintMinNumber(nums) << endl;
	}
}