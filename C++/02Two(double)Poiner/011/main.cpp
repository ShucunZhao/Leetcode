/*
 * The key to this task: (Two pointers)
 * 1.Define the head and tail pointer
 * 2.Move the index whoes value of height is less:
 *   if not, area will decrease while the width shorten
 * 3.Return the max area at last
 */ 
class Solution {
public:
    int maxArea(vector<int>& height) {
        int area = 0;
        int w, h;
        int i=0,j=height.size()-1;
        while(i<j){
            w = j-i;
            if(height[i]>height[j]){
                h = height[j];
                j--;
            }
            else{
                h = height[i];
                i++;
            }
            area = h*w>area?h*w:area;
        }
        return area;
    }
};