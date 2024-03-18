/*
原题：
https://leetcode.cn/problems/three-steps-problem-lcci/description/
*/

/*
Hello算法 ，三个变量即可，滚动，自己画一下 
*/
class Solution {
public:
    int waysToStep(int n) {
        if(n == 1 || n == 2){
            return n;
        }
        if(n == 3){
            return 4;
        }
        long a = 1, b = 2, c = 4;
        for(int i = 4; i <= n; i ++){
            long tmp = (a + b + c) % 1000000007;
            a = b;
            b = c; 
            c = tmp;
        }
        return (int)c;
    }
};

