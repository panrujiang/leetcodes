/*
题目来源：
https://leetcode.cn/problems/maximum-subarray/
解答：
https://programmercarl.com/0053.%E6%9C%80%E5%A4%A7%E5%AD%90%E5%BA%8F%E5%92%8C.html#%E7%AE%97%E6%B3%95%E5%85%AC%E5%BC%80%E8%AF%BE
*/

/*
暴力解法 
*/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max = INT_MIN;
        int count = 0;
        for(int i =0; i < nums.size(); i ++){
            count = 0;
            for(int j = i; j < nums.size(); j ++){
                count += nums[j];
                max = max > count ? max:count;
            }
        }
    return max;
    }
};

/*
贪心算法 
*/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int result = INT32_MIN;
        int count = 0;
        for(int i = 0; i < nums.size(); i ++){
            count += nums[i];
            if(count > result){
                result = count;
            }
            if(count <= 0) count = 0;
        }
        return result;
    }
};
