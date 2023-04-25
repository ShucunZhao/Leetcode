class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        /*
                      i
            In:  [2,1,0]
            Out: [1,2,0]
                      j
            st:  In: , base
        */
        stack<int> st;
        for(int i=0,j=0;i<pushV.size();i++){
            st.push(pushV[i]);
            while(!st.empty()&&st.top()==popV[j]){
                st.pop();
                j++;
            }
        }
        return st.empty();
    }
};