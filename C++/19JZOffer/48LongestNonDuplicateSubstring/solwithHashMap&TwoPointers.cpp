class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param s string字符串 
     * @return int整型
     */
    int lengthOfLongestSubstring(string s) {
        // write code here
        /*
                    l
            str:   "pwwkew"
                    r
            ms: w,k,e
            cnt:3
            ans:3
        */
        unordered_map<char, int> ms;
        int cnt = 0, ans = 0, l = 0, r = 0;
        while(r<s.size()){
            while(ms.count(s[r])){
                ms[s[l]]--;
                if(ms[s[l]]==0){
                    ms.erase(s[l]);
                    cnt--;
                }
                l++;
            }
            cnt++;
            ms[s[r]]++;
            ans = max(ans, cnt);
            r++;
        }
        return ans;
    }
};