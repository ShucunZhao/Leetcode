package lc572SubtreeOfAnotherTree;

import java.util.Arrays;
import java.util.Scanner;
import java.util.List;
import java.util.ArrayList;

public class SolWithPreOrder {
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        Solution S1 = new Solution();
        while(true){
            System.out.println("Enter root tree:");
            String R = scan.nextLine();
            if(R.equals("q")) break;
            System.out.println("Enter sub tree:");
            String S = scan.nextLine();
            if(S.equals("q")) break;
            R = R.substring(1, R.length()-1);
            S = S.substring(1, S.length()-1);
            TreeNode root = null;
            TreeNode subRoot = null;
            if(!R.equals("")){
                String[] Rs = R.split(",");
                int[] numsR = new int[Rs.length];
                for(int i=0;i<Rs.length;++i){
                    if(Rs[i].equals("null")) numsR[i] = -1;
                    else numsR[i] = Integer.parseInt(Rs[i].trim());
                }
                root = construct(numsR);
            }
            if(!S.equals("")){
                String[] Ss = S.split(",");
                int[] numsS = new int[Ss.length];
                for(int i=0;i<Ss.length;++i){
                    if(Ss[i].equals("null")) numsS[i] = -1;
                    else numsS[i] = Integer.parseInt(Ss[i].trim());
                }
                subRoot = construct(numsS);
            }
            System.out.println("Res: "+S1.isSubtree(root, subRoot));
        }
    }
    private static TreeNode construct(int[] nums){
        List<TreeNode> nodes = new ArrayList<>();
        for(int i : nums){
            if(i==-1) nodes.add(null);
            else nodes.add(new TreeNode(i));
        }
        TreeNode root = nodes.get(0);
        int childI = 1;
        for(int i=0;i<nodes.size();++i){
            TreeNode cur = nodes.get(i);
            if(childI<nodes.size()&&cur!=null) cur.left = nodes.get(childI++);
            if(childI<nodes.size()&&cur!=null) cur.right = nodes.get(childI++);
        }
        return root;
    }
    private static class TreeNode{
        int val;
        TreeNode left;
        TreeNode right;
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

    private static class Solution{
        public boolean checkSame(TreeNode a, TreeNode b){
            if(a==null&&b==null) return true;
            else if(a==null&&b!=null) return false;
            else if(a!=null&&b==null) return false;
            else if(a.val!=b.val) return false;
            return checkSame(a.left, b.left)&&checkSame(a.right, b.right);
        }
        public boolean isSubtree(TreeNode root, TreeNode subRoot) {
            if(root==null&&subRoot==null) return true;
            if(root==null&&subRoot!=null) return false;
            boolean M = checkSame(root, subRoot);
            boolean L = isSubtree(root.left, subRoot);
            boolean R = isSubtree(root.right, subRoot);
            return M||L||R;
        }
    }
}

