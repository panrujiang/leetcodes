/*
题目来源：
https://leetcode.cn/problems/recursive-mulitply-lcci/description/
解答：
https://www.bilibili.com/video/BV1da411M798?p=12&spm_id_from=pageDriver&vd_source=bb4b48d8c0acdd7bc58973f8e38ef55a
https://leetcode.cn/problems/recursive-mulitply-lcci/solutions/130031/java-jiu-shi-bu-yong-di-gui-by-npe_tle/
https://leetcode.cn/problems/recursive-mulitply-lcci/solutions/1365611/yi-xing-by-warrenes-hsrm/
*/



/*
递归法，两个数字都是正整数 
*/
class Solution {
public:
    int multiply(int A, int B) {
        int MAX = max(A,B);
        int MIN = min(A,B);
        if( MIN == 0){
            return 0;
        }
        return multiply(MIN - 1, MAX) + MAX;
    }
};


/*
位移操作 ，base要设置为long long类型 
*/
class Solution {
public:
    int multiply(int A, int B) {
        long long base = A;
        int result = 0;
        while(B){
            if(B & 1){
                result += base;
            }
            base *= 2;
            B >>= 1;
        }
    return result;
    }
};
/*
这种解法实质上也是位移操作，但代码量少了很多 
*/
class Solution {
public:
    int multiply(int A, int B) {
        return B?multiply(A<<1,B>>1)+(B&1?A:0):0;
    }
};
