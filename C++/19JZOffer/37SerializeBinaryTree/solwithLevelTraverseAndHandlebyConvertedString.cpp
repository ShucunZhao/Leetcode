/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
    /*
    void preorder(TreeNode * root, string & s){
        if(!root){
            s+="#,";
            return;
        }
        s+=to_string(root->val);
        s+=",";
        preorder(root->left, s);
        preorder(root->right, s);
        return;
    }
    */
    char* Serialize(TreeNode *root) {    
        if(!root) return NULL;
        /*
        string str;
        preorder(root, str);
        */
        
        string str;
        queue<TreeNode*> Q;
        Q.push(root);
        int size;
        while(!Q.empty()){
            size = Q.size();
            while(size--){
                TreeNode * cur = Q.front();
                Q.pop();
                if(cur){
                    str+=to_string(cur->val);
                    str+=",";
                    Q.push(cur->left);
                    Q.push(cur->right);
                }
                else{
                    str+="#,";
                }
            }
        }
        
        str.pop_back();
        str.push_back('\0');/*
            When you append the null character to the std::string, it will create a new buffer with the null character at the end. 
            However, when you return the char* pointer to the string using &str[0], you are returning a pointer to the original buffer. 
            This buffer may be destroyed when the Serialize function exits, leaving the returned pointer pointing to invalid memory.
        */
        /*
            To avoid this issue, you can make a copy of the char* string before appending the null character to it. 
            This way, you can return a pointer to the new buffer, which will remain valid even after the Serialize function exits.
        */
        char * ans = new char[str.size()];
        strcpy(ans, str.c_str());
        //cout<<"org:"<<ans<<endl;
        return ans;
        //return &str[0];
    }
    /*
    TreeNode * construct(char * str, int & start){
        if(str[start]==','){
            start+=1;
        }
        if(str[start]=='\0'||str[start]=='#') return NULL;
        string s;
        while(str[start]!=','){
            s+=str[start];
            start++;
        }
        TreeNode * root = new TreeNode(stoi(s));
        root->left = construct(str, ++start);
        root->right = construct(str, ++start);
        return root;
    }
    */
    TreeNode* Deserialize(char *str) {
        if(str==NULL) return NULL;
        //cout<<str<<endl;
        /*
            {1,2,3,#,#,6,7}
            root:1
           |      |
           2      3 
        */
        /*
        cout<<"new:";
        for (int i = 0; str[i]!='\0'; i++)
        {
            cout << str[i];
        }
        */
        //int start = 0;
        stringstream ss(str);
        vector<string> save;
        string token;
        while(getline(ss, token, ',')){
            save.push_back(token);
            //cout<<token<<endl;            
        }
        queue<TreeNode*> Q;
        int i = 0;
        TreeNode * root = new TreeNode(stoi(save[i++]));
        Q.push(root);
        int size;
        while(!Q.empty()){
            size = Q.size();
            while(size--){
                TreeNode * cur = Q.front();
                Q.pop();
                if(save[i]!="#"){
                    cur->left = new TreeNode(stoi(save[i]));
                    i++;
                    Q.push(cur->left);
                }
                else{
                    i++;
                    cur->left = NULL;
                }
                if(save[i]!="#"){
                    cur->right = new TreeNode(stoi(save[i]));
                    i++;
                    Q.push(cur->right);
                }
                else{
                    i++;
                    cur->right = NULL;
                }
            }
        }
        //cout<<ss.str()<<endl;
        return root;
    }
};