class Solution {
public:
    string removeKdigits(string num, int k) {
        /*
                     i
            num = "132219", k = 3

            st:0,1,
        */
        string ans;
        stack<int> st;//Monotonic stack to store the index.
        int i = 0;
        while(k&&i<num.size()){
            while(k&&!st.empty()&&num[st.top()]>num[i]){
                k--;
                i--;
                num.erase(st.top(), 1);
                st.pop();
            }
            st.push(i);
            i++;
        }
        while(k--){
            num.pop_back();
        }
        i = 0;
        while(i<num.size()&&num[i]=='0'){
            i++;
        }
        // if(i>0){
        //     return ;
        // }
        num = num.substr(i);
        return num==""?"0":num;
    }
};
//1121 1 113
// 123 