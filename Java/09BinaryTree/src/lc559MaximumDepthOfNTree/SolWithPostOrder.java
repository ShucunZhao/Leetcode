package lc559MaximumDepthOfNTree;

import java.util.List;

public class SolWithPostOrder {
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
    public int maxDepth(Node root) {
        if(root==null) return 0;
        int maxD = 0;
        for(int i=0;i<root.children.size();++i){
            maxD = Math.max(maxD, maxDepth(root.children.get(i)));
        }
        return maxD+1;
    }
}
