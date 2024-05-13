#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

class Solution {
public:
    double Power(double base, int exponent) {
        /*
            In:  2.00000,3
            Out: 8.00000
            -------------
            In:  2.00000,-2
            Out: 0.25000
        */
        if (exponent == 0) return 1;
        if (exponent == 1) return base;
        if (exponent < 0) {
            return 1 / (base * Power(base, -exponent - 1));
        }
        else {
            return base * Power(base, exponent - 1);
        }
        return -1;
    }
    double Power2(double base, int exponent) {
        /*
            Sol with quick exponet
            In:  2.00000, 3
            Out: 8.00000
            2^3 ---> 2^2*2^1---->2^1*2^1*2^1
        */
        if (exponent == 0) return 1;
        if (exponent == 1) return base;
        if (exponent < 0) return 1 / (Power2(base, -exponent));
        if (exponent % 2 == 0) {
            return Power2(base, exponent / 2) * Power2(base, exponent / 2);
        }
        return base * Power2(base, exponent - 1);
    }
};

int main(int argc, char* argv[]) {
    while (true) {
        Solution S1;
        cout << "Enter the base: " << endl;
        string B;
        getline(cin, B);
        if (B == "q") break;
        double base = stod(B);
        cout << "Enter the exponent: " << endl;
        string E;
        getline(cin, E);
        if (E == "q") break;
        int exponent = stoi(E);
        cout << "Res: " << S1.Power(base, exponent) << endl;
    }
}