class Solution {
public:
    bool isMatch(string s, string p) {
        /*
            s = "aa", p = "a"
            s = "aa", p = "a*"
        */
        // If the pattern is empty, the string must also be empty for a match
        if(p.empty()) return s.empty();
        // Check if the first character in the string matches the first character in the pattern
        bool first = !s.empty()&&(s[0]==p[0]||p[0]=='.');

        // If the second character in the pattern is a '*', handle the special case
        if(p.size()>=2&&p[1]=='*'){
            /* //sol1:
            // Either skip the first two characters of p
            // or keep the first character of p and compare it with the next character of s
            return isMatch(s, p.substr(2, p.size()-2))||(first&&isMatch(s.substr(1, s.size()-1), p));
            */
            //sol2:(These three steps's order cannot be changed below!)
            // Step1: Check if the pattern without the first two characters can match the entire string
            if(isMatch(s, p.substr(2, p.size()-2))){
                return 1;
            }           
            // Step2: If the pattern without the first two characters cannot match the entire string,
            // check if the first character in the string matches the first character in the pattern
            if(first){
                // Recursively call isMatch with the string without the first character and the original pattern
                return isMatch(s.substr(1, s.size()-1), p);
            }
            // If the first character in the string does not match the first character in the pattern,
            // the pattern cannot match the string
            return 0;   
        }
        //else:
        return first&&isMatch(s.substr(1, s.size()-1), p.substr(1, p.size()-1));
    }
};