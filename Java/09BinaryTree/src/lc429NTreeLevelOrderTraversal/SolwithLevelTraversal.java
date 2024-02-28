package lc429NTreeLevelOrderTraversal;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

public class SolwithLevelTraversal {
    class Node {
        public int val;
        public List<Node> children;

        public Node() {}

        public Node(int _val) {
            val = _val;
        }

        public Node(int _val, List<Node> _children) {
            val = _val;
            children = _children;
        }
    };
    class Solution {
        public List<List<Integer>> levelOrder(Node root) {
            if(root==null) return new ArrayList<>();
            Queue<Node> Q = new LinkedList<>();
            Q.add(root);
            int size;
            List<List<Integer> > ans = new ArrayList<>();
            while(!Q.isEmpty()){
                size = Q.size();
                List<Integer> tmp = new ArrayList<>();
                while(size-->0){
                    Node cur = Q.poll();
                    if(cur!=null){
                        tmp.add(cur.val);
                        for(int i=0;i<cur.children.size();++i){
                            Node child = cur.children.get(i);
                            if(child!=null) Q.add(child);
                        }
                    }
                }
                ans.add(tmp);
            }
            return ans;
        }
    }
}
