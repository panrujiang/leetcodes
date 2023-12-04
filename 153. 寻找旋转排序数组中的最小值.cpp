/*
题目来源：
https://leetcode.cn/problems/find-minimum-in-rotated-sorted-array/description/
解答：
https://www.bilibili.com/video/BV1nt4y1b7pw/?spm_id_from=333.999.0.0&vd_source=bb4b48d8c0acdd7bc58973f8e38ef55a
*/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int min = INT_MAX;
        for(int i =0; i < nums.size(); i++){
            min = min < nums[i] ? min:nums[i];
        }
    return min;
    }
};
