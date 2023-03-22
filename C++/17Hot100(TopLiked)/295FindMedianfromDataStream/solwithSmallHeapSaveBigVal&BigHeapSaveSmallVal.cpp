class MedianFinder {
public:
    struct greater{
        bool operator()(int a, int b){
            return a>b;
        }
    };    
    struct smaller{
        bool operator()(int a, int b){
            return a<b;
        }
    }; 
    priority_queue<int, vector<int>, greater> Small;
    priority_queue<int, vector<int>, smaller> Big;
    MedianFinder() {
        /*
        for(int i=0;i<10;i++){
            Big.push(i);
        }
        for(int i=0;i<10;i++){
            Small.push(i);
        }
        cout<<"Big:";
        while(!Big.empty()){
            cout<<Big.top()<<",";
            Big.pop();
        }
        cout<<endl;
        cout<<"Small:";
        while(!Small.empty()){
            cout<<Small.top()<<",";
            Small.pop();
        }
        cout<<endl;
        */
    }
    /*
        Hint:
            Define two heaps, one Big-roof heap for saving smaller elements,
            another Small-roof heap for saving bigger elements.
            Keep the small-roof head always has more elements:
            i:     0 1 2 3 4 5 
            arr = [2,3,4,7,9,8]
            Big:(Put smaller)          Small:(Put larger) 
    head:        2                           3                            

    */
    void addNum(int num) {
        if(Small.size()==0){
            Small.push(num);
            //return;
        }
        else if(Big.size()==0){
            if(num >= Small.top()){
                Big.push(Small.top());
                Small.pop();
                Small.push(num);
                //swap(num, Small.top());
            }
            else{
                Big.push(num);
            }
        }
        else if(num<Small.top()){
            Big.push(num);
        }
        else{
            Small.push(num);
        }
        //Keep size balance:
        if(Small.size()>Big.size()&&Small.size()-Big.size()>1){
            Big.push(Small.top());
            Small.pop();
        }
        else if(Big.size()>Small.size()&&Big.size()-Small.size()>1){
            Small.push(Big.top());
            Big.pop();
        }
    }
    
    double findMedian() {
        if(Big.size()>Small.size()){
            return Big.top();
        }
        else if(Big.size()<Small.size()){
            return Small.top();
        }
        return ((Big.top()+Small.top())/2.0);
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */