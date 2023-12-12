/*
题目来源：
https://leetcode.cn/problems/complement-of-base-10-integer/description/
解答：
https://leetcode.cn/problems/complement-of-base-10-integer/solutions/24424/liang-chong-fang-fa-by-keyway1984-2/
*/

/*
用1去异或就是取反 
*/
class Solution {
public:
    int bitwiseComplement(int n) {
        if(n == 0){
            return 1;
        }
        int temp1 = 1;
        int temp2 = n;
        while(temp2 > 0){
            n ^= temp1;
            temp1 <<= 1;
            temp2 >>= 1;
        }
        return n;
    }
};


/*
反码的性质 ，101就是要找到1000，然后1000 - 1 - 101 
*/
class Solution {
public:
    int bitwiseComplement(int n) {
        if(n == 0){
            return 1;
        }
        int k = 1;
        while(1){
            if(k > n){
                break;
            }
            k <<= 1;
        }
        return k - 1 - n;
    }
};
/*
在力扣476上，n的数值变大了，同样的方法就会导致时间限制错误，但把int 改成long long类型又过了 
*/
class Solution {
public:
    int findComplement(int num) {
        long long  k = 1;
        while(1){
            if(k > num){
                break;
            }
            k <<= 1;
        }
        return k - 1 - num;
    }
};
