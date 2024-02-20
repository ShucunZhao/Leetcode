package lc232ImplementQueueUsingStacks;
import java.util.Stack;
import java.util.Scanner;

public class SolWithStack {
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        MyQueue mq = new MyQueue();
        while(true){
            System.out.println("Enter command with format xxx,value: ");
            String In = scan.nextLine();
            if(In.equals("q")) break;
            String[] InSet = In.split(",");
            String cmd = InSet[0], val = InSet[1];
            if(cmd.equals("MyQueue")){
                mq = new MyQueue();
            }
            else if(cmd.equals("push")){
                mq.push(Integer.parseInt(val));
            }
            else if(cmd.equals("peek")){
                System.out.println(mq.peek());
            }
            else if(cmd.equals("pop")){
                System.out.println( mq.pop());
            }
            else if(cmd.equals("empty")){
                System.out.println(mq.empty());
            }
        }

    }
    private static class MyQueue{
        /*
                In:  {456
                Out: {
                1
         */
        private Stack<Integer> InSt;
        private Stack<Integer> OutSt;

        public MyQueue() {
            InSt = new Stack<>();
            OutSt= new Stack<>();
        }

        public void push(int x) {
            InSt.push(x);
        }

        public int pop() {
            if(OutSt.empty()) {
                while (!InSt.empty()) {
                    OutSt.push(InSt.pop());
                }
            }
            return OutSt.pop();
        }

        public int peek() {
            if(OutSt.empty()) {
                while (!InSt.empty()) {
                    OutSt.push(InSt.pop());
                }
            }
            return OutSt.peek();
        }

        public boolean empty() {
            return InSt.empty()&&OutSt.empty();
        }
    }
}
