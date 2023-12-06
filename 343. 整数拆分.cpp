/*
题目来源：
https://leetcode.cn/problems/integer-break/description/
解答：
https://leetcode.cn/problems/integer-break/solutions/29098/343-zheng-shu-chai-fen-tan-xin-by-jyd/
https://programmercarl.com/0343.%E6%95%B4%E6%95%B0%E6%8B%86%E5%88%86.html#%E6%80%9D%E8%B7%AF
*/
/*
数学方法，3 
*/
class Solution {
public:
    int integerBreak(int n) {
        if(n <= 3) return n -1; 
        int count, left,max;
        count = n /3;
        left = n % 3;
        if(left == 0){
            max = pow(3,count);
        }else if(left == 1){
            max = pow(3,count -1)*4;
        }else{
            max = pow(3,count)*2;
        }
        return max;
    }
};
