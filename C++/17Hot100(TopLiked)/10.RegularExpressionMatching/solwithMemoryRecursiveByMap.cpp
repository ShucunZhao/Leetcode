class Solution {
public:
    map<pair<string, string>, bool> ms;//Memory recursive.
    bool isMatch(string s, string p) {
        /*
            s = "aa", p = "a"
            s = "aa", p = "a*"
        */
        // If the pattern is empty, the string must also be empty for a match
        if(p.empty()) return s.empty();
        // If found same suffix we can return the result in map to reduce the time complexity.
        if(ms.count({s,p})!=0) return ms[{s,p}];
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
                ms[{s,p}] = 1;
                return 1;
            }           
            // Step2: If the pattern without the first two characters cannot match the entire string,
            // check if the first character in the string matches the first character in the pattern
            if(first){
                // Recursively call isMatch with the string without the first character and the original pattern
                ms[{s,p}] = isMatch(s.substr(1, s.size()-1), p);
                return ms[{s,p}];
            }
            // If the first character in the string does not match the first character in the pattern,
            // the pattern cannot match the string
            ms[{s,p}] = 0;
            return 0;   
        }
        //else:
        return first&&isMatch(s.substr(1, s.size()-1), p.substr(1, p.size()-1));
    }
};