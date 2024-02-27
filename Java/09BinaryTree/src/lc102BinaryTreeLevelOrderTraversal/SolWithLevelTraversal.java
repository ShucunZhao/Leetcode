package lc102BinaryTreeLevelOrderTraversal;

import java.util.*;

public class SolWithLevelTraversal {
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        Solution S1 = new Solution();
        while(true){
            System.out.println("Enter tree node set with [x,x,x]: ");
            String In = scan.nextLine();
            if(In.equals("q")) break;
            In = In.substring(1, In.length()-1);
            String[] InSet = In.split(",");
            int[] nums = new int[InSet.length];
            for(int i=0;i<nums.length;++i){
                if(InSet[i].equals("null")) nums[i] = -1;
                else nums[i] = Integer.parseInt(InSet[i].trim());
            }
            TreeNode root = construct(nums);
            List<List<Integer> > res = S1.levelOrder(root);
            System.out.print("Res: [");
            for(int i=0;i<res.size();++i){
                System.out.print("[");
                for(int j=0;j<res.get(i).size();++j){
                    System.out.print(res.get(i).get(j)+",");
                }
                System.out.println("],");
            }
            System.out.println("]");
        }
    }
    private static TreeNode construct(int[] nums){
        List<TreeNode> nodes = new ArrayList<>();
        for(int i : nums){
            if(i!=-1) nodes.add(new TreeNode(i));
            else nodes.add(null);
        }
        TreeNode root = nodes.get(0);
        int childI = 1;
        for(int i=0;i<nodes.size();++i){
            TreeNode cur = nodes.get(i);
            if(childI<nodes.size()){
                cur.left = nodes.get(childI);
                childI++;
            }
            if(childI<nodes.size()){
                cur.right = nodes.get(childI);
                childI++;
            }
        }
        return root;
    }
    private static class TreeNode{
        int val;
        TreeNode left;
        TreeNode right;
        TreeNode(){};
        TreeNode(int val){this.val = val;}
        TreeNode(int val, TreeNode left, TreeNode right){
            this.val = val;
            this.left = left;
            this.right = right;
        }
    }
    private static class Solution{
        public List<List<Integer>> levelOrder(TreeNode root) {
            if(root==null) return new ArrayList<>();
            Queue<TreeNode> Q = new LinkedList<>();
            Q.add(root);
            int size;
            List<List<Integer> > ans = new ArrayList<>();
            while(!Q.isEmpty()){
                size = Q.size();
                List<Integer> tmp = new ArrayList<>();
                while(size-->0){
                    TreeNode cur = Q.poll();
                    if(cur!=null) tmp.add(cur.val);
                    if(cur.left!=null) Q.add(cur.left);
                    if(cur.right!=null) Q.add(cur.right);
                }
                ans.add(tmp);
            }
            return ans;
        }
    }
}