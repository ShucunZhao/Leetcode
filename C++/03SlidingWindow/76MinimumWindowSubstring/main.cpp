class Solution {
public:
    string minWindow(string s, string t) {
        //Corner case: when given string is smaller than target
        if(s.size()<t.size()){
            return "";
        }
        //Step1: store the target into a map mt.
        unordered_map<char, int> ms, mt;
        for(int i=0;i<t.size();i++){
            mt[t[i]]++;
        }
        //Step2: Traverse the given string with sliding window.
        int count=0;//Key variable: count the valid elements of map ms that is being compared.
        int ans = INT32_MAX;//Initial the ans length with maximum.
        int subL = 0;//Store sublength when the condition met. 
        int ansIndex=0;//Store left index(of slidingWindow) when the condition met.
        int l=0;//left pointer of SW.
        for(int r=0;r<s.size();r++){//r is right pointer of SW.
            if(ms[s[r]]<mt[s[r]]){//Key point: When ms map has no or smaller amount of element then adding couner.
                count++;
                }
            ms[s[r]]++;//Insert each travese element then we will do the erase of it when the counter meet condition.
            while(count>=t.size()){//When counter reach the length of target string, we do the ans step:
                subL = r-l+1;
                if(subL<ans){//we update the ans and index when the subL is smaller than previous one.
                    ans=subL;
                    ansIndex=l;
                }
                if(ms[s[l]]==mt[s[l]]){//Key point: We eliminate the valid elements counter only when the 
                                        //element amount is equal to target. 
                    count--;
                }
                ms[s[l]]--;//Then eliminate the elements of ms map.
                if(ms[s[l]]==0){
                    ms.erase(s[l]);
                }
                l++;//Let the left pointer go ahead.
            }
        }
        return ans==INT32_MAX ? "" : s.substr(ansIndex, ans);
        /*
        if(ans==INT32_MAX){//If no ans updated, return ""
            return "";
        }
        else{
            return s.substr(ansIndex, ans);//Return ans.
        }
        */
    }
};