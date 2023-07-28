/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int binarySearch(int l, int r, bool up, int target, MountainArray &mountainArr){
        while(l<=r){
            int m = l+(r-l)/2;
            int mVal = mountainArr.get(m);
            if(mVal==target) return m;
            if(up){
                if(mVal>target){
                    r = m-1;
                }
                else if(mVal<target){
                    l = m+1;
                }
            }
            else{
                if(mVal>target){
                    l = m+1;
                }
                else if(mVal<target){
                    r = m-1;
                }
            }
        }
        return -1;
    }
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int l = 1, r = mountainArr.length()-2;
        int peak;
        while(l<=r){
            int m = l+(r-l)/2;
            int mVal = mountainArr.get(m);
            int lVal = mountainArr.get(m-1);
            int rVal = mountainArr.get(m+1);
            if(lVal<mVal&&mVal>rVal){
                peak = m;
                break;
            }
            else if(lVal>mVal&&mVal>rVal){
                r = m-1;
            }
            else{
                l = m+1;
            }
        }
        // cout<<"peak:"<<peak<<endl;
        int left = binarySearch(0, peak, true, target, mountainArr);
        if(left!=-1) return left;
        int right = binarySearch(peak, mountainArr.length()-1, false, target, mountainArr);
        // cout<<"left:"<<left<<endl;
        // cout<<"right:"<<right<<endl;
        return right; 
    }
};