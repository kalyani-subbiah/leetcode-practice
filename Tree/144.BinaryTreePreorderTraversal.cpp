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

// recursive
class Solution {
public:
    std::vector<int> preorderTraversalRecursive(TreeNode* root) {
      if(root == NULL) return;
      printf("%c ", root->val);
      preorderTraversalRecursive(root->left);
      preorderTraversalRecursive(root->right);
    }

    std::vector<int> preorderTraversalIterative(TreeNode* root) {
      std::vector<int> nodes;
      std::stack<TreeNode*> todo;
      while (root || !todo.empty())
      {
        if (root)
        {
          nodes.push_back(root->val);
          if (root->right)
          {
            todo.push(root->right);
          }
          root = root->left;
        } else
        {
          root = todo.top();
          todo.pop();
        }
      }
    };

    std::vector<int> preorderTraversalMorris(TreeNode* root) {
      std::vector<int> nodes;
      while (root)
      {
        if (root->left)
        {
          TreeNode* pre = root->left;
          while (pre->right && pre->right!=root)
          {
            pre=pre->right;
          }   
          if (!pre->right)
          {
            pre->right = root;
            nodes.push_back(root->val);
            root=root->left;
          }     
       } 
      };
    };
};