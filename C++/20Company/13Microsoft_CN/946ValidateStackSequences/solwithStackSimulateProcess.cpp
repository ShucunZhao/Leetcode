class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        /*
            pushed = [1,2,3,4,5], popped = [4,5,3,2,1]

        pushed = [2,1,0]   popped = [1,2,0]    

        st: 2 
        */
        stack<int> st;
        int popI = 0;
        for(int i=0;i<pushed.size();i++){
            st.push(pushed[i]);
            while(!st.empty()&&st.top()==popped[popI]){
                st.pop();
                popI++;
            }
        }
        while(!st.empty()){
            if(st.top()==popped[popI]){
                while(!st.empty()&&st.top()==popped[popI]){
                    st.pop();
                    popI++;
                }
            }
            else{
                return false;
            }
        }
        return true;
    }
};