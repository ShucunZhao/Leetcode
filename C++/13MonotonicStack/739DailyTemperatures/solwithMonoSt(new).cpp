class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        /*
            Sol with monotonic stack:
            i:              0  1  2  3  4  5  6  7
            temperatures = [73,74,75,71,69,72,76,73]
            In:  |7,6|base.
            ans: 1  1  4  2  1  1  0  0
                 0  1  2  3  4  5  6  7 
        */
        vector<int> ans(temperatures.size(), 0);
        stack<int> st;
        for(int i=0;i<temperatures.size();i++){
            // if(!st.empty()&&temperatures[i]>temperatures[st.top()]){
            while(!st.empty()&&temperatures[i]>temperatures[st.top()]){
                ans[st.top()] = i-st.top();
                st.pop();
            }
            // }
            st.push(i);
        }
        return ans;
    }
};