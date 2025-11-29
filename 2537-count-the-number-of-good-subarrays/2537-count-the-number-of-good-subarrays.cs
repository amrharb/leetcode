using System.Collections.Generic;

public class Solution {
    /*
       1 1 1 1 1
       cnt = 1 + 2 + 3 + 4 = 10
       5 3 1 4 3 2 2 4 6 7 8 9 
       cnt = 1 + 1 = 2 + 1 = 3

       abcabc
    */
    public long CountGood(int[] nums, int k) {
        
        var dict = new Dictionary<int, int>();
        var l = 0;
        long res = 0;
        long cnt = 0;
        for(int r = 0; r < nums.Length; r++)
        {
            if(!dict.ContainsKey(nums[r])) dict[nums[r]]= 0;
            cnt += dict[nums[r]];//counter of nums[r] on current subarray
            dict[nums[r]]++;
            while(cnt >= k)
            {
                res += nums.Length - r;
                dict[nums[l]]--;
                cnt -= dict[nums[l]];
                l++;
            }
        }

        return res;

    }
}
