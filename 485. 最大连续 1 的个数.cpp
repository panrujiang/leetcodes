/*
问题来源：
https://leetcode.cn/problems/max-consecutive-ones/description/
解答：
https://leetcode.cn/problems/max-consecutive-ones/solutions/603700/zui-da-lian-xu-1de-ge-shu-by-leetcode-so-252a/
*/

/*
我的低端解法 
*/
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0, length = nums.size();
        for(int i = 0; i < length; i ++){
            for(int j = i; j < length; j ++){
                if(nums[j] == 0){
                    break;
                }
                ans = max(ans, j - i + 1);
            }
        }
        return ans;
    }
};

/*
官方只需一次遍历即可 
*/
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxCount =0, count = 0;
        for(int i = 0; i < nums.size(); i ++){
            if(nums[i] == 1){
                count ++;
            }else{
                maxCount = max(maxCount, count);
                count = 0;
            }
        }
        maxCount = max(maxCount, count);
        return maxCount;
    }
};
