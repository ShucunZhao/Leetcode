class Solution {
public:
    vector<string> withinTen = {"","One","Two","Three","Four","Five","Six","Seven","Eight","Nine"};
    vector<string> withinTwenty = {"Ten","Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen",
                        "Seventeen","Eighteen","Nineteen"};
    vector<string> withinHundred = {"","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety"};
    //The last "Hundred", "Thousand", "Million", "Billion" 
    string dfs(int n){
        string res;
        if(n<10){
            return withinTen[n];
        }
        else if(n<20){
            return withinTwenty[n-10];
        }
        else if(n<100){
            res+=(withinHundred[n/10]+" "+dfs(n%10));
            //63/10=6......3
        }
        else if(n<1000){//633:
            res+=dfs(n/100)+" "+"Hundred"+" "+dfs(n%100);
        }
        else if(n<1000000){//633333
            // cout<<"dfs(n/1000):"<<(n/1000)<<endl;
            res+=dfs(n/1000)+" "+"Thousand"+" "+dfs(n%1000);
        }
        else if(n<1000000000){
            res+=dfs(n/1000000)+" "+"Million"+" "+dfs(n%1000000);
        }
        else if(n<1000000000000){
            res+=dfs(n/1000000000)+" "+"Billion"+" "+dfs(n%1000000000);
        }
        int i = res.size()-1;
        while(res[i]==' '){
            i--;
        }
        // cout<<"i:"<<i<<endl;
        res = res.substr(0, i+1);
        return res;
    }
    string numberToWords(int num) {
        if(num==0){
            return "Zero";
        }
        return dfs(num);
    }
};