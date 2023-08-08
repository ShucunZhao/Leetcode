class Solution {
public:
    int nthUglyNumber(int n) {
        if(n==1) return 1;
        /*
            [1, 2, 3, 4, 5, 6, 8, 9, 10, 12]
            Use base 1 to calculate the ugly number from small to large
            and use priority queue to get the No.n small answer.
            pq: 4,5,6,10,
            1,2,3
        */
        // bool check[10000] = {false};
        // unordered_set<long long> mset;
        priority_queue<long long, vector<long long>, greater<long long> >pq;
        pq.push(1);
        // check[1] = true;
        // mset.insert(1);
        long long ans;
        // n++;
        while(n--){
            ans = pq.top();
            // cout<<"n:"<<n<<",ans:"<<ans<<endl;
            pq.pop();
            while(!pq.empty()&&pq.top()==ans) pq.pop();
            pq.push(2*ans);
            pq.push(3*ans);
            pq.push(5*ans);
            /*
            if(mset.count(2*ans)==0){
                mset.insert(2*ans);
                pq.push(2*ans);
            }
            if(mset.count(3*ans)==0){
                mset.insert(3*ans);
                pq.push(3*ans);
            }         
            if(mset.count(5*ans)==0){
                mset.insert(5*ans);
                pq.push(5*ans);
            }       
            */        
            /*
            if(!check[2*ans]){
                check[2*ans] = true;
                pq.push(2*ans);
            }
            if(!check[3*ans]){
                check[3*ans] = true;
                pq.push(3*ans);
            }
            if(!check[5*ans]){
                check[5*ans] = true;
                pq.push(5*ans);
            }
            */
        }
        return ans;
    }
};