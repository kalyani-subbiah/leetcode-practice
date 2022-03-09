// two conditions
// all kids get at least one candy
// children with a higher rating get more candy than their neighbors
// Return the minimum number of candies you need to have to distribute the
// candies to the children

// size of array 
// take subsets of 3 
// four possibilities: a < b < c =  [1,2,3]
// a > b > c = [3,2,1]
// a < b > c = 1 = [1,2,1]
// a > b < c = 2 = [2,1,2]
// or go item by item

#include <vector>
#include <numeric>

class Solution {
public:
  int candy(vector<int> &ratings)
  {
    int size=ratings.size();
    if(size<=1)
      return size;
    vector<int> num(size,1);
    for (int i = 1; i < size; i++)
    {
      if(ratings[i]>ratings[i-1])
        num[i]=num[i-1]+1;
    }
    for (int i= size-1; i>0 ; i--)
    {
      if(ratings[i-1]>ratings[i])
        num[i-1]=max(num[i]+1,num[i-1]);
    }
    int result=0;
    for (int i = 0; i < size; i++)
    {
      result+=num[i];
      // cout<<num[i]<<" ";
    }
    return result;
 }

    }
};
