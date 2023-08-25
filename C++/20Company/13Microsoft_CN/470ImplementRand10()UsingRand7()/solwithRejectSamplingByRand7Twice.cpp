// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        /*
            rand7: [1,7]
            rand7-1: [0,6]
            (rand7-1)*7: [0, 42]
            (rand7-1)*7+rand7: [1, 49]
        so:
            1  2  3  4  5  6  7  8  9 10
           11 12 13 14 15 16 17 18 19 20 
           21 22 23 24 25 26 27 28 29 30 
           31 32 33 34 35 36 37 38 39 40
           41 42 43 44 45 46 47 48 49
        */
        int num = (rand7()-1)*7+rand7();
        while(true){
            if(num<=40){
                return num%10+1;
            }
            num = (rand7()-1)*7+rand7();
        }
        return -1;
    }
};