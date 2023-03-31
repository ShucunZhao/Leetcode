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
         1-2-3-4-5

    */
    string path;
    void levelTraverse(TreeNode * root){
        //Step1: Use level traversal to convert tree into string that split by "," and use "#" 
        //       to represent the NULL node. 
        queue<TreeNode*> Q;
        Q.push(root);
        int size;
        //Q: 2,3,
        //S: 1,2,
        while(!Q.empty()){
            size = Q.size();
            while(size--){
                TreeNode * cur = Q.front();
                Q.pop();
                if(!cur){//If is null node add "#" in string.
                    path+="#,";
                    continue;
                }
                path+=to_string(cur->val);
                path+=",";
                Q.push(cur->left);
                Q.push(cur->right);
            }
        }
        path.pop_back();
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "";
        levelTraverse(root);
        return path;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty()) return NULL;
        /*
        for(int i=0;i<data.size();i++){
            cout<<data[i];
        }
        cout<<endl;
        */
        stringstream ss(data);
        vector<string> parse;
        string str;
        while(getline(ss, str, ',')){
            parse.push_back(str);
        }
        TreeNode * root = new TreeNode(stoi(parse[0]));
        queue<TreeNode*> Q;
        Q.push(root);
        //Q: NN45
        //P: 45####

        for(int i=1;i<parse.size();){
            TreeNode * cur = Q.front();//2
            Q.pop();
            if(!cur){
                continue;
            }
            if(parse[i]!="#"){
                cur->left = new TreeNode(stoi(parse[i]));
            }
            Q.push(cur->left);
            i++;
            if(parse[i]!="#"){
                cur->right = new TreeNode(stoi(parse[i]));
            }
            Q.push(cur->right);
            i++;
        }
        /*
        for(int i=0;i<parse.size();i++){
            cout<<parse[i]<<endl;
        }
        */
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));