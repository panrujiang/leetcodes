/*
��Ŀ��Դ��
https://leetcode.cn/problems/add-two-integers/description/
���
https://leetcode.cn/problems/add-two-integers/solutions/2394899/python3javacgorust-yi-ti-shuang-jie-shi-k0rbl/
*/

/*
λ����ķ��� YYDS 
*/
class Solution {
public:
    int sum(int num1, int num2) {
        while(num2){
            unsigned int carry = (unsigned int) (num1 & num2) << 1;
            num1 ^= num2;
            num2 = carry;
        }
        return num1;
    }
};
