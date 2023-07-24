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
            s = "MCMXCIV"
        */ 
        if(s.size()<2) return getNum(s[0]);
        int ans = 0;//1,
        for(int i=0;i<s.size();i++){
            if(i==s.size()-1){
                ans+=getNum(s[i]);
                break;
            }
            if(getNum(s[i])<getNum(s[i+1])){
                ans-=getNum(s[i]);
            }
            else{
                ans+=getNum(s[i]);
            }
        }
        return ans;
    }
};