/*
题目来源：
https://leetcode.cn/problems/powx-n/description/
解答：
https://leetcode.cn/problems/powx-n/solutions/27526/qing-xi-jian-dan-de-dan-han-shu-di-gui-wu-lei-xing/
https://leetcode.cn/problems/powx-n/solutions/241471/50-powx-n-kuai-su-mi-qing-xi-tu-jie-by-jyd/
*/

/*
用递归的方法解决了幂次方 
*/
class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0) return 1;
        if(n == 1) return x;
        if(n == -1) return 1/x;
        double half = myPow(x, n/2);
        double rest = myPow(x, n % 2);
        return rest * half * half;
    }
};

/*
二进制移位法 
*/
class Solution {
public:
    double myPow(double x, int n) {
        if(x == 0.0){
            return 0.0;
        }
        double ans = 1;
        long n_big = n;
        if(n_big < 0){
            x = 1 / x;
            n_big = - n_big; 
        }
        while(n_big){
            if(n_big & 1){
                ans *= x;
            }
            n_big >>= 1;
            x *= x;
        }
        return ans;
    }
};
