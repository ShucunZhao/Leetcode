class Solution {
public:
    void reverseString(vector<char>& s) {
        for(int l=0,r=s.size()-1; l<r;l++,r--){//The end condition is l==r:
                                                //Because the middle element can stay in place.
            swap(s[l],s[r]);
            /*
	int tmp = s[l];
	s[l] = s[r];
	s[r] = tmp;
	*/
        }
    }
};