package Amazon.Intern.oa20240208ImplementAPI;

import java.util.*;

public class SolWithImplementAPI {
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        Solution S1 = new Solution();
        while(true){
            System.out.println("Enter requests:");
            String In = scan.nextLine();
            if(In.equals("q")) break;
            In = In.substring(1, In.length()-1);
            String[] InSet = In.split(",");
            for(int i=0;i<InSet.length;++i){
                InSet[i] = InSet[i].replaceAll("\"", "").trim();
            }
            String[] res = S1.returnRecords(InSet);
            System.out.print("Res: [");
            for(String s : res) System.out.print(s+",");
            System.out.println("]");
        }
    }
    private static class Solution{
        public String[] returnRecords(String[] attempts) {
            String REGISTER = "register";
            String LOGIN = "login";
            String LOGOUT = "logout";
            Map<String, String> Info = new HashMap<>();
            Set<String> loggedInUser = new HashSet<>();
            String[] ans = new String[attempts.length];
            for(int i=0;i<attempts.length;++i){
                String cmd = attempts[i];
                StringTokenizer tokens = new StringTokenizer(cmd);
                String order = tokens.nextToken();
                String user = tokens.nextToken();
                String pwd = null;
                if(!order.equalsIgnoreCase(LOGOUT)){
                    pwd = tokens.nextToken();
                }
                if(order.equalsIgnoreCase(REGISTER)){
                    if(Info.containsKey(user)){
                        ans[i] = "Username already exists";
                    }
                    else{
                        ans[i] = "Registered Successfully";
                        Info.put(user, pwd);
                    }
                }
                else if(order.equalsIgnoreCase(LOGIN)){
                    if(Info.containsKey(user)){
                        if(Info.get(user).equals(pwd)){
                            ans[i] = "LoggedIn Successfully";
                            loggedInUser.add(user);
                            continue;
                        }
                        ans[i] = "Login Unsuccessfully";
                    }
                }
                else if(order.equalsIgnoreCase(LOGOUT)){
                    if(loggedInUser.contains(user)){
                        ans[i] = "Logged Out Successfully";
                        loggedInUser.remove(user);
                    }
                    else{
                        ans[i] = "Logged Out Unsuccessfully";
                    }
                }
            }
            return ans;
        }
    }
}
