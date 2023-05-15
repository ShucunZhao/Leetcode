class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size) {
        /*
                           i
            [2,3,4,2,6,2,5,1],     3
                     
        It's not neccessary to keep the values which is smaller than current value.
        Q:  In:  5,6   |Out        ans: 4,4,6,6,6

        //st: IN:   ,4,3,2|base        max: 6//Cannot use monotonic stack here.

        */
        if(size==0||size>num.size()) return {};
        deque<int> Q;
        vector<int> ans;
        for(int i=0;i<num.size();i++){
            while(!Q.empty()&&num[i]>Q.back()){
                Q.pop_back();
            }
            Q.push_back(num[i]);
            if(i>=size&&Q.front()==num[i-size]){//KeyPoint, if the size of slidingWindow is larger than size need to
                                                //check if the front element is valid, if no longer valid just pop it.
                Q.pop_front();
            }
            if(i>=size-1) ans.push_back(Q.front());
        }
        return ans;
    }
};