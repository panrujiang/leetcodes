/*
题目来源：
https://leetcode.cn/problems/minimum-moves-to-equal-array-elements/description/
解答：
https://leetcode.cn/problems/minimum-moves-to-equal-array-elements/solutions/1056443/wei-rao-li-lun-xuan-chu-n-1ge-zeng-jia-1-czj7/
*/

/*
给n-1个数加一与给一个数减一没区别 
*/ 
class Solution {
public:
    int minMoves(vector<int>& nums) {
        int l_min = INT_MAX, sum = 0;
        for(int i = 0; i < nums.size(); i ++){
            l_min = min(l_min, nums[i]);
            sum += nums[i];
        }
        return sum - l_min * nums.size();
    }
};

class Solution {
public:
    int minMoves(vector<int>& nums) {
        int small = nums[0];
        int ans = 0;
        for(auto n : nums){
            small = min(small,n);
        }
        for(auto n : nums){
            ans += n - small;
        }
        return ans;
    }
};
