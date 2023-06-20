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

class TreeNode{
	public:
		int val;
		vector<TreeNode*> children;
		TreeNode(int In):val(In){
		}
		TreeNode(){
			val = 0;
		}
};

class Solution {
public:
	/*
	    1/3,2,4,
	*/
	string encoded = "";

	TreeNode* constructTree(vector<int>& nums, int& index){
   		if(index >= nums.size()){
   	    	 return NULL;
   		 }
   	 	TreeNode* root = new TreeNode(nums[index]);
   	 	int numChildren = nums[++index];
   	 	for(int i = 0; i < numChildren; i++){
   	   		 root->children.push_back(constructTree(nums, index));
   	 	}
   	 	return root;
	}

	void printTree(TreeNode * root){
		if(!root){
	        return;
		}
		cout << root->val << " ";
		for(int i = 0; i < root->children.size(); i++){
			 printTree(root->children[i]);
	    }
	}


	string Serialize(TreeNode * root){
		if(!root) return encoded;
		queue<TreeNode*> Q;
		Q.push(root);//1,
		int size;
		while(!Q.empty()){
			size = Q.size();//1,
			while(size--){
				TreeNode * cur = Q.front();
				Q.pop();//2,4
				if(cur){
					encoded+=to_string(cur->val);//encoded: 1,/3,2,4,/5,6,#,#,/#,#,/
					encoded+=",";
					for(auto x : cur->children){
						Q.push(x);//
					}
				}
				else{
					encoded+="#";
					encoded+=",";
				}
			}
			encoded+="/";
		}
		return encoded;
	}

	TreeNode * Deserialize(string & encoded){
		if(encoded.empty()){
			return NULL;
		}
		//			 e	
		//                      r 
		//                                 l
		//encoded: 1,/3,2,4,/5,6,#,#,/#,#,/
		int l=0;
		size_t r = encoded.find(',', l);
		int rootVal = stoi(encoded.substr(l,r-l));
		l=r+2;
		TreeNode * root = new TreeNode(rootVal);
		queue<TreeNode*> Q;
		Q.push(root);
		while(l<encoded.size()){
			TreeNode * cur = Q.front();
			Q.pop();
			while(encoded[l]!='/'){
				if(encoded[l]=='#'){
					l+=2;
					continue;
				}
				else{
					r = encoded.find(',', l);
					int val = stoi(encoded.substr(l, r-l));
					TreeNode * C = new TreeNode(val);
					Q.push(C);
					cur->children.push_back(C);
					l=r+1;
				}
			}
			l++;
		}
		return root;
	}
};

int main(){
    Solution S;
	vector<int> arr = {1,3,2,4,5,6};
	int index = 0;
	TreeNode * root = S.constructTree(arr, index);
	cout<<"Original: ";
	S.printTree(root);
	cout<<endl;
	string encoded = S.Serialize(root);
	cout<<"encoded: "<<encoded<<endl;
	TreeNode * decoded = S.Deserialize(encoded);
	cout<<"decoded: ";
	S.printTree(decoded);
    cout<<endl;
	return 0;
}
