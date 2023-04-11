class Solution {
public:

    int leastInterval(vector<char>& tasks, int n) {
        /*
            Coner case: n == 0: return tasks,size().
            tasks =  ["A","A","A","B","B","B", "C","C","C", "D", "D", "E"], n = 2
            Frequency:
                A: 3(f)    B: 3(f)    C: 3(f)    D: 2    E: 1   
            Greedy: Because same task should be divided between n tasks, do the task placement by the order of frequency.
            1.Find the task whose frequency is most, and place their to positions first:
                A B_ C_
                A B_ C_
                A B C

            2. p is the number of most frequency element.(If there exist any same most frequency element).
                p=1;
            ans = (f-1)*(n+1) + p
                = (6-1)*(2+1) + 1
                = 5*3+1
                = 16
        */
        if(n==0) return tasks.size();
        unordered_map<char, int> ms;
        for(char c : tasks) ms[c]++;
        vector<pair<char, int> > Vec(ms.begin(), ms.end());
        sort(Vec.begin(), Vec.end(), [](const pair<char, int> & A, const pair<char, int> & B) ->int {
            return A.second>B.second;
        });
        int freq = Vec[0].second;
        int mostCnt = 0;
        for(auto x : ms){
            if(x.second==freq){
                mostCnt++;
            }
        }
        //cout<<"mostCnt:"<<mostCnt<<endl;
        /*
        for(auto x : Vec){
            cout<<x.first<<":"<<x.second<<endl;
        }
        */
        int rst = (freq-1)*(n+1)+mostCnt;
        return tasks.size()>rst?tasks.size():rst;//KeyPoint here: If the size is larger than our Greedy fomula, which means there will have some
                                                        //elements remain, so need to add this situation.
    }
};