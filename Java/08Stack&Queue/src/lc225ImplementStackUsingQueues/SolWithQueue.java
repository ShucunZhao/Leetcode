package lc225ImplementStackUsingQueues;
import java.util.Queue;
import java.util.LinkedList;
import java.util.Scanner;

public class SolWithQueue {
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        MyStack st = new MyStack();
        while(true){
            System.out.println("Enter command with format xxx,value: ");
            String In = scan.nextLine();
            if(In.equals("q")) break;
            String[] InSet = In.split(",");
            String cmd = InSet[0], val = InSet[1];
            if(cmd.equals("MyStack")){
                st = new MyStack();
            }
            else if(cmd.equals("push")){
                st.push(Integer.parseInt(val));
            }
            else if(cmd.equals("top")){
                System.out.println(st.top());
            }
            else if(cmd.equals("pop")){
                System.out.println(st.pop());
            }
            else if(cmd.equals("empty")){
                System.out.println(st.empty());
            }
        }
    }
    private static class MyStack{
        /*      ____
                1,2,3
                ____
         */
        private Queue<Integer> Q;
        public MyStack() {
            Q = new LinkedList<>();
        }

        public void push(int x) {
            Q.add(x);
        }

        public int pop() {
            for(int i=0;i<Q.size()-1;++i){
                int tmp = Q.poll();
                Q.add(tmp);
            }
            return Q.poll();
        }

        public int top() {
           int res = pop();
            Q.add(res);
            return res;
        }

        public boolean empty() {
            return Q.isEmpty();
        }
    }
}
