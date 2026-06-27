public class Solution {
    /*
    [-2,1,-3,4,-1,2,1,-5,4]
  [0,-2,-1,-4 ,0,-1,1,2,-3,1]
    pref[right] - pref[left - 1] left -> 0... n-1

    end - (start-1) 
    cur = 1
    max = 1
    */
    public int MaxSubArray(int[] nums) {
        var prefix = new int[nums.Length];
        var max =  int.MinValue;
        prefix[0]= nums[0];
        for(int i = 1 ; i <nums.Length; i++)
        {
            prefix[i] = nums[i] + prefix[i-1];
            // pref[i + 1] = nums[i] + pref[i] 0..n-1
            // pref[i] = nums[i-1] + pref[i-1] 1..n 
        }
        var min = 0;
       for(int i = 0; i< prefix.Length; i++)
        {
           max = Math.Max(max, prefix[i] - min);
           min = Math.Min(min,prefix[i]);
        }
        return max;

    }
}