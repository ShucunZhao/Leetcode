class Solution {
public:
    /*
        1 1 10 6 *
    */
    unordered_map<string, long long> ms;
    int mod = 1e9+7;
    long long dfs(string s) {
        if(s.empty()) return 1;//Successfully ans, so return 1.
        if(s[0]=='0') return 0;
        if(s.length()==1){
            if(s[0]=='*') return 9;
            return 1;
        } 
        if(ms.count(s)) return ms[s];
        long long cnt = 0;
        //There are different combination cases:
        if(s[0]=='*'&&s[1]=='*'){//Case1: the first char is *: [*][*]xxx
            cnt+=9*dfs(s.substr(1))%mod;
            cnt+=15*dfs(s.substr(2))%mod;
        }
        else if(s[0]=='*'){//Case2: the first one is * but second one not: [*][0-9]xxx
            if(s[1]=='0'){//Only two situations here: 10 or 20.
                cnt+=2*dfs(s.substr(2))%mod;
            }
            else{// * = 1-9 in first bit:
                cnt+=9*dfs(s.substr(1))%mod;
                if(s[1]>='7'){// first bit *=1, second bit = [7-9].
                    cnt+=dfs(s.substr(2))%mod;
                }
                else{// first bit *=1, second bit [1-6] or first bit *=2, second bit [1-6] or
                    cnt+=2*dfs(s.substr(2))%mod;
                }
            }
        }
        else if(s[1]=='*'){//[1-9]*xxx 
            if(s[0]=='1'){//11,12,13...,19
                cnt+=9*dfs(s.substr(2))%mod;
            }
            else if(s[0]=='2'){//21,22,23...,26
                cnt+=6*dfs(s.substr(2))%mod;
            }
            if(s[0]!='0'){
                cnt+=dfs(s.substr(1))%mod;
            }
        }
        else{// first and second bit without *, like question 91.
            cnt+=dfs(s.substr(1))%mod;
            string tmp = s.substr(0, 2);
            if(stoi(tmp)<=26){
                cnt+=dfs(s.substr(2))%mod;
            }
        } 
        ms[s] = cnt%mod;
        return ms[s]; 
    }
    int numDecodings(string s) {
        return dfs(s);
    }
};