class Solution {
public:
    vector<double> getOptsRes(double a, double b){
        return {(a-b),(b-a),(a+b),(b*a),(a/b),(b/a)};
    }

    bool backtracking(vector<double> & nums){
        //nums: 4 1 2 3
        if(nums.size()==1){
            // cout<<nums[0]<<",";
            // cout<<abs(nums[0]-24)<<",";
            return abs(nums[0]-24)<=0.001;
        }
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                vector<double> tmp(nums.size()-1);//It will less than original one element.
                int index = 0;
                for(int k=0;k<nums.size();k++){//KeyPoint here, we need to traverse from 0 to end.
                    if(k!=i&&k!=j){//When met the used element just jump it.
                        tmp[index++] = nums[k];
                    }
                }
                vector<double> res = getOptsRes(nums[i], nums[j]);
                //Here is the backtracking step.
                for(double x : res){
                    tmp[tmp.size()-1] = x;
                    if(backtracking(tmp)){
                        return true;
                    }
                }
            }
        }
        return false;
    }

    bool judgePoint24(vector<int>& cards) { 
        vector<double> nums(cards.size());
        for(int i=0;i<cards.size();i++){
            nums[i] = (double)cards[i];
        }
        return backtracking(nums);
    }
};

