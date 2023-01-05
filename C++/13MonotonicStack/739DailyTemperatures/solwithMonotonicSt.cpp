class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ans(temperatures.size(), 0);
        stack<int> moSt;//Monotonic ascending stack (From entry to top);
        moSt.push(0);
        //i:     0, 1, 2, 3, 4, 5, 6, 7
        //T:    [73,74,75,71,69,72,76,73]
        //ans:   1, 1, 4, 2, 1, 1, 0, 0
        //moSt: [6
        //       top................entry         
        for(int i=1;i<temperatures.size();i++){
            if(temperatures[i]>temperatures[moSt.top()]){
                while(!moSt.empty()&&temperatures[i]>temperatures[moSt.top()]){
                    ans[moSt.top()] = i-moSt.top();
                    moSt.pop();
                }
                moSt.push(i);
            }
            else{
                moSt.push(i);
            }
        }
        return ans;
    }
};