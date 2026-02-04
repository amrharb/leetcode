class Solution:
    def maxSumTrionic(self, nums: List[int]) -> int:
        n = len(nums)
        NINF = -(10**18)
        
        up1 = NINF
        down = NINF
        up2 = NINF
        
        ans = NINF

        for i in range(1, n):
            curr = nums[i]
            prev = nums[i-1]
            prev_up1, prev_down, prev_up2 = up1, down, up2
            
            if curr > prev:
                up1 = prev + curr
                if prev_up1 != NINF:
                    up1 = max(up1, prev_up1 + curr)
                
                down = NINF
                
                up2 = NINF
                if prev_up2 != NINF:
                    up2 = prev_up2 + curr
                if prev_down != NINF:
                    if up2 == NINF:
                        up2 = prev_down + curr
                    else:
                        up2 = max(up2, prev_down + curr)
                    
            elif curr < prev:
                up1 = NINF
                down = NINF
                if prev_down != NINF:
                    down = prev_down + curr
                if prev_up1 != NINF:
                    if down == NINF:
                        down = prev_up1 + curr
                    else:
                        down = max(down, prev_up1 + curr)
                    
                up2 = NINF
            else:
                up1 = NINF
                down = NINF
                up2 = NINF
            
            if up2 != NINF:
                ans = max(ans, up2)

        return ans if ans != NINF else -1