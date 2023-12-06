/*
问题来源：
https://leetcode.cn/problems/divide-array-into-equal-pairs/description/
解答：
https://www.bilibili.com/video/BV1Ra41177RB/?spm_id_from=333.788&vd_source=bb4b48d8c0acdd7bc58973f8e38ef55a
*/

/*
双指针法 
*/
class Solution {
public:
    bool divideArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(int i =0; i < nums.size();){
            int j =i;
            while(j < nums.size() && nums[j] == nums[i]) j ++;
            if((j - i)%2) return false;
            i = j;
        }
        return true;
    }
};
