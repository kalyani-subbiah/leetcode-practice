#include <cstddef>
#include <vector>
#include <queue>

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
  std::vector< std::vector<int> > nodes;  

  void buildVectordfs(TreeNode *root, int depth)
  {
    if (root==NULL) return;
    if (nodes.size() == depth)
    {
      nodes.push_back(std::vector<int>());
    }
    nodes[depth].push_back(root->val);
    buildVectordfs(root->left, depth+1);
    buildVectordfs(root->right, depth+1);
  }

  std::vector<std::vector<int> > levelOrder(TreeNode *root) {
    buildVectordfs(root, 0);
    return nodes;
  } 
  std::vector<std::vector<int> > levelOrder(TreeNode *root) {
    std::vector<std::vector<int> >  result;
    if (!root) return result;
    std::queue<TreeNode*> q;
    q.push(root);
    q.push(NULL);
    std::vector<int> cur_vec;
    while(!q.empty()) {
        TreeNode* t = q.front();
        q.pop();
        if (t==NULL) {
            result.push_back(cur_vec);
            cur_vec.resize(0);
            if (q.size() > 0) {
                q.push(NULL);
            }
        } else {
            cur_vec.push_back(t->val);
            if (t->left) q.push(t->left);
            if (t->right) q.push(t->right);
        }
    }
    return result;
  }
};
