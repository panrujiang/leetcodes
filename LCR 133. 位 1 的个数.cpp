/*
��Ŀ��Դ��
https://leetcode.cn/problems/er-jin-zhi-zhong-1de-ge-shu-lcof/description/
���
https://www.bilibili.com/video/BV1da411M798?p=23&spm_id_from=pageDriver&vd_source=bb4b48d8c0acdd7bc58973f8e38ef55a
*/

/*
ֱ������ 
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
��������ܶ������ڵ���������һ�º������0 
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
