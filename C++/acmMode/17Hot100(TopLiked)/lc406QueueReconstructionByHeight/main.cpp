#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

class Solution {
public:
    class myCmp {
    public:
        bool operator()(vector<int>& a, vector<int>& b) {
            if (a[0] == b[0]) return a[1] < b[1];
            return a[0] > b[0];
        }
    };
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        /*
            Input: people = [[7,0],[4,4],[7,1],[5,0],[6,1],[5,2]]
            Output: [[5,0],[7,0],[5,2],[6,1],[4,4],[7,1]]
            Sort the people with height and if the height is same make the smaller k in front:
            [[7,0],[7,1],[6,1],[5,0],[5,2],[4,4]]
            Then according to the height order to insert the element to correspoinding position
        */
        sort(people.begin(), people.end(), myCmp());
        vector<vector<int> > ans;
        ans.push_back(people[0]);
        for (int i = 1; i < people.size();++i) {
            ans.insert(ans.begin()+people[i][1], people[i]);
        }
        return ans;
    }
};

int main(int argc, char* argv[]) {
    while (true) {
        Solution S1;
        cout << "Enter the people:" << endl;
        string In;
        getline(cin, In);
        if (In == "q") break;
        In = In.substr(2, In.size() - 4);
        vector<vector<int> > people;
        if (!In.empty()) {
            size_t pos;
            while ((pos=In.find("],[")) != string::npos) {
                string token1 = In.substr(0, pos);
                In = In.substr(pos + 3);
                stringstream ss(token1);
                string token2;
                vector<int> tmp;
                while (getline(ss, token2, ',')) {
                    size_t l = token2.find_first_not_of(" ");
                    size_t r = token2.find_last_not_of(" ");
                    tmp.push_back(stoi(token2.substr(l, r - l + 1)));
                }
                people.push_back(tmp);
            }
            stringstream ss(In);
            string token2;
            vector<int> tmp;
            while (getline(ss, token2, ',')) {
                size_t l = token2.find_first_not_of(" ");
                size_t r = token2.find_last_not_of(" ");
                tmp.push_back(stoi(token2.substr(l, r - l + 1)));
            }
            people.push_back(tmp);
        }
        vector<vector<int> > res = S1.reconstructQueue(people);
        cout << "Res: [";
        for (vector<int>& x : res) {
            cout << "[";
            for (int& i : x) cout << i << ",";
            cout << "],";
        }
        cout << "]" << endl;
    }
}