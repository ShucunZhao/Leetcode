#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <stack>
using namespace std;

class MinStack {
public:
	/*
		[2,3
	*/
	pair<int, int> P;
	stack<pair<int, int> > st;
	MinStack() {

	}
	void push(int val) {
		if (st.empty()) {
			st.push(make_pair(val,val));
		}
		else {
			int curMin = getMin();
			if (val < curMin) st.push(make_pair(val, val));
			else st.push(make_pair(val, curMin));
		}
	}
	void pop() {
		st.pop();
	}
	int top() {
		return st.top().first;
	}
	int getMin() {
		if (st.empty()) return -1;
		return st.top().second;
	}
};

int main(int argc, char* argv[]) {
	// MinStack * mst = new MinStack();
	unique_ptr<MinStack> mst(new MinStack());
	while (true) {
		cout << "Enter the cmd: " << endl;
		string In;
		getline(cin, In);
		if (In == "q") break;
		stringstream ss(In);
		string token;
		vector<string> cmd;
		while (getline(ss, token, ',')) {
			size_t l = token.find_first_not_of(" ");
			size_t r = token.find_last_not_of(" ");
			cmd.push_back(token.substr(l, r - l + 1));
		}
		if (cmd[0] == "MinStack") {
			// mst = new MinStack();
			mst.reset(new MinStack());
		}
		else if (cmd[0] == "push") {
			int val = stoi(cmd[1]);
			(*mst).push(val);
		}
		else if (cmd[0] == "getMin") {
			cout << "Res: " << (*mst).getMin() << endl;
		}
		else if (cmd[0] == "pop") {
			(*mst).pop();
		}
		else if (cmd[0] == "top") {
			cout << "Res: " << (*mst).top() << endl;
		}
	}
}