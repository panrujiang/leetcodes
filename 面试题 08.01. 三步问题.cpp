/*
ԭ�⣺
https://leetcode.cn/problems/three-steps-problem-lcci/description/
*/

/*
Hello�㷨 �������������ɣ��������Լ���һ�� 
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

