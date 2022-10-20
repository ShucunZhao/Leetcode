class Solution {
private:
    template<typename T>
    class MyQue{
    public:
        deque<T> que;
        void push(T val){
            while(!que.empty()&&val>que.back()){//KeyPoint: You cannot use val>=que.back() as condition here because
                                                //if all elements inside the windows are same you also need to save one
                                                //of them as the maximum rather pop them!
                que.pop_back();
            }
            que.push_back(val);
        }
        void pop(T val){
            if(!que.empty()&&que.front()==val){
                que.pop_front();
            }
        }
        T getMax(){
            return que.front();
        }
    };
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        MyQue<int> Q;
        vector<int> ans;
        for(int i=0;i<k;i++){
            Q.push(nums[i]);
        }
        ans.push_back(Q.getMax());
        for(int j=k;j<nums.size();j++){
            Q.push(nums[j]);
            Q.pop(nums[j-k]);
            ans.push_back(Q.getMax());
        }
        return ans;
    }
};