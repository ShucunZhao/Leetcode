class Solution {
public:
    string IPv6Check(string & queryIP, char & tag){
        /*
             l
                 r
            "2001:0db8:85a3:0:0:8A2E:0370:7334"
        */
        queryIP.push_back(':');//Add a another dot at tail to help handle.
        // string tmp;
        int cntColon = 0;
        int l=0,r=0;
        while(find(queryIP.begin(), queryIP.end(), tag)!=queryIP.end()){
            cntColon++;
            if(cntColon>8) return "Neither";
            r = queryIP.find(tag);
            if(r-l>4||r==l) return "Neither";
            while(l<r){
                if(!isdigit(queryIP[l])&&!isalpha(queryIP[l])){
                    return "Neither";
                }
                if(isalpha(queryIP[l])){
                    char c = queryIP[l];
                    if(islower(c)&&c>'f'){
                        return "Neither";
                    }
                    if(isupper(c)&&c>'F'){
                        return "Neither";
                    }
                }
                l++;
            }
            l=0;
            // tmp = queryIP.substr(l, r-l);
            // cout<<"tmp:"<<tmp<<endl;
            // cout<<"r:"<<r<<endl;
            queryIP = queryIP.substr(r+1);
            // cout<<"cntColon:"<<cntColon<<endl;
        }
        return cntColon==8?"IPv6":"Neither";
    }
    string IPv4Check(string & queryIP, char & tag){
        /*
             l
                r
            "172.16.254.1"
        */
        queryIP.push_back('.');//Add a another dot at tail to help handle.
        string tmp;
        // string remain;
        int cntDot = 0;
        int l=0,r=0;
        while(find(queryIP.begin(), queryIP.end(), tag)!=queryIP.end()){
            cntDot++;
            if(cntDot>4) return "Neither";
            r = queryIP.find(tag);
            if(r-l>3||r==l) return "Neither";
            if(queryIP[l]=='0'&&r-l>1){
                return "Neither";
            }
            tmp = queryIP.substr(l, r-l);
            // cout<<"tmp:"<<tmp<<endl;
            if(!all_of(tmp.begin(), tmp.end(), ::isdigit)){
                // bool is_digit = std::all_of(str.begin(), str.end(), ::isdigit);
                return "Neither";
            }
            if(stoi(tmp)>255||stoi(tmp)<0) return "Neither";
            // cout<<"r:"<<r<<endl;
            queryIP = queryIP.substr(r+1);
            // cout<<"cnt:"<<cntDot<<endl;
        }
        return cntDot==4?"IPv4":"Neither";
    }
    string validIPAddress(string queryIP) {
        char ip4 = '.', ip6 = ':';
        if(find(queryIP.begin(), queryIP.end(), ip4)!=queryIP.end()&&find(queryIP.begin(), queryIP.end(), ip6)==queryIP.end()){
            return IPv4Check(queryIP, ip4);
        }
        else if(find(queryIP.begin(), queryIP.end(), ip6)!=queryIP.end()&&find(queryIP.begin(), queryIP.end(), ip4)==queryIP.end()){
            return IPv6Check(queryIP, ip6);;
        }
        return  "Neither";
    }
};