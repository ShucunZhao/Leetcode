class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        for(char x : s){
            if(!st.empty()&&x==st.top()){
                st.pop();
            }
            else{
                st.push(x);
            }
        }
        // cout<<st.size();
        string ans;
        int size = st.size();
        for(int i = 0;i<size;i++){
            ans.push_back(st.top());
            // cout<<st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};