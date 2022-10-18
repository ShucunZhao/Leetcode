/*
 * KMP explanation:
 * https://blog.csdn.net/yearn520/article/details/6729426
 */
class Solution {
public:
    string longestPrefix(string s) {
        vector<int> next(s.size(), 0);
        next[0]=0;//Step1: Inital the first value of next array.
        int j;//This j is use for backtracking which represent the elements before current position i.
        //Step2: KMP to get the longest repeated prefix and suffix:(next array)
        for(int i=1;i<s.size();i++){//Traverse the current location with index i.
            j = next[i-1];//j is the previous next value of i.
            while(j>0&&s[j]!=s[i]){//Step3: If found confict: backtracking the previous next location.
                j = next[j-1];
            }
            if(s[i]==s[j]){//Step4: If matched: increse the next value by 1 in location 'i' with previous(j) value.
                next[i] = j+1;
            }
            else{
                next[i] = 0;//Step5: If backtracking all but not found match, let the next[i] be 0.
            }
        }
        // for(int x : next){
        //     cout<<x;
        // }
        return s.substr(0, next[s.size()-1]);
    }
};