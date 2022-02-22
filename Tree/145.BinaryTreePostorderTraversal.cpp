#include <cstddef>
#include <vector>

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
    std::vector<int> postOrderTraversal(TreeNode* root) {
      if(root == NULL) return;
      postOrderTraversal(root->left);
      postOrderTraversal(root->right);
      printf("%c ", root->val);
    }
};