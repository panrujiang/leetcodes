/*
题目来源：
https://leetcode.cn/problems/concatenation-of-array/description/
解答：
https://www.bilibili.com/video/BV1da411M798?p=30&vd_source=bb4b48d8c0acdd7bc58973f8e38ef55a

*/

/*
新建了vector 
*/

class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> ans(2 * nums.size());
        for(int i = 0 ; i < nums.size(); i ++){
            ans[i] = nums[i];
            ans[i + nums.size()] = nums[i];
        }
        return ans;
    }
};

/*
英雄哪里出来的算法 
*/

class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i ++){
            nums.push_back(nums[i]);
        }
        return nums;
    }
};


