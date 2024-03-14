/*
问题来源：
https://leetcode.cn/problems/binary-search/description/
*/

/*
分而治之 
*/
class Solution {
private:
    int dfs(vector<int> &nums, int target, int i, int j){
        if(i > j){
            return -1;
        }
        int middle = i + (j - i) / 2;
        if(nums[middle] > target){
            return dfs(nums, target, i, middle - 1);
        }else if(nums[middle] < target){
            return dfs(nums, target, middle + 1, j);
        }else{
            return middle;
        }
    }
public:
    int search(vector<int>& nums, int target) {
        int i = 0, j = nums.size() -1;
        return dfs(nums, target, i, j);
    }
};

/*
二分法 
*/
class Solution {
public:
    int search(vector<int>& nums, int target) {
            int left = 0,right = nums.size();
            while(left < right){
                 int mid = left + (right - left)/2;
                if(nums[mid] < target)
                left = mid + 1;
            else if(nums[mid] > target)
                right = mid;
            else
                return mid;
            }
            return -1;
    }
};
