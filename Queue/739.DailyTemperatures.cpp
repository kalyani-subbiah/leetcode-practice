/*
739. Daily Temperatures
Given an array of integers temperatures represents the daily temperatures, return an array answer such that answer[i] is the number of days you have to wait after the ith day to get a warmer temperature. If there is no future day for which this is possible, keep answer[i] == 0 instead.

Example 1:

Input: temperatures = [73,74,75,71,69,72,76,73]
Output: [1,1,4,2,1,1,0,0]
Example 2:

Input: temperatures = [30,40,50,60]
Output: [1,1,1,0]
Example 3:

Input: temperatures = [30,60,90]
Output: [1,1,0]
*/

#include <vector>
#include <stack>

// Solution 1. Brute Force
class Solution {
  public:
  std::vector<int> dailyTemperatures(std::vector<int>& T) {
    std::vector<int> ans(T.size());
    for (int i = 0; i < T.size(); i++)
      for (int j = i+1; j < T.size(); j++)
        if(T[j] > T[i])
          ans[i] = j - i;
    return ans;
  }
};

// Solution 2: Decreasing Monotonic Stack
class Solution {
    public:
    std::vector<int> dailyTemperatures(std::vector<int>& T) 
    {
        std::vector<int> ans(T.size());
        std::stack<int> s;
        for (int i = 0; i < T.size(); i++)
        {
          while (!s.empty() && (T[s.top()] < T[i]))
          {
            s.pop();
            ans[s.top()] = i - s.top();
          }
        s.push(i);
        }
        return ans;  
    };
};

// Solution 3: 
class Solution {
  public:
    std::vector<int> dailyTemperatures(std::vector<int>& T) 
    {
      std::stack<int> s;
      std::vector<int> ans(T.size());
      for (int cur = T.size() - 1; cur >= 0; cur--)
      {
        // pop till current temp > stack top's temp. 
        while (s.size() and T[s.top()] <= T[cur]) s.pop();
        ans[cur] = s.empty()? 0 : s.top() - cur;
        s.push(cur);
      }
      return ans;
    }
};

// Space Optimized version
class Solution {
  public:
  std::vector<int> dailyTemperatures(std::vector<int>& T) {
    std::vector<int> ans(T.size());
    for(int n = T.size(), cur = n-2; cur >= 0; cur--) {
      int next = cur + 1;                         // start at next day & iterate till you find next warmer day (NWD)
      while(next < n && T[next] <= T[cur])        // jump till you reach NWD
          next += ans[next] ? ans[next] : n;      // ?: operator just to make sure that if we reach ans[next], we know NWD doesnt exist, so jump direct to end
      if(next < n) ans[cur] = next-cur;           // if next > n, NWD doesnt exist. Otherwise, assign distance to NWD
    }
    return ans;
  }
};
