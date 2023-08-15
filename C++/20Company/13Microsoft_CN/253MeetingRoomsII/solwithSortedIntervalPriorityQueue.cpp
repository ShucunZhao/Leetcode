/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param intervals: an array of meeting time intervals
     * @return: the minimum number of conference rooms required
     */
    class myCmp{
    public:
        bool operator()(const Interval & A, const Interval & B)const{
            if(A.start==B.start){
                return A.end<B.end;
            }
            return A.start<B.start;
        }

    };

    int minMeetingRooms(vector<Interval> &intervals) {
        /*
               e 
               15 17 20 
               s
               6 6 13      
            [(6,15),(6,17),(13,20)]
              0 1 2 3 ... 20

            heap: 15,17,20  
            cnt:  
        */
        // Write your code here
        sort(intervals.begin(), intervals.end(), myCmp());
        priority_queue<int, vector<int>, greater<int> > pq;
        pq.push(intervals[0].end);
        // cout<<pq.top()<<endl;
        for(int i=1;i<intervals.size();i++){
            if(intervals[i].start>=pq.top()){
                pq.pop();
            }
            pq.push(intervals[i].end);
        }
        return pq.size();
    }
};