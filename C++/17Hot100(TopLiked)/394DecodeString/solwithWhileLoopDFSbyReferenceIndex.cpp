class Solution {
public:
    string dfs(int & n, string & s){
        // if(n==s.size()) return "";
        string ans = "";
        while(n<s.size()){        
            if(isdigit(s[n])){
                int num = 0;
                while(n<s.size()&&isdigit(s[n])){
                    num=10*num+(s[n]-'0');
                    n++;
                }
                // if(s[n]=='['){
                n++;
                string str = dfs(n,s);
                while(num--){
                    ans += str;
                }
                // return ans;
                // }
            }
            // else if(isalpha(s[n])){
            //     string str;
            //     while(n<s.size()&&isalpha(s[n])){
            //         str+=s[n];
            //         n++;
            //     }
            //     return str+dfs(n,s);
            // }
            else if(s[n]==']'){
                n++;
                return ans;
            }
            else{
                ans+=s[n];
                n++;
            }
        }
        return ans;
    }
    string decodeString(string s) {
        /*
                  i
             s = "3[a2[c]]"

             digit: 3
             
        */
        int index = 0;
        return dfs(index, s);
    }
};