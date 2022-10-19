/*
 * Method1: Moving matching
 * Step1: Concatenate the original string to the back of original to get a new string 
 * Step2: Remove the head and tail element of the new string
 * Step3: If you can find the original string in new string: the original meets the pattern
 *        else doesn't meet instead.
 */
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string newStr = s+s;
        newStr.erase(newStr.begin());
        newStr.erase(newStr.end()-1);
        // cout<<newStr;
        if(newStr.find(s)==string::npos){
            return 0;
        }
        return 1;
    }
};