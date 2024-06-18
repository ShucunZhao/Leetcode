#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

class Solution {
public:
	bool IsContinuous(vector<int>& numbers) {
		/*
			In: [6,0,2,0,4]
			     0 0 2 4 6
			need: case1: 4-2-1 = 1
				  case2: 6-4-1 = 1
			zero: 2
			zero == need: true
		*/
		sort(numbers.begin(), numbers.end());
		int zeroCnt = 0;
		int needCnt = 0;
		if (numbers[0] == 0) zeroCnt++;
		for (int i = 1; i < numbers.size(); ++i) {
			if (numbers[i] == 0) {
				zeroCnt++;
				continue;
			}
			if (numbers[i - 1] == 0) continue;
			if (numbers[i] == numbers[i - 1]) return false;
			needCnt += (numbers[i] - numbers[i - 1] - 1);
		}
		return zeroCnt >= needCnt;
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
		vector<int> numbers;
		if (!In.empty()) {
			stringstream ss(In);
			string token;
			while (getline(ss, token, ',')) {
				size_t l = token.find_first_not_of(" ");
				size_t r = token.find_last_not_of(" ");
				numbers.push_back(stoi(token.substr(l, r - l + 1)));
			}
		}
		cout << "Res: " << S1.IsContinuous(numbers) << endl;
	}
}