/*
题目来源：
https://leetcode.cn/problems/binary-subarrays-with-sum/description/
解答：
https://leetcode.cn/problems/binary-subarrays-with-sum/solutions/562198/de-liao-yi-wen-ba-qian-zhui-he-miao-sha-mqngx/
https://leetcode.cn/problems/binary-subarrays-with-sum/solutions/864533/930-he-xiang-tong-de-er-yuan-zi-shu-zu-h-w5o4/
（双指针讲很好） 
*/

/*
哈希表 + 前缀和  
哈希表用来存储前缀和的个数 
*/
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int ans = 0;
        int sum = 0;
        unordered_map <int, int> map;
        map[0] = 1;
        for(auto num : nums){
            sum += num;
            ans += map[sum - goal];
            map[sum] ++;
        }
        return ans;
    }
};

/*
双指针版本 
*/
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        int left1 = 0, left2 = 0, right = 0;
        int sum1 = 0, sum2 = 0;
        int res = 0;

        while(right < n){
            sum1 += nums[right];
            while(left1 <= right && sum1 > goal){
                sum1 -= nums[left1 ++];
            }
            sum2 += nums[right];
            while(left2 <= right && sum2 >= goal){
                sum2 -= nums[left2 ++];      
            }
            res += left2 - left1;
            right ++;
        }
        return res;
    }
};

