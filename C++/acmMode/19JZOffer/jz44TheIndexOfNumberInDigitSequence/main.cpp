#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

class Solution {
public:
    int findNthDigit(int n) {
        /*
             0123456789101112131415
                           range        number of digit         number of chars
              bit-1:       1-9          9                        9*1 = 9
              bit-10:      10-99        90                       90*2 = 180
              bit-100:     100-999      900                      900*3 = 2700
              bit-1000:    1000-9999    9000                     9000*4 = 36000
              bit-n                                              9*10^len(n-1)*len(n)

              if input N = 13:
                13-10 = 3
                  3/(len(n)) = 1
                  3%(len(n)) = 1
                1011                     
        */
        if (n < 10) return n;
        int bit = 1;
        int num_of_char = 9;
        int number;
        int index;
        while (n > num_of_char) {
            if (num_of_char == 9) {
                n -= 10;
                number = pow(10,bit)+n;
                index = n / bit;
                bit++;
                num_of_char = num_of_char * 10 * bit;//
                continue;
            }
            n -= num_of_char;
            number = pow(10, bit) + n;
            index = n / bit;
            bit++;
            num_of_char = num_of_char * 10 * bit;//
        }
        string N = to_string(number);
        return N[index] - '0';
    }
};

int main(int argc, char* argv[]) {
    while (true) {
        Solution S1;
        cout << "Enter n:" << endl;
        string In;
        getline(cin, In);
        if (In == "q") break;
        int n = stoi(In);
        cout << "Res: " << S1.findNthDigit(n) << endl;
    }
}