function subarraysDivByK(nums: number[], k: number): number {
    // count of non-empty sub arrays
    // that have a sum
    // divisible by k

    // input array
    // calculate prefix sum
    // num[i]
    // (a % k + k) % k
    // prefix[0] = 0
    // hash.set(0, 1)
    // m = ( (prefix[i-1] + num[i] ) % k + k) % k
    // ans += hash.get(m)
    // hash.set(m, hash.get(m) + 1)
    // ret ans

    const lookup = new Map<number, number>()
    let ans = 0
    let prefix = 0

    lookup.set(0, 1)
    const n = nums.length;
    for (let i=0; i<n; i++) {
        prefix = ( (prefix + nums[i] ) % k + k) % k
        const curr = lookup.get(prefix) ?? 0

        ans += curr
        lookup.set(prefix, curr + 1)
    }

    return ans

    // [x,x,x,x,x]


    // build a prefix sum array of entries
    //   [4,5,0,-2,-3,1]
    //  0,4,9,9, 7, 4,5
    //    4,4,4, 2, 4,0
    //  
    // 0 - empty state
    // 4 
    // 9 % 5 =  4
    // 9 4
    // 7 2
    // 4 4
    // 5 0


    // 0 3 4
    // (0, 3), (0,4), (3,4), (3, 0), (4, 0), (4, 3)
    // n * (n - 1) / 2
    // -2 % 5 = -2 + 5 = 3
    // 3 % 5
    
    // prefix[r] - prefix[l - 1] -> [l, r]
    // n % 2 == 1 -> odd
    // -5 % 2 = (-1 + 2) = 1
    // 5 % 2 = 1 + 2 = 3 % 2
    // (a % k + k) % k
    // (a + b) % k = (a % k + b % k) % k
    // (a - b) % k = (a % k - b % k + k) % k

    // (prefix[j] - prefix[i]) % k === 0
    // prefix[j] % k - prefix[i] % k == 0
    // (prefix[j] % k + k) % k == (prefix[i] % k + k) % k
    
    // (prefix[j] - prefix[i]) % k === 0

};