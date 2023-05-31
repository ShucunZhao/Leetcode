#include <cstdlib>
#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
#include <queue>
#include <climits>

using namespace std;

/*
 *	We group all the data into 10 thousand bit which is 4 bits in number to deal with:
 *	1.Map the number to Chinese.
 *	2.Deal with each group by 4 bits.
 *  Map:
 *  There possible situations are: 一,二,...,九;十,百,千,万,亿, and the zero is spectial to save alone.
 *  The basic number 一,二,...,九 should be saved to an array.
 *  The each 10 thousand group unis 十,百,千 should be saved to an array.
 *  The larger 10-thousand and billion units 万,亿 should be saved to an array.
 */ 

class Solution {
public:
    string atoCN(int N) {//2001234
		string word;//Answer.
		//Preparation:
		const string CN_ZERO = "零";
		const string CN_DIGITS[10] = {"","一","二","三","四","五","六","七","八","九"};
		const string CN_BaseUnit[4] = {"","十","百","千"};
		const string CN_LarUnit[3] = {"","万","亿"};
		//Step1: extract the number in each bits:
		int data[10];//Save each number of bit in N(The max of input data is 10 billion so that the size is 10).
		int digit; 
		int pos = 0;
		int len;
		while(N){
			digit = N%10;//4
			N /= 10;//200123
			data[pos++] = digit;
		}
		len = pos;
		//Step2: translate to Chinese:
		//len: 7
		//i:     0 1 2 3 4 5 6
		//data: {2,0,0,1,2,3,4}
		int groupSize = 4;
		bool groupIsZero = true;
		bool needZero = false;
		int unit = 0;
		int group = 0;
		for(int i=len-1;i>=0;i--){
			unit = i%4;//2
			group = i/4;//1
			if(data[i]!=0){
				if(needZero){
					word+=CN_ZERO;
				}
				if(data[i]!=1||unit!=1||(!groupIsZero)||(group==0&&needZero)){
					word+=CN_DIGITS[data[i]];
				}
				word+=CN_BaseUnit[unit];
			}
			groupIsZero = groupIsZero&&data[i]==0;
			if(unit==0&&(!groupIsZero)){
				word+=(CN_LarUnit[group]);
			}
			needZero = (data[i]==0&&(unit!=0||groupIsZero));
			if(unit==0){
				groupIsZero = true;
			}
		}
		return word;
    }
};

int main(){
	int N;
	cout<<"Please enter a number:\n";
	cin>>N;
	if(N==0){
		cout<<"零"<<endl;
	}
	Solution S1;
	string ans = S1.atoCN(N);
	cout<<ans<<endl;
	return 0;
}
