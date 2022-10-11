/*
 * The key point is you need to pay attention to the size and length of the target map.
 * cnt: Counter to record the times of ms meeting condition.
 * len: Len of the fixed sliding window that saving elements by iterating.
 * size_t size - The number of element types in target set mt: Use for checking answer.
 * p.length() - The length of all elements in target string: Use for eliminate element on ms.
 */
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char, int> ms, mt;
        vector<int> ans;
        size_t cnt=0, len=0;
        //Step1: Store the target in mt.
        for(size_t i=0;i<p.length();i++){
            mt[p[i]]++;
        }
        size_t size = mt.size();//Get the types amount of mt
        //Step2: Use sliding window iterate all elements in string s.
        for(size_t l=0,r=0;r<s.length();r++){
            ms[s[r]]++;//Add each element in ms.
            len++;//Update the length of ms each time.
            if(ms[s[r]]==mt[s[r]]){//If the element value in ms equal to mt:
                                    //Increse cnt by 1 because s[r] met the condition in mt.
                    cnt++;
            }
            if(cnt==size){//While cnt met the types amount condition of mt, we found the ans.
                ans.push_back(l);
            }
            if(len==p.length()){//Key point: We should fix the length of the sliding window by the length of target string p.
                                //Therefore, we need to eliminate the 'l' pointer element in this step.
                if(ms[s[l]]==mt[s[l]]){//If the s[l] met the condition of mt we need to decrease the count cnt by one.
                    cnt--;
                }
                ms[s[l]]--;//Eliminate the 'l' element.
                /*
                 *Because it's not use ms.size() so we don't need to erase it.
                 *if(ms[s[l]]==0){
                 *  ms.erase(s[l]);
                 *}
                 */
                len--;
                l++;
            }
        }
        return ans;
    }
};
/*
 * Corner case is:
 * s = "aabaa", p = "aa"
 * If you don't use the number of type in mt to judge you will get wrong ans.
 */
