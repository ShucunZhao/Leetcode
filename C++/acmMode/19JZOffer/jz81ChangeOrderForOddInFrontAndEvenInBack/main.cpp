#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> reOrderArrayTwo(vector<int>& array) {
		/*
		*      l
			[1,2,3,4]
		       r
		*/
		int l = 0, r = 0;
		while(l<array.size()&&r<array.size()){
			if (array[l] % 2 == 1) {
				l++;
				r++;
			}
			else {
				while (r < array.size()&& array[r] % 2 != 1) {
					r++;
				}
				if (r == array.size()) break;
				swap(array[l], array[r]);
				l++;
				r++;
			}
		}
		return array;
	}
};

int main(int argc, char* argv[]) {
	while (true) {
		Solution S1;
		cout << "Enter the array:" << endl;
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
		vector<int> res = S1.reOrderArrayTwo(nums);
		cout << "Res: [";
		for (int& i : res) cout << i << ",";
		cout << "]" << endl;
	}
}