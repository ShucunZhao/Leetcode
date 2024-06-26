#include <iostream>
#include <vector>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

class Solution {
public:
    struct myCmp {
    public:
        bool operator()(vector<int> & a, vector<int> & b) {
            return a[0] < b[0];
        }
    };
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        /*
            [[1,3],[2,6],[8,10],[15,18]]
            1.sort by first element
            2.Mock

            [[2,3],[4,5],[6,7],[8,9],[1,10]]

            [1,10],[2,3],[4,5],[6,7],[8,9]
        */
        sort(intervals.begin(), intervals.end(), myCmp());
        vector<vector<int> > ans;
        int first = intervals[0][0];
        int second = intervals[0][1];
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] <= second) {
                second = max(second, intervals[i][1]);
            }
            else {
                ans.push_back({ first, second });
                first = intervals[i][0];
                second = intervals[i][1];
            }
        }
        ans.push_back({ first, second });
        return ans;
    }
};

int main(int argc, char* argv[]) {
    while (true) {
        Solution S1;
        cout << "Enter the interval:" << endl;
        string In;
        getline(cin, In);
        if (In == "q") break;
        In = In.substr(2, In.size() - 4);
        vector<vector<int> > interval;
        if (!In.empty()) {
            size_t pos1;
            while ((pos1 = In.find("],[")) != string::npos) {
                string token1 = In.substr(0, pos1);
                In = In.substr(pos1 + 3);
                stringstream ss(token1);
                string token2;
                vector<int> tmp;
                while (getline(ss, token2, ',')) {
                    size_t l = token2.find_first_not_of(" ");
                    size_t r = token2.find_last_not_of(" ");
                    tmp.push_back(stoi(token2.substr(l, r - l + 1)));
                }
                interval.push_back(tmp);
            }
            stringstream ss(In);
            string token2;
            vector<int> tmp;
            while (getline(ss, token2, ',')) {
                size_t l = token2.find_first_not_of(" ");
                size_t r = token2.find_last_not_of(" ");
                tmp.push_back(stoi(token2.substr(l, r - l + 1)));
            }
            interval.push_back(tmp);
        }
        vector<vector<int> > res = S1.merge(interval);
        cout << "Res: [";
        for (vector<int>& x : res) {
            cout << "[";
            for (int& i : x) {
                cout << i << ",";
            }
            cout << "],";
        }
        cout << "]" << endl;
    }
}