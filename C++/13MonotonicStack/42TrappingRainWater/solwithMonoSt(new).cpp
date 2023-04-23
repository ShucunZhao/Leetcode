class Solution {
public:
    int trap(vector<int>& height) {
        /*
            step1: traverse each bottom whose height is height[i].
            step2: from this middle position to find the first left and right direction whose height
                   is taller than middle, and use width*min(height[left], height[right]) to calculate
                   area to represent to rain.
            We cannot ues two arrays to store the first larger height element from middle to left and right
            repectively by arrayL and arrayR here because it will exist the repeat case.
            So we just need to use one monotonic stack to do the whole process becase the first larger element
            is the first right larger element and the next element in stack was already the first left larger element.
        Simulation:
                              x  
            i:        0  1  2  3  4  5  6  7  8  9 10 11
            height = [0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1]
            stack: In:  |  ,0|base
            mid: 0
            left: -1
            height[i]: 
            H:
            W:
            ans:

        */
        int ans = 0;
        stack<int> st;
        for(int i=0;i<height.size();i++){
            while(!st.empty()&&height[i]>height[st.top()]){
                int mid = st.top();
                st.pop();
                int left;
                if(!st.empty()){
                    left = st.top();
                }
                else{
                    left = -1;
                }
                if(left!=-1){
                    int H = min(height[left], height[i])-height[mid];
                    int W = i-left-1;
                    ans+=H*W;
                }
            }
            st.push(i);
        }
        return ans;
    }
};