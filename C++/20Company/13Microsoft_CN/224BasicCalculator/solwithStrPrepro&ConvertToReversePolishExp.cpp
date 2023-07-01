class Solution {
public:
    int calculate(string s) {
        /*
            S: 0-(2+3)
               -
               023+

            S: "1-11"

            S: "6+(-(2+3))"
            In this case we also need to add a 0 in front of the '-'

            "(6+7)-(2+3)"
            S:      2+(3*5/4+7*(2+3))/4
            st:    +(+
            RPE:   235*4/
            st: +/
            RPE:   235*4/723+*+4/+
                                 i
            cal_st:  2,9
        */
        //Step1: Preprocessing the original stirng:
        //Step1.1: Remove all space of string.
        for(int i=0;i<s.size();i++){
            if(s[i]==' '){
                s.erase(i,1);
                i--;
            }
        }
        /*Step1.2: Deal with the negative cases:
          Case1. It' a pure negative number which is start as '-', then convert it into 0 minus this
                numebr.(Which can insert a 0 at first to change valid RPE like "-1" to "0-1", then RPE is "01-").   
          Case2: The inside negative of expression like:
                 S: "6+(-(2+3))"
                 In this case we also need to add a 0 in front of the '-', so we abstract it as if there is not a digit or ')' infront of negative, 
                 we need to insert a 0 in front of it.
        */
        //Case1:
        if(s[0]=='-'){
            s.insert(0,1,'0');
        }
        //Case2:
        for(int i=1;i<s.size();i++){
            if(s[i]=='-'){
                if(!isdigit(s[i-1])&&s[i-1]!=')'){
                    s.insert(i,1,'0');
                    i++;
                }
            }
        }
        // cout<<"s:"<<s<<endl;
        //Step2: Get the reverse polish expression(RPE), it should be vector<string> format because there will be multiple bits of number inside of it:
        vector<string> RPE;
        stack<string> st;
        bool check = false;//Check if a string is all number without operator.
        for(int i=0;i<s.size();i++){
            string tmp;
            string str;
            while(s[i]>='0'&&s[i]<='9'){
                tmp+=s[i];
                i++;
            }
            if(!tmp.empty()){
                RPE.push_back(tmp);
            }
            if(s[i]=='('){
                // st.push(to_string(s[i]));
                str+=s[i];
            }
            else if(s[i]=='*'||s[i]=='/'){
                check = true;
                if(!st.empty()&&(st.top()=="*"||st.top()=="/")){
                    RPE.push_back(st.top());
                    st.pop();
                }
                str+=s[i];
            }
            else if(s[i]=='+'||s[i]=='-'){
                check = true;
                if(!st.empty()&&(st.top()=="+"||st.top()=="-")){
                    RPE.push_back(st.top());
                    st.pop();
                }
                str+=s[i];
            }            
            else if(s[i]==')'){
                while(!st.empty()&&st.top()!="("){
                    RPE.push_back(st.top());
                    st.pop();
                }
                if(!st.empty()) st.pop();
            }
            if(!str.empty()){
                st.push(str);
            }
        }
        while(!st.empty()){
            RPE.push_back(st.top());
            st.pop();
        }
        /*
        cout<<"RPE:"<<endl;
        for(string str : RPE){
            cout<<str<<",";
        }
        cout<<endl;
        */
        if(!check){
            string num;
            for(string str : RPE){
                num+=str;
            }
            return stoi(num);
        }
        //Step3: Use the reverse polish expression to calculate the answer.
        stack<int> calSt;//Use stack to store the calculation result.
        for(int i=0;i<RPE.size();i++){
            if(isdigit(RPE[i][0])){
                calSt.push(stoi(RPE[i]));
            }
            else{
                int opt1 = calSt.top();
                calSt.pop();
                int opt2 = calSt.top();
                calSt.pop();
                // cout<<"opt2: "<<opt2<<", opt1: "<<opt1<<endl;
                int rst = 0;
                if(RPE[i]=="+"){
                    rst = opt2+opt1;
                }
                else if(RPE[i]=="-"){
                    rst = opt2-opt1;
                }
                else if(RPE[i]=="*"){
                    rst = opt2*opt1;
                }
                else if(RPE[i]=="/"){
                    rst = opt2/opt1;
                }
                calSt.push(rst);
            }
        }
        
        /*
        cout<<"Ans: ";
        while(!calSt.empty()){
            cout<<calSt.top()<<",";
            calSt.pop();
        }
        cout<<endl;
        */
        // return -1;
        return calSt.top();
    }
};