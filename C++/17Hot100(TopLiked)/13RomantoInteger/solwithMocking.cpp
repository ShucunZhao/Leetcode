class Solution {
public:
    int getNum(char c){
        switch(c){
            case 'I':
                return 1;
            case 'V':
                return 5;
            case 'X':
                return 10;
            case 'L':
                return 50;
            case 'C':
                return 100;
            case 'D':
                return 500;
            case 'M':
                return 1000;
            default:
                return -1;
        }
        return -1;
    }
    int romanToInt(string s) {
        /*
            I             1
            V             5
            X             10
            L             50
            C             100
            D             500
            M             1000
            s = "L   V   I   I   I"
                50  5   1    1   1  
            sum: 58    
            s = "M   C   M   X   C   I   V"
                1000 100 1000 10 100  1  5
                =199 
        */
        int sum = 0;
        for(int i=0;i<s.size()-1;i++){
            int cur = getNum(s[i]);
            int next = getNum(s[i+1]);
            if(next>cur){
                sum-=cur;
            }
            else{
                sum+=cur;
            }
        }
        sum+=getNum(s[s.size()-1]);
        return sum;
    }
};