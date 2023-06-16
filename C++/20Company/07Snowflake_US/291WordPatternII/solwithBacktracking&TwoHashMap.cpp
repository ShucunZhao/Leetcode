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

using namespace std;

class Solution {
public:
	unordered_map<string, char> ms;
	unordered_map<char, string> mp;
	bool backtracking(string & pattern, string & str, int index, int start){
		if(index==pattern.size()||start==str.size()){//"redblueredblue"
			return index==pattern.size()&&start==str.size();
		}
		for(int i=start;i<str.size();i++){
			//0
			//1
			string tmp = str.substr(start, i-start+1);
			//cout<<tmp<<endl;
			if(ms.count(tmp)!=0&&ms[tmp]!=pattern[index]){
				continue;
			}
			if(mp.count(pattern[index])!=0&&mp[pattern[index]]!=tmp){
				continue;
			}
			ms[tmp] = pattern[index];
			mp[pattern[index]] = tmp;
			bool check = backtracking(pattern, str, index+1, i+1);//Backtracking step: plus one here!
			ms.erase(tmp);//Backtracking step!
			mp.erase(pattern[index]);//Backtracking step!
			if(check) return true;
		}
		return false;
	}
	bool wordPatternMatch(string pattern, string str){
		return backtracking(pattern, str, 0,0);
	}
};

int main(){
    Solution S;
    vector<string> patternSet, stringSet;
	patternSet.push_back("abab");
	stringSet.push_back("redblueredblue");
 	patternSet.push_back("aaaa");
	stringSet.push_back("asdasdasdasd");
 	patternSet.push_back("aabb");
	stringSet.push_back("xyzabcxzyabc");
	for(int i=0;i<3;i++){
		cout<<S.wordPatternMatch(patternSet[i], stringSet[i])<<endl;
		cout<<"Next pairs:"<<endl;
	}
	//cout<<S.wordPatternMatch(patternSet[0], stringSet[0])<<endl;
    return 0;
}
