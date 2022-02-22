#include <cstddef>
#include <vector>
#include <stack>
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
    std::vector<int> inorderTraversal(TreeNode* root) {
      if(root == nullptr) return;
      inorderTraversal(root->left);
      printf("%c ", root->val);
      inorderTraversal(root->right);
    }

      std::vector<int> preorderTraversalIterative(TreeNode* root) {
        std::vector<int> nodes;
        std::stack<TreeNode*> todo;
        while (root || !todo.empty())
        {
          if (root)
          {
            
            if (root->right)
            {
              todo.push(root->right);
            }
            nodes.push_back(root->val);
            root = root->left;
          } else
          {
            root = todo.top();
            todo.pop();
          }
        }
      };
};
