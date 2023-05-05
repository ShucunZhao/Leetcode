class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n) {
        /*
            Formula:
                cur = (n/base)%10

            n:     5012223
                  high-c-low            
            Case1: the cur is larger than 1 and base is in 100 bit, low = n%base, high = n/base/10;
            cur: 2(>1 which can be treated as 1)
            low: from 0 to 99 which is 100 in total(is equal to base)  
            high: from 0 to 5012 which is high(n/base/10)+1 in total 
            so the total case is  base*(high+1) = base*(n/base/10 + 1).
            -------------------------------------------------------------
            n:     5012223
                high-c-low 
            Case2: the cur is equal to 1 and base is in 1000 bit, low = n%base, high = n/base/10;
            cur: 1, we got two subcases here:
            subcase1:
            when high is from 0 to 49, the low can be from 0 to 999 which is base in total, so the
            sum is high*base 
            subcase2:
            when high is the 50, the low is only can be from 0 to low which is low+1 in total, 
            so the sum is low+1
            In summary: total case is high*base + low+1
             -------------------------------------------------------------
            n:     5012223
               high-c-low 
            Case3: the cur is equal to 0 and base is in 10000 bit, low = n%base, high = n/base/10;
            cur: 0, if we treated it as 1, the high only can be 0~4, which cannot be 5
            and the low can be from 0 to 9999 which is base in total, so:
            total case: high*base                       

        */
        long base = 1;
        int sum = 0;
        while(base<=n){
            int cur = (n/base)%10;
            int high = (n/base)/10;
            int low = n%base;
            if(cur>1){
                sum+=base*(high+1);
            }
            else if(cur==1){
                sum+=(high*base+low+1);
            }
            else{
                sum+=high*base;
            }
            base*=10;
        }
        return sum;
    }
};