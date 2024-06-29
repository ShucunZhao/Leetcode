#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    //Insert one char from stringstream
    unordered_map<char, int> ms;
    deque<int> Q;
    void Insert(char ch) {
        /*
            google

            ms: g:2, o:2

            Q:   o  ->
            ans: ggg
        */
        ms[ch]++;
        if(ms[ch]==1) Q.push_back(ch);
    }
    //return the first appearence once char in current stringstream
    char FirstAppearingOnce() {
        while (!Q.empty() && ms[Q.front()] > 1) Q.pop_front();
        if (Q.empty()) return '#';
        return Q.front();
    }

};

int main(int argc, char* argv[]) {
    while (true) {
        Solution S1;
        cout << "Enter string:" << endl;
        string In;
        getline(cin, In);
        if (In == "q") break;
        string res;
        for (char& c : In) {
            S1.Insert(c);
            res.push_back(S1.FirstAppearingOnce());
        }
        cout << "Res: " << res << endl;
    }
}