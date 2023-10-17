/*
题目来源：
https://leetcode.cn/problems/number-of-good-pairs/description/ 
*/
/*
方法为对于j，在（0，j - 1）中遍历，向前遍历，在数组中看看对应的数据有多少个 
record数组记录着数字的个数，ans记录着好数对的数目 
*/
class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int record[101] = {0};
        int ans = 0;
        for(int i =0; i < nums.size(); i ++){
                ans += record[nums[i]];
                record[nums[i]] ++;
        }
        return ans;
    }
};
