#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cctype>

using namespace std;

class Solution {
public:
    bool checkInt(string str) {
        if (str[0] != '+' && str[0] != '-' && !isdigit(str[0])) return false;
        if (str.size() < 2 && !isdigit(str[0])) return false;
        for (int i = 1; i < str.size();++i) {
            if (!isdigit(str[i])) return false;
        }
        return true;
    }
    bool checkNumber(string str) {
        for (char& c : str) {
            if (!isdigit(c)) return false;
        }
        return true;
    }
    bool checkDecimal(string str) {
        if (str[0] != '+' && str[0] != '-' && !isdigit(str[0])&&!str[0]=='.') return false;
        size_t pos = str.find(".");
        string first = str.substr(0, pos);
        string second = str.substr(pos + 1);
        if (first.empty()&&!second.empty()) {
            return checkNumber(second);
        }
        else if (!first.empty() && second.empty()) {
            return checkNumber(first);
        }
        else if (!first.empty() && !second.empty()) {
            if (first == "+" || first == "-") return checkNumber(second);
            return checkNumber(first)&& checkNumber(second);
        }
        return false;
    }
    bool isNumeric(string str) {
        if (str.empty()) return false;
        // write code here
        size_t l = str.find_first_not_of(" ");
        size_t r = str.find_last_not_of(" ");
        if (1 == string::npos || r == string::npos) {
            return false;
        }
        str = str.substr(l, r - l + 1);
        size_t pos;
        if ((pos = str.find("e")) != string::npos || (pos = str.find("E")) != string::npos) {
            string first = str.substr(0, pos);
            string second = str.substr(pos + 1);
            if (!checkInt(first) && !checkDecimal(first)) return false;
            if (!checkInt(second)) return false;
            return true;
        }
        else if((pos = str.find(".")) != string::npos){
            return checkDecimal(str);
        }
        return checkInt(str);
    }
};

int main(int argc, char* argv[]) {
    while (true) {
        Solution S1;
        cout << "Eneter string:" << endl;
        string In;
        getline(cin, In);
        if (In == "q") break;
        In = In.substr(1, In.size() - 2);
        cout << "Res: " << S1.isNumeric(In) << endl;
    }
}
