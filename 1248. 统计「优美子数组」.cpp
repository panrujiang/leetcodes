/*
题目来源：
https://leetcode.cn/problems/count-number-of-nice-subarrays/description/
解答：
https://leetcode.cn/problems/binary-subarrays-with-sum/solutions/562198/de-liao-yi-wen-ba-qian-zhui-he-miao-sha-mqngx/
https://leetcode.cn/problems/count-number-of-nice-subarrays/solutions/213352/hua-dong-chuang-kou-qian-zhui-he-bi-xu-miao-dong-b/
*/

/*
前缀和 + 哈希表 
map[0] = 1的意思：初始化的时候奇数个数为0的时候，有一种情况，这种应该就是从0开始，最前面没有截断 
*/
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int count = 0;
        int ans = 0;
        unordered_map <int, int> map;
        map[0] = 1;
        for(auto num : nums){
            count += num % 2;
            ans += map[count - k];
            map[count] ++;
        }
        return ans;
    }
};

/*
滑动窗口，把这种结构记下来 
*/
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int left = 0, right = 0, oddCnt = 0, res = 0;
        while(right < nums.size()){
            if(nums[right ++] % 2){
                oddCnt ++;
            }
            if(oddCnt == k){
                int tmp = right;
                while(right < nums.size() && (nums[right] & 1) == 0){
                    right ++;
                }
                int rightEvenCnt = right - tmp;
                int leftEvenCnt = 0;
                while((nums[left] & 1) == 0){
                    leftEvenCnt ++;
                    left ++;
                }
                res += (leftEvenCnt + 1) * (rightEvenCnt + 1);
                left ++;
                oddCnt --;
            }
        }
        return res;
    }
};
