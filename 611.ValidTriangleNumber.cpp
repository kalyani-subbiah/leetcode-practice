#include <vector>

class Solution {
public:
    int triangleNumber(std::vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int result = 0;
        int size = nums.size();
        for (int k=2; k < size; k++)
        {
          int i = 0;
          int j = k-1;
          while (i < j)
          {            
            if (nums[i]+nums[j]>nums[k])
            {
              result += j-i;
              j--;
            }
            else
            {
              i++;
            }

          }
        }
        return result;
    }
};
