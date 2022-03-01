#include <vector>
#include <queue>
#include <utility>

class Solution {
public:
  typedef std::pair< int,  std::vector<int> > tuple;
    std::vector< std::vector<int> > kSmallestPairs(std::vector<int>& nums1, std::vector<int>& nums2, int k) {
      std::priority_queue<std::vector<int>, std::vector<std::vector<int> >, std::greater<int> > minheap;

      for (int i = 0; i<nums1.size(); i++)
      {
        for (int j = 0; j<nums1.size(); j++)
        {
          int sum = nums1[i] + nums2[j];
          std::vector<int> list;
          list.push_back(sum);
          list.push_back(nums1[i]);
          list.push_back(nums2[i]);
          minheap.push(list);
        }
      }

      std::vector<std::vector<int> > result;

      while (!minheap.empty())
      {
        std::vector<int> front = minheap.top();
        std::vector<int> tup;
        tup.push_back(front[1]);
        tup.push_back(front[2]);
        minheap.pop();
        result.push_back(tup);
      }
    }
};