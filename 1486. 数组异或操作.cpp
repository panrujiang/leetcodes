/*
��Ŀ��Դ��
https://leetcode.cn/problems/xor-operation-in-an-array/description/
���
https://leetcode.cn/problems/xor-operation-in-an-array/solutions/762179/gong-shui-san-xie-yi-ti-shuang-jie-mo-ni-dggg/
*/

/*
ģ�ⷨ ������������󣬻ᳬ��ʱ������ 
*/
class Solution {
public:
    int xorOperation(int n, int start) {
        int ans = 0;
        for(int i = 0; i < n; i ++){
            ans ^= (start + 2 * i);
        }
        return ans;
    }
};


/*
��Ҷ����ѧ��� ���ҵ��뷨��������ÿһλ����ӣ��޽�λ 

cal �������������ֵ����
4i��(4i+1)��(4i+2)��(4i+3)=0
0^1^2^3^4^5^6^7������x = 6, 0^1^2^3һ�飬ֵΪ0,0^4 = 4,4^5 = 1,����4��5�������λ��ͬ������λ����ͬ������4^5 = 1;1^6 �൱�ڸ�6 ����1��
7 ^ 7 = 0;
x �� x �� y = y����(s ^ (s+1) ^ (s+2) ^ ���� ^ (s+n-1)) = 
��1 ^ 2 ^ 3 ^ ���� ^ s - 1)^(1 ^ 2 ^ 3 ^ ���� ^ s - 1 ^ s ^ (s+1) ^ (s+2) ^ ���� ^ (s+n-1))

*/
class Solution {
private:
    int cal(int x){
        if(x % 4 == 0) return x;
        else if(x % 4 == 1) return 1;
        else if(x % 4 == 2) return x + 1;
        else return 0;
    }
public:
    int xorOperation(int n, int start) {
        int s = start >> 1;
        int prefix = cal(s - 1) ^cal(s + n - 1);
        int last = n & start & 1;
        int ans = prefix << 1 | last;
        return ans;
    }
};


