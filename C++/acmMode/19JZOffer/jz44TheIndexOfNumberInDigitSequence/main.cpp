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
                10111213  //6-2*2
        */
        if (n < 10) return n;
        int bit = 1;
        long long num_of_char = 9;
        n -= 9;
        bit++;//2
        num_of_char = num_of_char * 10 * bit;//180
        while (n > num_of_char) {
            n -= num_of_char;
            bit++;//2
            num_of_char = 9*pow(10, bit-1)*bit;//180
        }
        /*
        //n=3
        //Which number: whichNumber = n/bit = 1 (0 is the first one, 1 is the second one)
        //int number = 10^(bit-1) // 10
        //while(i--){ number++; }
        //Which index: n-(whichNumber+1)-1
           0   1   2   3   4   5   6   7   8   9                 3
           10  11  12  13  14  15  16  17  18  19  ... 99
        */
        int whichNumber = (n-1) / bit + pow(10, bit - 1);//11
        int index = (n-1)%bit;
        string N = to_string(whichNumber);
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