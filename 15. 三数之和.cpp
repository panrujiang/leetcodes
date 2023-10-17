/*
问题来源：
https://leetcode.cn/problems/3sum/description/
解答：
https://programmercarl.com/0015.%E4%B8%89%E6%95%B0%E4%B9%8B%E5%92%8C.html#%E6%80%9D%E8%B7%AF 
*/

/*
双指针法，用一个i对整个数组遍历 ，然后left和right向中间靠拢 
*/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        //对数组排序 
        sort(nums.begin(),nums.end());
        for(int i =0; i < nums.size(); i ++){
            if(nums[i] > 0){
                return result;
            }
    		//对a去重 
            if(i > 0 &&nums[i] == nums[i - 1]){
                continue;
            }
            int left = i + 1;
            int right = nums.size() - 1;
            while(left < right){
                if(nums[i] + nums[left] + nums[right] > 0){
                    right --;
                }else if(nums[i] + nums[left] + nums[right] < 0){
                    left ++;
                }else{
                    result.push_back(vector<int>{nums[i], nums[left], nums[right]});
                    //只有找到了符合题目要求的数字，才有必要对b,c去重 
                    while(left < right && nums[left] == nums[left + 1]) left ++;
                    while(left < right && nums[right] == nums[right - 1]) right --;

                    right --;
                    left ++;
                }
            }
        }
        return result;
    }
};
