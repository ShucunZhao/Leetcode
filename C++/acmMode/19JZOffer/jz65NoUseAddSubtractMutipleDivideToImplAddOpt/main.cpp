#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

class Solution {
public:
    int Add(int num1, int num2) {
        /*
            1
            01
            11
            01 
        */
        int sumIn, sumNotIn;
        while (num1) {
            sumNotIn = (num1 ^ num2);
            sumIn = (num1 & num2) << 1;
            num1 = sumIn;
            num2 = sumNotIn;
        }
        return num2;
    }
};

int main(int argc, char* argv[]) {
    while (true) {
        Solution S1;
        cout << "Enter the num1:" << endl;
        string N1;
        getline(cin, N1);
        if (N1 == "q") break;
        cout << "Enter the num2:" << endl;
        string N2;
        getline(cin, N2);
        if (N2 == "q") break;
        int num1 = stoi(N1);
        int num2 = stoi(N2);
        cout << "Res: " << S1.Add(num1, num2) << endl;
    }
}