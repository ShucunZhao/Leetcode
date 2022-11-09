class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        string num = to_string(n);
        int flag=0,index;
        for(int i = num.size()-2; i>=0; i--){
            if(num[i]>num[i+1]||(num[i]=='0'&&num[i+1]=='0')){
                num[i]--;
                flag=1;
                index = i+1;
            }
        }
        if(flag){//KeyPoint: If you find a unsatisfied situation, you need to let all elements behind it to be '9'.
            for(int i = index;i<num.size();i++){
                num[i] = '9';
            }
        }
        return stoi(num);
    }
};