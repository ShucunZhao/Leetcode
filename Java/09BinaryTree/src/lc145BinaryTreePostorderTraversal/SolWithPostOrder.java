package lc145BinaryTreePostorderTraversal;
import java.util.List;
import java.util.ArrayList;
import java.util.Scanner;

public class SolWithPostOrder {
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        Solution S1 = new Solution();
        while(true){
            System.out.println("Enter tree nodes array: ");
            String In = scan.nextLine();
            if(In.equals("q")) break;
            In = In.substring(1, In.length()-1);
            TreeNode root = null;
            if(!In.equals("")) {
                String[] InSet = In.split(",");
                int[] nums = new int[InSet.length];
                for(int i=0;i<nums.length;++i){
                    if(InSet[i].equals("null")) nums[i] = -1;
                    else nums[i] = Integer.parseInt(InSet[i]);
                }
                root = constructTree(nums);
            }
            List<Integer> res = S1.postorderTraversal(root);
            System.out.print("[");
            for(int i=0;i<res.size();++i){
                System.out.print(res.get(i)+",");
            }
            System.out.println("]");
        }
    }
    private static class TreeNode{
        int val;
        TreeNode left;
        TreeNode right;
        TreeNode(){}
        TreeNode(int val){this.val = val;}
        TreeNode(int val, TreeNode left, TreeNode right){
            this.val = val;
            this.left = left;
            this.right = right;
        }
    }
    private static TreeNode constructTree(int[] nums){
        List<TreeNode> treeSet = new ArrayList<>();
        for(int i=0;i<nums.length;++i){
            TreeNode cur = null;
            if(nums[i]!=-1) cur = new TreeNode(nums[i]);
            treeSet.add(cur);
        }
        TreeNode root = treeSet.get(0);
        int childI = 1;
        for(int i=0;i<treeSet.size();++i){
            TreeNode cur = treeSet.get(i);
            if(cur!=null){
                if(childI<treeSet.size()) cur.left = treeSet.get(childI++);
                if(childI<treeSet.size()) cur.right = treeSet.get(childI++);
            }
        }
        return root;
    }
    private static class Solution{
        public List<Integer> postorderTraversal(TreeNode root) {
            List<Integer> ans = new ArrayList<>();
            postorder(root, ans);
            return ans;
        }
        public void postorder(TreeNode root, List<Integer> ans){
            if(root==null) return;
            postorder(root.left, ans);
            postorder(root.right, ans);
            ans.add(root.val);
        }
    }
}
