/*
题目来源：
https://leetcode.cn/problems/er-jin-zhi-zhong-1de-ge-shu-lcof/description/
解答：
https://www.bilibili.com/video/BV1da411M798?p=23&spm_id_from=pageDriver&vd_source=bb4b48d8c0acdd7bc58973f8e38ef55a
*/

/*
直观做法 
*/
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while(n){
            count += n & 1;
            n >>= 1;
        }
        return count;
    }
};
/*
这个方法很顶，相邻的两个数与一下后面会变成0 
*/
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while(n){
            n &= (n - 1);
            count ++;
        }
        return count;
    }
};
