class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start=0,curSave=0,totalSave=0;
        for(int i=0;i<gas.size();i++){
            curSave += (gas[i]-cost[i]);
            totalSave += (gas[i]-cost[i]);
            if(curSave<0){
                start=i+1;
                curSave=0;
            }
        }
        return totalSave<0?-1:start;
    }
};