class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        /*
                                 i
                [1,2,3,2,2,2,5,4,2]
        ans: 2
        vote: 0
        */
        int ans = numbers[0];
        int vote = 1;
        for(int i=1;i<numbers.size();){
            if(ans==numbers[i]){
                vote++;
            }
            else{
                vote--;
            }
            if(vote==0){
                i++;
                ans = numbers[i];
            }
            else{
                i++;
            }
        }
        return ans;
    }
};