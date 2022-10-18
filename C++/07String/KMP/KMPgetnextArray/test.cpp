#include <string>
#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

void getNextmy(vector<int> & next, const string & str){
	next[0] = 0;
	int j;
	for(size_t i=1;i<str.size();i++){
		j = next[i-1];
		while(j>0&&str[j]!=str[i]){
			j = next[j-1];
		}
		if(str[j]==str[i]){
			next[i] = j+1;
		}
		else{
			next[i] = 0;
		}
	}
}

void getNextCarl(vector<int> & next, const string & s){
	int j = 0;
	next[0] = 0;
	for(size_t i=1;i<s.size();i++){
		while(j>0&&s[i]!=s[j]){
			j=next[j-1];
		}
		if(s[i]==s[j]){
			j++;
		}
		next[i] = j;
	}
}

int main(int argc, char ** argv){
	string str("aabaaf");
	vector<int> next1(str.size(), 0);
	vector<int> next2(str.size(), 0);
	getNextmy(next1, str);
	getNextCarl(next2, str);
	for(int x : next1){
		cout<<x<<",";
	}
	cout<<endl;
	for(int y : next2){
		cout<<y<<",";
	}
	cout<<endl;

	
	return EXIT_SUCCESS;
}
