/*
 * Sol: Use stack to save the right paratheses that waiting to be matched.
 * If match: pop it in stack
 * If while the stack is empty but the original string has not yet finished traverse:
        retrun false because there has no other elements can be matched.
 * If finished iterating original string, check if matching stack is empty:
        if yes return true, else return false.
 */
class Solution {
public:
    bool isValid(string s) {
        if(s.size()%2!=0){
            return 0;
        }
        stack<char> match;
        for(char c : s){
            if(c=='('){
                match.push(')');
            }
            else if(c=='['){
                match.push(']');
            }
            else if(c=='{'){
                match.push('}');
            }
            else if(!match.empty()&&match.top()==c){//Must let judge empty first because if match is empty the stach.top will cause error.
                match.pop();
            } 
            else{
                return 0;
            }               
        }
        return match.empty();
    }
};