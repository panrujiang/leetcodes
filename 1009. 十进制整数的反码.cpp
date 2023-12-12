/*
��Ŀ��Դ��
https://leetcode.cn/problems/complement-of-base-10-integer/description/
���
https://leetcode.cn/problems/complement-of-base-10-integer/solutions/24424/liang-chong-fang-fa-by-keyway1984-2/
*/

/*
��1ȥ������ȡ�� 
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
��������� ��101����Ҫ�ҵ�1000��Ȼ��1000 - 1 - 101 
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
������476�ϣ�n����ֵ����ˣ�ͬ���ķ����ͻᵼ��ʱ�����ƴ��󣬵���int �ĳ�long long�����ֹ��� 
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
