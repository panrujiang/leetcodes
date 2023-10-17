/*
问题来源：
https://leetcode.cn/problems/4sum/description/
解答：
https://www.programmercarl.com/0018.%E5%9B%9B%E6%95%B0%E4%B9%8B%E5%92%8C.html#%E6%80%9D%E8%B7%AF 
*/

/*
类似三数之和，只不过这里用两层循环，两个指针 
*/
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int left, right;
        for(int i =0; i < nums.size(); i ++){
        	//如果target是负数，不能提前终止，如target=-9，nums[0] = -8,nums[1] = -3,nums[2] = 0,nums[3] = 2,即使nums[0] > -9,但还是存在的 
            if(nums[i] > target && nums[i] > 0){
                return ans;
            }
            if(i > 0 && nums[i] == nums[i - 1]){
                continue;
            }
            //这里只能是break，而不能是return 
            for(int j = i + 1; j < nums.size(); j ++){
                if(nums[j] + nums[i] > target && nums[j] + nums[i] >= 0){
                    break;
                }
                if((j - 1) > i &&nums[j] == nums[j - 1]){
                    continue;
                }
                left = j + 1;
                right = nums.size() - 1;
            while(left < right){
            	//加了long是怕溢出 
                if((long)nums[i] + nums[j] + nums[left] + nums[right] > target){
                    right --;
                }else if((long)nums[i] + nums[j] + nums[left] + nums[right] < target){
                    left ++;
                }else{
                    ans.push_back({nums[i],nums[j],nums[left],nums[right]});
                    //这里去重不是加减2是因为不管重不重，left都要++,right都要-- ，只要将它们移到最后一个重的位置即可 
                    while(left < right && nums[left] == nums[left + 1]) left ++;
                    while(left < right && nums[right] == nums[right - 1]) right --;
                    left ++;
                    right --;
                }
            }

            }
        }
        return ans;
    }
};
