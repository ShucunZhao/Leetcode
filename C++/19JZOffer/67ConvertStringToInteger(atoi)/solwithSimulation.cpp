class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param s string字符串 
     * @return int整型
     */
    int convert(string num, bool nega){//"1204"
        int ans = 0;
        int bit = 10;
        int i = 0;
        int sign = nega?-1:1;
        while(i<num.size()&&num[i]=='0') i++;
        for(i;i<num.size();i++){
            if(ans>INT_MAX/10||(ans==INT_MAX/10&&((num[i]-'0')>INT_MAX%10))){
                ans = INT_MAX;
                break;
            }
            if(ans<INT_MIN/10||(ans==INT_MIN/10&&((num[i]-'0')>-(INT_MIN%10)))){
                ans = INT_MIN;
                break;
            }
            ans*=bit;//10,120,1200
            ans+=sign*(num[i]-'0');//1,12,120,4
        }
        return ans;
    }
    int StrToInt(string s) {
        // write code here
        int i = 0;
        int size = s.size();
        bool nega = false;
        while(i<size&&s[i]==' '){//Step1: skip the pre-space
            i++;
        }
        if(i<size&&s[i]=='-'){//Step2: deal with symbol
            nega = true;
            i++;
        }
        else if(i<size&&s[i]=='+'){
            i++;
        }
        //Step3: trim the number.
        string num;
        while(i<size&&s[i]==' '){//Step1: skip the pre-space
            i++;
        }
        while(i<size&&(s[i]>='0'&&s[i]<='9')){//"01234"
            num+=s[i];
            i++;
        }
        if(num.empty()){
            return 0;
        }
        //cout<<stoi(s)<<endl;
        return convert(num, nega);
    }
};