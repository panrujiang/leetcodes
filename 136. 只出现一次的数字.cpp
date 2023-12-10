/*
题目来源：
https://leetcode.cn/problems/single-number/description/
解答：
https://www.bilibili.com/video/BV11Y4y1q7YA?p=47&vd_source=bb4b48d8c0acdd7bc58973f8e38ef55a
*/

/*
异或的方法 
*/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        for(int i = 1; i < nums.size(); i ++){
            nums[0] ^= nums[i];
        }
        return nums[0];
    }
};
