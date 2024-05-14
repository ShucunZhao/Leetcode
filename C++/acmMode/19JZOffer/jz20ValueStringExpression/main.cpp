#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cctype>

using namespace std;

class Solution {
public:
    bool checkInt(string str) {
        bool isNumber = false;
        for (int i = 0; i < str.size();++i) {
            if (isalpha(str[i])) return false;
            if (str[i] == '+' || i != 0) return false;
            if (str[i] == '+' || i != 0) return false;
            if (isdigit(str[i])) isNumber = true;
        }
        return isNumber;
    }
    bool isNumeric(string str) {
        if (str.empty()) return false;
        // write code here
        size_t l = str.find_first_not_of(" ");
        size_t r = str.find_last_not_of(" ");
        str = str.substr(l, r - l + 1);
        size_t pos;
        if ((pos = str.find("e")) != string::npos || (pos = str.find("E")) != string::npos) {
            string first = str.substr(0, pos);
            string second = str.substr(pos + 1);
            if ((pos = first.find(".")) != string::npos || (pos = second.find(".")) != string::npos) return false;
            return checkInt(first) && checkInt(second);
        }
        else if((pos = str.find(".")) != string::npos){
            if (str[0] == '.') return checkInt(str.substr(1));
            if (str[str.size() - 1] == ',') return checkInt(str.substr(0, pos));
            string first = str.substr(0, pos);
            string second = str.substr(pos + 1);
            return checkInt(first) && checkInt(second);
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
