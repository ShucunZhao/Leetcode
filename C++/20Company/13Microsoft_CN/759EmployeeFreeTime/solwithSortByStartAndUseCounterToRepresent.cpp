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
	int start;
	int end;
	Interval(){}
	Interval(int sIn, int eIn){
		this->start = sIn;
		this->end = eIn;
	}
};

class Solution {
public:	
	
	class myCmp{
	public:
		bool operator()(const Interval & A, const Interval & B) const{
			if(A.start!=B.start) return A.start<B.start;
			return A.end<B.end;
		}
	};
	
    vector<Interval> employeeFreeTime(vector<vector<Interval> > schedule) {
	/*
		cnt: 0
		schedule = [[[1,3],[6,7]],[[2,4]],[[2,5],[9,12]]]
		sorted:	[1,3] [2,4] [2,5] [6,7] [9,12]	
		 	 	1  3  2  1  0  1  0  0  1  1   1   0		
		flag:   1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12

		ans:	[5,6], [7,9]
	*/
		sort(schedule[0].begin(), schedule[0].end(), myCmp());
		int size = schedule[0].size();
		int head = schedule[0][0].start, tail = schedule[0][size-1].end;
		int len = tail-head+1;
		vector<int> cnt(len);
		vector<int> startSet(len), endSet(len);
		cout<<"head:"<<head<<",tail:"<<tail<<endl;
		for(auto x : schedule[0]){
			startSet[x.start-head]++;
			endSet[x.end-head]++;
		}
		cout<<"startSet:";
		for(int i : startSet){
			cout<<i<<",";
		}
		cout<<endl;
		cout<<"endSet:";
		for(int i : endSet){
			cout<<i<<",";
		}
		cout<<endl;
		int pre = 0;
		for(int i=0;i<len;i++){
			if(startSet[i]){
				cnt[i]+=startSet[i];
			}
			if(endSet[i]){
				cnt[i]-=endSet[i];
			}
			cnt[i]+=pre;
			pre = cnt[i];
		}
		cout<<"cnt:";
		for(int i : cnt){
			cout<<i<<",";
		}
		cout<<endl;
		vector<Interval> ans;
		for(int i=0;i<len;i++){
			if(cnt[i]==0){
/*
   					        i  j   
		 	 	1  3  2  1  0  1  0  0  1  1   1   0		
		flag:   1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12
		*/
				int j = i+1;
				while(j<len&&cnt[j]==0) j++;
				if(j<len){
					ans.push_back(Interval(i+head, j+head));
					i =  j;
				}
			}
		}
		for(auto x : ans){
			cout<<x.start<<","<<x.end<<endl;
		}
	
		/*
		for(auto x : schedule[0]){
		cout<<x.start<<","<<x.end<<endl;
		}
		*/
		return ans;
    }
};

int main(){
	vector<vector<Interval> > schedule = {{Interval(1,3),Interval(6,7),Interval(2,4),Interval(2,5),Interval(9,12)}};
	vector<vector<Interval> > schedule2 = {{Interval(1,2),Interval(5,6),Interval(1,3),Interval(4,10)}};

	/*
	for(auto x : schedule[0]){
		cout<<x.start<<","<<x.end<<endl;
	}
	cout<<"------------"<<endl;
	*/
    Solution S;
	S.employeeFreeTime(schedule2);
    return 0;
}
