class Solution {
public:
    int countDigitOne(int n) {
        /*
            0   1   2   3   4   5   6   7   8   9  
           10  11  12  13  
                    54321
                N:  23456       bit: i
                    xx1xx 
            first xx: N/(pow(10,i))     last xx: N%(pow(10,i-1));
            case1: current position is larger than 1:
                    00 00
                    23 99    
                    which is 24*100 in total.
            case2: current position is 0:
                    00 00
                    22 99
            case3: current position is 1:
                case3.1:
                    00 00
                    22 99   which is 23*100 in total.
                case3.2:
                    00 00 
                    23 56 whici is 1*57 in total.
            So we need to traverse whole string from first one bit to the last
            by a index i and determine which cases the current i is and count
            towards to ans.
         */
        int ans = 0;
        string num = to_string(n);
        int size = num.size();
        /*
            13
        */
        for(int i=1;i<=size;i++){
            int cur = num[size-i]-'0';//3
            long long bit1 = pow(10, i);//10
            long long bit2 = pow(10, i-1);
            // cout<<"bit1:"<<bit1<<",bit2:"<<bit2<<endl;
            int head = n/bit1;//1
            int tail = n%bit2;//3
            // cout<<"head:"<<head<<",tail:"<<tail<<endl;
            if(cur>1){
                ans+=(head+1)*bit2;
                // cout<<"cur>1:"<<(head+1)*bit2<<endl;
            }
            else if(cur==1){
                ans+=head*bit2;
                ans+=(tail+1);
            }
            else if(cur==0){
                ans+=head*bit2;
            }
        }
        return ans;
    }
};