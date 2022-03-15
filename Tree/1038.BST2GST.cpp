#include <cstddef>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 
class Solution {
public:
  int sum;
  TreeNode* bstToGst(TreeNode* root) {
    TreeNode* current = root;
    recursiveGst(current);
    return root;
  }

  void recursiveGst(TreeNode* current) {
    if (current == NULL) return;
    recursiveGst(current->right);
    sum += current->val;
    current->val=sum;
    recursiveGst(current->left);
  }
};

