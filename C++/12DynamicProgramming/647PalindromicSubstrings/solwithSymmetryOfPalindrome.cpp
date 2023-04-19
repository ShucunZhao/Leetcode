class Solution {
public:
    int ans = 0;
    int countSubstrings(string s) {
        /*
            Sol with symmetrical characteristic:
                for each substring there are only two case to be palindrome when in position i:
                    Case1: the substring length is odd:
                        The symmetrical center is i, so s[i-1]==s[i+1]
                    Case2: the substirng length is even:
                        The symmetrical center is the middle-left and middle-right.
                So we just need to traverse the index of original string to count the palindrome quantity.
        */
        for(int i=0;i<s.size();i++){
            countPalindrome(i, i, s);
            countPalindrome(i, i+1, s);
        }
        return ans;
    }
    void countPalindrome(int start, int end, string & s){
        while(start>=0&&end<=s.size()-1&&s[start]==s[end]){
            ans++;
            start--;
            end++;
        }
        return;
    } 
};