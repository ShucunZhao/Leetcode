/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    /*
    S:
        size: 0
        Q: N,N,4,5,
        cur: 3
        s: 1,#2,3,#N,N,4,5
    D:
                 i
        s:1,#2,3,#N,N,4,5
        Q:2,3

    */
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        queue<TreeNode*> Q;
        Q.push(root);
        string str = "";
        // int size;
        while(!Q.empty()){
            // size = Q.size();
            // while(size--){
            TreeNode * cur = Q.front(); 
            Q.pop();
            if(cur){
                Q.push(cur->left);
                Q.push(cur->right);
                str+=to_string(cur->val);
                str+=",";
            }
            else{
                str+="N";
                str+=",";
            }
            // }
        }
        // cout<<str<<endl;
        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data[0]=='N') return NULL;
        queue<TreeNode*> Q;
        int l = 0;
        int curI = data.find(',', l);
        string rootVal = data.substr(l, curI-l);
        // cout<<"curI:"<<curI<<", rootVal:"<<rootVal<<endl;
        curI++;
        l = curI;
        // int Root = stoi(rootVal);
        // cout<<"rootVal:"<<rootVal<<endl;
        TreeNode * root = new TreeNode(stoi(rootVal));
        Q.push(root);
        while(!Q.empty()){
            /*
                2,3
                2,3,N,N,4,5,N,N,N,N,
                100

            */
            TreeNode * cur = Q.front();
            Q.pop();
            curI = data.find(',', l);
            string lVal = data.substr(l, curI-l);
            curI++;
            l = curI;
            curI = data.find(',', l);
            string rVal = data.substr(l, curI-l);
            curI++;
            l = curI;
            // cout<<"lVal:"<<lVal<<", rVal:"<<rVal<<endl;
            if(!lVal.empty()&&lVal!="N"){
                TreeNode * newL = new TreeNode(stoi(lVal));
                cur->left = newL;
                Q.push(newL);
            }
            if(!rVal.empty()&&rVal!="N"){
                TreeNode * newR = new TreeNode(stoi(rVal));
                cur->right = newR;
                Q.push(newR);
            }
        }
        return root;
        // return NULL;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));