class Solution {
  private int res;
  public class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode() {}
    TreeNode(int val) { this.val = val; }
    TreeNode(int val, TreeNode left, TreeNode right) {
    this.val = val;
    this.left = left;
    this.right = right;
      }
    }
   
  public int countPairs(TreeNode root, int distance) {
    res = 0;
    helper(root, distance);
    return res;
  }

  private int[] helper(TreeNode node, int distance)
  {
    if (node==null) return new int[11];
    int[] left = helper(node.left, distance);
    int[] right = helper(node.right, distance);

    int[] A = new int[11];

    // node is leaf node, no child, just return
    if (node.left == null && node.right == null)
    {
      A[1] = 1;
      return A;
    }

    //find all node satisfying distance
    for (int i = 0; i <= 10; ++i)
    {
      for (int j = 0; j <= 10; ++j)
      {
        if (i+j <= distance) res += (left[i] * right[j]);
      }
    }

    for (int i = 0; i <= 9; ++i)
    {
      A[i+1] += left[i];
      A[i+1] += right[i];
    }

    return A;
  }

}

