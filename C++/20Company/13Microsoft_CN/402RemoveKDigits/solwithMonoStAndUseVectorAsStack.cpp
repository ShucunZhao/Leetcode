class Solution {
public:
    string removeKdigits(string num, int k) {
        /*
                    i
            num = "1432219", k = 3

            st:0,1,
        */
        vector<int> st;//Monotonic stack to store the index and use vector as stack.
        int i = 0;
        while(k&&i<num.size()){
            while(k&&!st.empty()&&num[st.back()]>num[i]){
                k--;
                // cout<<"st.back():"<<st.back()<<endl;
                st.pop_back();
            }
            st.push_back(i);
            i++;
        }
        // cout<<"i:"<<i<<endl;
        while(i<num.size()){
            st.push_back(i);
            i++;
        }
        while(k--){
            // num.pop_back();
            st.pop_back();
        }
        string ans;
        for(int i : st){
            ans+=num[i];
        } 
        i = 0;
        while(i<ans.size()&&ans[i]=='0'){
            i++;
        }
        ans = ans.substr(i);
        // cout<<"ans:"<<ans<<endl;
        return ans==""?"0":ans;
    }
};
//1121 1 113
// 123 