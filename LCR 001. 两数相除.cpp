/*
题目来源：
https://leetcode.cn/problems/xoh6Oh/description/
解答：
https://leetcode.cn/problems/xoh6Oh/solutions/1241948/hua-luo-yue-que-li-yong-wei-yun-suan-guo-h31x/
*/
class Solution {
    private static final int BOUND = Integer.MIN_VALUE >> 1;
    public int divide(int dividend, int divisor) {
        //int 型整数的除法只有一种情况会导致溢出，即（-2^31）/(-1)
        if(dividend == Integer.MIN_VALUE && divisor == -1){
            return Integer.MAX_VALUE;
        }
        if(dividend == 0 || divisor == 1){
            return dividend;
        }else if(divisor == -1){
            return -dividend;
        }
        int negative = 2;
        if(dividend > 0){
            negative --;
            dividend = - dividend;
        }
        if(divisor > 0){
            negative --;
            divisor = -divisor;
        }
        int result = divideCore(dividend, divisor);
        return negative == 1 ? -result : result;
    }
    private int divideCore(int dividend, int divisor){
        if(dividend == divisor){
            return 1;
        }
        int result = 0;
        int shift = getMaxShift(divisor, dividend);
        while(dividend <= divisor){
            while(dividend > (divisor << shift)){
                shift --;
            }
            dividend -= (divisor << shift);
            result += (1 << shift);
        }
        return result;
    }
    private int getMaxShift(int num, int min){
        int shift = 0;
        int temp = num;
        while(temp > min && temp >= BOUND){
            temp <<= 1;
            shift ++;
        }
        return shift;
    }
}
