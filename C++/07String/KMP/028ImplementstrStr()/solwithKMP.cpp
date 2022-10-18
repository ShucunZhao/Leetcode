/*
 * Same as 028 Find the Index of the First Occurrence in a String:
 * Use KMP algorithm.
 */
class Solution {
public:
    int strStr(string haystack, string needle) {
        int needSize = needle.size();
        vector<int> next(needSize, 0);
        next[0] = 0;
        int j;
        for(size_t i=1;i<needSize;i++){
            j = next[i-1];
            while(j>0 &&needle[j]!=needle[i]){
                j = next[j-1];
            }
            if(needle[i]==needle[j]){
                next[i] = j+1;
            }
            else{
                next[i] = 0;
            }
        }
        for(int l=0,r=0;l<haystack.size();l++){
            while(r>0&&haystack[l]!=needle[r]){
                r = next[r-1];
            }
            if(haystack[l]==needle[r]){
                r++;
            }
            if(r==needle.size()){
                return l-r+1;
            }
        }
        return -1;
    }
};