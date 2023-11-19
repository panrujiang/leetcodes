/*
题目来源：
https://leetcode.cn/problems/the-kth-factor-of-n/description/
解答：
https://www.bilibili.com/video/BV1oR4y1W79x/?spm_id_from=333.999.0.0&vd_source=bb4b48d8c0acdd7bc58973f8e38ef55a 
*/

class Solution {
public:
    int kthFactor(int n, int k) {
        int count = 0;
        for(int i = 1; i <= n; i ++){
            if(!(n%i)){
                count ++;
                if(count == k)  return i;
            }
        }
        return -1;
    }
};
