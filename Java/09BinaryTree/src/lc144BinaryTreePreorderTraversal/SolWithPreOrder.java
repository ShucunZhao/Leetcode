package lc144BinaryTreePreorderTraversal;
import java.util.List;
import java.util.ArrayList;
import java.util.Scanner;

public class SolWithPreOrder {
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        Solution S1 = new Solution();
        while(true){
            System.out.println("Enter the node value array of binary tree: ");
            String In = scan.nextLine();
            if(In.equals("q")) break;
            In = In.substring(1, In.length()-1);
            TreeNode root = null;
            if(!In.equals("")) {
                String[] InSet = In.split(",");
                int[] nums = new int[InSet.length];
                for (int i = 0; i < nums.length; ++i) {
                    if (InSet[i].equals("null")) nums[i] = -1;
                    else nums[i] = Integer.parseInt(InSet[i]);
                }
                root = constructTree(nums);
            }
            List<Integer> ans = S1.preorderTraversal(root);
            System.out.print("Res: [");
            for(int i=0;i<ans.size();++i){
                System.out.print(ans.get(i)+",");
            }
            System.out.println("]");
        }
    }
    private static class TreeNode{
        public int val;
        public TreeNode left;
        public TreeNode right;
        TreeNode(){}
        TreeNode(int val){
            this.val = val;
        }
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
        int childIndex = 1;//We should start from 1 because the root index in treeSet array is 0;
        for(int i=0;i<treeSet.size();++i){
            if(treeSet.get(i)!=null){//KeyPoint for convert tree nodes array to binary tree structure
                if(childIndex<treeSet.size()){
                    treeSet.get(i).left = treeSet.get(childIndex++);
                }
                if(childIndex<treeSet.size()){
                    treeSet.get(i).right = treeSet.get(childIndex++);
                }
            }
        }
        return root;
    }
    private static class Solution{
        public List<Integer> preorderTraversal(TreeNode root) {
            List<Integer> ans = new ArrayList<>();
            preorder(root, ans);
            return ans;
        }
        public void preorder(TreeNode root, List<Integer> ans){
            if(root==null){
                return;
            }
            ans.add(root.val);
            preorder(root.left, ans);
            preorder(root.right, ans);
        }
    }
}
