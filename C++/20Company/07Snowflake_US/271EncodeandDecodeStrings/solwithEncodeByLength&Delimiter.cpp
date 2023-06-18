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
	/*
		"You", "know", "what", "time", "it", "is"
		3You4know4what4time2it2is
		3/You4/know4/what4/time2/it2/is
		=======================================
	    prog8/ramming language
		i
		  j
		13/prog8/ramming8/language
	*/
	string encode(vector<string> & Strs){
		string encoded = "";
		for(string str : Strs){
			encoded+=(to_string(str.length())+"/"+str);
			//encoded+=(to_string(str.length())+str);//If only add the length to head will not work in length more than 10 case.
		}
		return encoded;
	}

	vector<string> decode(string & encoded){
		vector<string> decoded;
		for(int i = 0, j = 0;i<encoded.size();i++){
			//auto pos = find(encoded.begin()+i, encoded.end(), '/');
			size_t pos = encoded.find('/', i);//KeyPoint here! How to find target char from a specific position in string.
			if(pos==string::npos){
				break;
			}
			//j = pos - encoded.begin();
			j = pos;
			int len = stoi(encoded.substr(i, j-i));
			string s = encoded.substr(j+1, len);
			//string s = encoded.substr(i+2, len);
			//cout<<"len: "<<len<<", s: "<<s<<endl;
			//i+=len+1;
			i=j+len;
			decoded.push_back(s);
		}
		return decoded;	
	}

};

int main(){
    Solution S;
	vector<vector<string> > StrsSet = {
		{"You", "know", "what", "time", "it", "is"},
		{},
		{"hello"},
		{"a very long string that exceeds the maximum string length allowed in the programming language being used"},
		{"hello", "world", "abc/def"},
		{"hello", "world", "3.14:pi"},
		{"hello", "world", "こんにちは"},
		{"hello", "world/", "leetcode"}
	};
	for(vector<string> Strs : StrsSet){
		cout<<"Original string set:"<<endl;
		for(string s : Strs){
			cout<<s;
		}
		cout<<endl;
		string encoded = S.encode(Strs);
		cout<<"Encoded string is: "<<encoded<<endl;
		vector<string> decoded = S.decode(encoded);
		cout<<"Decoded string set:"<<endl;
		for(string s : decoded){
			cout<<s;
		}
		cout<<endl;
	}
    return 0;
}
