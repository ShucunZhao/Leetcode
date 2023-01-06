class Solution {
public:
    int trap(vector<int>& height) {
        //i:         0,1,2,3,4,5,6,7,8,9,10,11   
        //height:   [0,1,0,2,1,0,1,3,2,1, 2, 1]
        //st:       [3 6 
        //           2 1
        //ans:      1*1+0+1*1+
        int ans = 0;
        stack<int> st;
        st.push(0);
        for(int i=1;i<height.size();i++){
            if(!st.empty()&&height[i]>height[st.top()]){
                while(!st.empty()&&height[i]>height[st.top()]){
                    int mid = st.top();
                    st.pop();
                    if(!st.empty()){
                        int h = min(height[i], height[st.top()])-height[mid];
                        int w = i-st.top()-1;
                        ans+=h*w;
                    }
                }
                st.push(i);
            }
            else if(!st.empty()&&height[i]==height[st.top()]){
                st.pop();
                st.push(i);
            }
            else if(!st.empty()&&height[i]<height[st.top()]){
                st.push(i);
            }
        }
        return ans;
    }
};