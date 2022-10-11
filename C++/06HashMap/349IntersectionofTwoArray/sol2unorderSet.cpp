class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> ms; 
        unordered_set<int> mt(nums2.begin(), nums2.end());
        for(int i : nums1){
            if(mt.count(i)!=0){//Use set.cout here to determine if an element exist is fater than set.find(). 
            //if(mt.find(i)!=mt.end()){
                ms.insert(i);
            }
        }
        return vector<int>(ms.begin(), ms.end());
    }
};
/*
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> ms; 
        // unordered_set<int> mt(nums2.begin(), nums2.end());
        unordered_set<int> mt;
        for(int x : nums2){
            mt.insert(x);
        }
        for(int i : nums1){
            if(mt.count(i)!=0){//Use set.cout here to determine if an element exist is fater than set.find(). 
            //if(mt.find(i)!=mt.end()){
                ms.insert(i);
            }
        }
        vector<int> ans;
        for(auto a : ms){
            ans.push_back(a);
        }
        //return vector<int>(ms.begin(), ms.end());
        return ans;
    }
};
*/