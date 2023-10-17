/*
问题来源：
https://leetcode.cn/problems/count-number-of-pairs-with-absolute-difference-k/description/
*/
/*
用哈希表记录之前出现过的数字次数，然后遍历，判断要查找的数字是否不合规，出现的次数 
*/
class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        int record[101] ={0};
        int ans = 0;
        for(int i =0; i < nums.size(); i ++){
            int x = nums[i] + k;
            if(x > 0 && x < 101){
                ans += record[x];
            }
            x = nums[i] - k;
            if(x > 0 && x < 101){
                ans += record[x];
            }
            record[nums[i]] ++;
        }
        return ans;
    }
};
