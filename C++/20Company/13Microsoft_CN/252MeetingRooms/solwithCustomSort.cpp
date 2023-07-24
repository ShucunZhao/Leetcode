#include <cstdlib>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <queue>
#include <climits>
#include <thread>
#include <map>
#include <list>
#include <mutex>
#include <algorithm>

using namespace std;

class Interval{
public:
	int start, end;
	Interval(int start, int end){
		this->start = start;
		this->end = end;
	}
};

class Solution {
public:
	class myCmp{
	public:
		bool operator()(Interval a, Interval b){
			return a.start<b.start;
		}
	};
	bool canAttendMeetings(vector<Interval> & intervals){
		if(intervals.size()<2) return true;
		sort(intervals.begin(), intervals.end(), myCmp());
		for(int i=1;i<intervals.size();i++){
			if(intervals[i].start<intervals[i-1].end) return false;
		}
		return true;
	}	
};

int main(){
	vector<Interval> intervals;
	intervals.push_back(Interval(5,8));
	intervals.push_back(Interval(9,15));
	//intervals.push_back(Interval(15,20));
    Solution S;
    cout<<S.canAttendMeetings(intervals)<<endl;
    return 0;
}
