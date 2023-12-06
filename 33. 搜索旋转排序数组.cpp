/*
题目来源：
https://leetcode.cn/problems/search-in-rotated-sorted-array/description/
解答：
https://leetcode.cn/problems/search-in-rotated-sorted-array/solutions/5906/ji-jian-solution-by-lukelee/
https://leetcode.cn/problems/search-in-rotated-sorted-array/solutions/22068/ji-bai-liao-9983de-javayong-hu-by-reedfan/
https://leetcode.cn/problems/search-in-rotated-sorted-array/solutions/577298/shua-chuan-lc-yan-ge-ologn100yi-qi-kan-q-xifo/
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while(left <= right){
            int mid = left + (right - left)/2;
            if(nums[mid] == target){
                return mid;
            }
            if(nums[left] <= nums[mid]){
                if(target >= nums[left] && target < nums[mid]){
                    right = mid - 1;
                }else{
                    left = mid + 1;
                }
            }else{
                if(target > nums[mid] && target <= nums[right]){
                    left = mid + 1;
                }else{
                    right = mid - 1;
                }
            }
        }
        return -1;
    }
};

/*
找到反转点 
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n - 1; 
        while(l < r){
            int mid = l + r + 1 >> 1;
            if(nums[mid] >= nums[0]){
                l = mid;
            }
            else r = mid - 1;
        }
        if(target >= nums[0]){
            l = 0;
        }
        else{
            l = l + 1;
            r = n - 1;
        }
        while(l < r){
            int mid = l + r >> 1;
            if(nums[mid] >= target){
                r = mid;
            }
            else l = mid + 1;
        }
        return (nums[r] == target ? r : -1);
    }
};
