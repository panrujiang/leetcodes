/*
问题来源：
https://leetcode.cn/problems/running-sum-of-1d-array/description/
解答：
https://www.bilibili.com/video/BV1nt4y1b7pw/?vd_source=bb4b48d8c0acdd7bc58973f8e38ef55a
*/

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
         vector<int> result;
         for(int i = 0; i < nums.size(); i ++){
            if(i == 0) 
            result.push_back(nums[i]);
            else
             result.push_back(result.back() + nums[i]);
         }
         return result;
    }
};
