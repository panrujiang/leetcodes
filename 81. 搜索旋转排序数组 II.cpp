/*
题目来源：
https://leetcode.cn/problems/search-in-rotated-sorted-array-ii/description/
解答：
https://www.bilibili.com/video/BV1nt4y1b7pw/?spm_id_from=333.999.0.0&vd_source=bb4b48d8c0acdd7bc58973f8e38ef55a
https://leetcode.cn/problems/search-in-rotated-sorted-array-ii/solutions/22056/zai-javazhong-ji-bai-liao-100de-yong-hu-by-reedfan/
https://leetcode.cn/problems/search-in-rotated-sorted-array-ii/solutions/705486/gong-shui-san-xie-xiang-jie-wei-he-yuan-xtam4/
*/

/*
先排序，再二分法 
*/
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int left = 0, right = nums.size() - 1;
        while(left <= right){
            int mid = left + (right - left)/2;
            if(nums[mid] == target){
                return true;
            }else if(nums[mid] > target){
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }
    return false;
    }
};

/*
有重复数字的处理方法 
*/
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int size = nums.size();
        int left = 0, right = size - 1;
        while(left <= right){
            int mid = left + (right - left)/2;
            if(nums[mid] == target){
                return true;
            }
            if(nums[left] == nums[mid]){
                left ++;   
                continue;
            } 
            if(nums[left] <= nums[mid]){
                if(nums[mid] > target && target >= nums[left]){
                    right = mid - 1;
                }else{
                    left = mid + 1;
                }
            }
            if(nums[right] >= nums[mid]){
                if(nums[mid] < target && target <= nums[right]){
                    left = mid + 1;
                }else{
                    right = mid - 1;
                }
            }
        }
        return false;
    }
};
