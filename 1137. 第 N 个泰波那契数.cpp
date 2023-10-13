/*
原题：
https://leetcode.cn/problems/n-th-tribonacci-number/description/
解答：
https://leetcode.cn/problems/n-th-tribonacci-number/solutions/921898/di-n-ge-tai-bo-na-qi-shu-by-leetcode-sol-kn16/
https://leetcode.cn/problems/n-th-tribonacci-number/solutions/922594/gong-shui-san-xie-yi-ti-si-jie-die-dai-d-m1ie/
https://leetcode.cn/problems/n-th-tribonacci-number/solutions/922594/gong-shui-san-xie-yi-ti-si-jie-die-dai-d-m1ie/
*/

/*
动态规划
*/ 
class Solution {
public:
    int tribonacci(int n) {
        if(n == 0){
            return 0;
        }
        int p = 0, q = 0, r = 0, t = 1;
        for(int i = 2; i <= n; i ++){
            p = q;
            q = r;
            r = t;
            t = p + q + r;
        }
        return t;
    }
};

