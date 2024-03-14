/*
问题来源：
https://leetcode.cn/problems/max-consecutive-ones-iii/description/
解答：
https://blog.csdn.net/qq_75270497/article/details/136607537
*/

/*
双指针 
*/
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left =0, right = 0;
        int ans = 0;
        while(right < nums.size()){
            if(nums[right] == 0){
                k --;
                if(k < 0){
                    while(k != 0){
                        if(nums[left] == 0){
                            k ++;
                            left ++;
                        }else{
                            left ++;
                        }
                    }
                } 
            }
            ans = max(ans, right - left + 1);
            right ++;
        }
        return ans;
    }
};
