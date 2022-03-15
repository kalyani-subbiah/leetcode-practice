import java.util.*;  

public class Permutations{
    public List<List<Integer>> permutations(int[] nums) 
    {
        List<List<Integer>> list = new ArrayList<>();
        Arrays.sort(nums);
        backtrack(list, new ArrayList<>(), nums);
        return list;
    }
    
    private void backtrack(List<List<Integer>> list , List<Integer> tempList, int [] nums)
    {
      if (tempList.size() == nums.length)
      {
        list.add(new ArrayList<>(tempList));
      } else {
        
        for(int i = 0; i < nums.length; i++)
        {
          if (tempList.contains(nums[i])) continue;
          tempList.add(nums[i]);
          backtrack(list, tempList, nums);
          tempList.remove(tempList.size() - 1);
        }
      }
    }
    public static void main (String[] args) {
        List<List<Integer>> list = new ArrayList<>();
        int[] nums = new int[]{1,2,3,4,5};
        Permutations s = new Permutations();
        list = s.permutations(nums);
    }
}


