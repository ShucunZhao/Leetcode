class Solution {
public:
    int GetUglyNumber_Solution(int index) {
        /*
            We can from 1 to find the ugly number by multiply 2,3 and 5.  
            For example:
                n = 11
                 i:   1 2 3 4 5 6 8 9 10 12 15 20 
               num:  
        */
        if(index==0) return 0;
        unordered_set<long long> ms;
        priority_queue<long long, vector<long long>, greater<long long> > pq;
        vector<long long> ans;
        pq.push(1);
        while(ms.size()<index&&!pq.empty()){
            long long i = pq.top();
            pq.pop();
            if(ms.count(i)==0){
                ms.insert(i);
                ans.push_back(i);
                for(int j=2;j<=5;){ 
                    long long ugly = i*j; 
                    j=2*j-1;
                    cout<<ugly<<endl;
                    pq.push(ugly);
                }
            }
        }
        //cout<<ms.size()<<endl;
        /*
        for(int i : ans){
            cout<<i<<endl;
        }
        */
        return ans[index-1];
    }
};