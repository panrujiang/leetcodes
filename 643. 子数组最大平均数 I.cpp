/*
��Ŀ��Դ��
https://leetcode.cn/problems/maximum-average-subarray-i/description/
���
https://leetcode.cn/problems/maximum-average-subarray-i/solutions/590403/hua-dong-chuang-kou-luo-ti-han-mo-ban-by-buo3/
https://www.bilibili.com/video/BV1dY4y1m7YB?p=16&spm_id_from=pageDriver&vd_source=bb4b48d8c0acdd7bc58973f8e38ef55a
*/

/*
˫ָ��Ľⷨ 
*/
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double maxAvg = 0, sum = 0;
        for(int i = 0; i < k; i ++){
            sum += nums[i];
        }
        maxAvg = sum;
        int left = 0, right = k;
        while(right  < nums.size()){
            sum +=  nums[right] - nums[left];
            maxAvg = max(maxAvg, sum);
            right ++;
            left ++;
        }
        return maxAvg / k;
    }
};
/*
ǰ׺�͵Ľⷨ 
*/
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        vector<int> pre(nums.size() + 1);
        for(int i = 0; i < nums.size(); i ++){
            pre[i + 1] = pre[i] +  nums[i];
        }
        int maxSum = INT_MIN;
        for(int i = 0, j = k; j < pre.size(); i ++, j ++){
            maxSum = max(maxSum, pre[j] - pre[i]);
        }
        return maxSum * 1.0  / k;
    }
};
