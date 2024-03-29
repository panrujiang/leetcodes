/*
问题来源：
https://leetcode.cn/problems/kth-largest-element-in-an-array/description/
解答：
https://leetcode.cn/problems/kth-largest-element-in-an-array/solutions/307351/shu-zu-zhong-de-di-kge-zui-da-yuan-su-by-leetcode-/
*/

/*
快排 可惜有一个例子没过 
*/
class Solution {
    int quickselect(vector<int> &nums, int left, int right, int k){
        if(left == right){
            return nums[k];
        }
        int partition = nums[left], i = left, j = right;
        while(i < j){
            while(i < j && nums[j] <= partition) j --;
            while(i < j && nums[i] >= partition) i ++;
            swap(nums[i], nums[j]);
        }
            swap(nums[i], nums[left]);
        if(k <= j) return quickselect(nums, left, j, k);
        else return quickselect(nums,j + 1,right, k);
    }
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        return quickselect(nums, 0, n - 1, k - 1);
    }
};

/*
优化 
*/
class Solution {
    int quickselect(vector<int> &nums, int left, int right, int k){
        if(left == right){
            return nums[k];
        }
        //多了这两句就不会超出时间限制 
        int ridx = rand() % (right - left + 1) + left;
        swap(nums[left],nums[ridx]);
        int partition = nums[left], i = left, j = right;
        while(i < j){
            while(i < j && nums[j] <= partition) j --;
            while(i < j && nums[i] >= partition) i ++;
            swap(nums[i], nums[j]);
        }
            swap(nums[i], nums[left]);
        if(k <= j) return quickselect(nums, left, j, k);
        else return quickselect(nums,j + 1,right, k);
    }
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        return quickselect(nums, 0, n - 1, k - 1);
    }
};
