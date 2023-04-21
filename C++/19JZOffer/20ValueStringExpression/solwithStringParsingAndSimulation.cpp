class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param str string字符串 
     * @return bool布尔型
     */
    // bool isValidDecimal(string In){
    //     if(In.size()==0) return 0;
    //     int i =0;
    //     while(In[i]==' '){
    //         i++;
    //     }
    //     In = In.substr(i);
    //     if(In.size()>0){
    //         if(In[0]=='+'||In[0]=='-'){
    //             In = In.substr(1);
    //         }
    //     }
    //     size_t index = In.find_first_of('.');
    //     string first = In.substr(0, index);
    //     string second = In.substr(index+1);
    //     return isValidInteger(first)&&isValidInteger(second);
    // }
    bool isValidNumber(string In){//This case can include decimal and integer:
        if(In.size()==0) return 0;
        //Decimal case:
        size_t index = In.find_first_of('.');
        if(index!=string::npos){
            string first = In.substr(0, index);
            string second = In.substr(index+1);
            if(first.size()>0&&second.size()>0){
                return isValidInteger(first)&&isValidInteger(second);
            }
            else if(first.size()>0){
                return isValidInteger(first);
            }
            else{
                return isValidInteger(second);
            }
        }
        return isValidInteger(In);
    } 
    bool isValidInteger(string In){//This case is only include integer:
        if(In.size()==0) return 0;
        int i =0;
        while(In[i]==' '){
            i++;
        }
        // In = In.substr(i);
        // if(In.size()>0){
        //     if(In[0]=='+'||In[0]=='-'){
        //         In = In.substr(1);
        //     }
        // }
        bool space = 0;
        for(char c : In){
            if(c<'0'||c>'9'){
                if(c!=' '){
                    return 0;
                }
                else{
                    space = 1;
                }
            }
            else{
                if(space){
                    return 0;
                }
            }
        }
        return 1;
    }
    bool isNumeric(string str) {
        if(str.size()==' ') return 0;
        // write code here
        //Step1: trim the space before first char
        int i =0;
        while(str[i]==' '){
            i++;
        }
        str = str.substr(i);
        //Step2: trim the symbol '+' or '-' if it's in first pos.
        if(str[0]=='+'||str[0]=='-'){
            str = str.substr(1);
        }
        //cout<<str<<endl;
        //Step3: scientific notation form:
        size_t index = string::npos;
        if(str.find_first_of('e')!=string::npos){
            index = str.find_first_of('e');
        }
        else{
            index = str.find_first_of('E');
        }
        //cout<<index<<endl;
        if(index!=string::npos){//Deal with the scientific number:
            string first = str.substr(0, index);
            string second = str.substr(index+1);
            if(second.size()>0){
                if(second[0]=='+'||second[0]=='-'){
                    second = second.substr(1);
                }
            }
            return isValidNumber(first)&&isValidInteger(second);
            //cout<<"first:"<<first<<endl;
            //cout<<"second:"<<second<<endl;
        }
        //Step4: decimal case:
        if(str.find_first_of('.')!=string::npos){
            return isValidNumber(str);
        }
        //Step5: the last case - Integer:
        return isValidInteger(str);
    }
};