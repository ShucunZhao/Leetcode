class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        /*
            string ans;
            numerator: 1,     denominator: 3
            1/3 = 0......1 --> ans+=to_string(rst)+"."+to_string(mod), ms[mod] = ans.size()-1;
                  rst   mod, mod*=10;
            10/3 = 3...1 if (ms.count(mod)) ans.insert(ms[mod], 1, '('); ans+=')' then retrun ans;

            
        */
        unordered_map<long long, int> ms;//<numerator, index>
        string ans;
        long long num = (long long)numerator;
        long long deno = (long long)denominator;
        if(num<0&&deno>0){
            ans+="-";
            num=-num;
        }
        else if(num>0&&deno<0){
            ans+="-";
            deno=-deno;    
        }
        else if(num<0&&deno<0){
            num=-num;
            deno=-deno;
        }
        long long rst = num/deno;//0
        long long mod = num%deno;//4
        // cout<<"rst:"<<rst<<", mod:"<<mod<<endl;
        ans+=to_string(rst);
        if(mod!=0) ans+=".";
        while(mod!=0){
           num=(mod*10);
           rst = num/deno;
           mod = num%deno;
           if(ms.count(num)){
               ans.insert(ms[num], 1, '(');
               ans+=")";
               return ans;
           }
        //    cout<<"rst:"<<rst<<", mod:"<<mod<<endl;
           ans+=to_string(rst);
           ms[num] = ans.size()-1;
        }
        return ans;
    }
}; 