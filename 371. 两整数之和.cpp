/*
��Ŀ��Դ��
https://leetcode.cn/problems/sum-of-two-integers/description/
���
https://leetcode.cn/problems/sum-of-two-integers/solutions/1017749/gong-shui-san-xie-shi-yong-wei-yun-suan-4hpb7/
*/

/*
λ���� 
*/
class Solution {
public:
    int getSum(int a, int b) {
        int ans = 0;
        for(int i = 0, t = 0; i < 32; i ++){
            int u1 = (a >> i) & 1, u2 = (b >> i) & 1;
            if(u1 == 1 && u2 == 1){
                ans |= (t << i);
                t = 1;
            }else if(u1 == 1 || u2 == 1){
                ans |= ((1 ^ t) << i);
            }else{
                ans |= (t << i);
                t = 0;
            }
        }
        return ans;
    }
};

/*
�ݹ鷨 
*/
class Solution {
public:
    int getSum(int a, int b) {
        return b == 0 ? a : getSum(a ^ b, (a & b) << 1);
    }
};
