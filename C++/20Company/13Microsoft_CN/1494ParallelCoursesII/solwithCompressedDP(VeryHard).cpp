class Solution {
public:
    int countOne(int In){
        int cnt = 0;
        while(In){
            if(In&1){
                cnt++;
            }
            In>>=1;
        }
        return cnt;
    }
    int minNumberOfSemesters(int n, vector<vector<int>>& relations, int k) {
        /*
            The input size n is 0~15 which notice us use the dp compression: 
            sol with state compress DP, use bits to represent each course.
                dp[state]
                dp[000...001]: the minimum semester to finish No.0 course
                dp[000...011]: the minimum semester to finish No.0 and No.1 courses.

            inference formula:
                dp[state] = min(dp[state], dp[preState]+1),
                Requirements:
                    1.preState is a subset of state becasue the previous courses should keep
                      to current state. (subset)
                    2. Meet the k condition:
                        countOne(state)-count(preState) should be <=k.
                    3. Meet the prerequisite requirements:
                            the preState must contain the prerequisite courses of current state.
                            We represent all prerequisite into a array prereq;
                            So the subset should contains all prerequisites which means:
                                subset take intersection of prereq[state] shouble be prereq[state]
                                    which is & operation.
        */
        vector<int> dp((1<<n), INT_MAX-1);
        vector<int> preCourse(n, 0);//Represent prerequisite course of each course. 
        vector<int> prereq((1<<n), 0);
        for(int i=0;i<relations.size();i++){
            int pre = relations[i][0];
            int nextI = relations[i][1]-1;
            preCourse[nextI] += (1<<(pre-1));
        }
        for(int state = 0;state<(1<<n);state++){
            prereq[state] = 0;
            for(int i=0;i<n;i++){
                if((state>>i)&1){
                    prereq[state] |= preCourse[i];
                }
            }
        }        
        dp[0] = 0;//Initialization.
        for(int state=1;state<(1<<n);state++){
            // for(int subset=state;subset>=0;subset--){//Keypoint here.
            for(int subset=state;subset>=0;subset=(subset-1)&state){//Keypoint here to keep next subset is always  the subset of state!
                // if(countOne(state)-countOne(subset)<=k&&(subset&prereq[state])==prereq[state]){
                // if(__builtin_popcount(state)-__builtin_popcount(subset)<=k&&(subset&prereq[state]==prereq[state])){
                if (__builtin_popcount(state) - __builtin_popcount(subset) <= k && (prereq[state] & subset) == prereq[state])
                {    
    
                    dp[state] = min(dp[state], dp[subset]+1);
                }
                if(subset==0 ){
                    break;
                }
            }
        }
        // cout<<countOne(7)<<endl;
        // return -1;
        return dp[(1<<n)-1];
    }
};