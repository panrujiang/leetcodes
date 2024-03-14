/*
��Ŀ��Դ��
https://leetcode.cn/problems/jewels-and-stones/description/
���
https://leetcode.cn/problems/jewels-and-stones/solutions/2356253/ben-ti-zui-you-jie-xian-xing-shi-jian-ch-ddw3/
*/

/*
�ҵ����� 
*/
class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int ans = 0;
        for(char& ch : stones){
            size_t pos = jewels.find(ch);
            if(pos != std::string::npos){
                ans ++;
            }
        }
        return ans;
    }
};
/*
����Ľⷨ 
*/
class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        long long mask = 0;
        for(char c : jewels){
            mask |= 1LL << (c & 63);
        }
        int ans = 0;
        for(char c : stones){
        	//&1�ǽ�����λ���㣬�������λ 
            ans += mask >> (c & 63) & 1;
        }
        return ans;
    }
};

// ȫ��Ӣ����ĸ��Сдһ�� 52 ��
// �������� 64 λ long long �Ķ�����λ����ϣ
// ��ν� 52 ����ĸΨһ��ӳ�䵽ÿ��������λ��
// (c & 63) ֻȡ�ַ�c(ASCII ��)�����Ƶĺ���λ���ñ�ȡ��������൱�� (c % 64)
// ��� 'A' ~ 'Z' ��ӳ�䵽 1 ~ 26��'a' ~ 'z' ��ӳ�䵽 33 ~ 58
// ��ӳ���ܱ�֤ÿ����ĸ����Ψһֵ�������ϣ��ͻ
// �� (c & 63) �������ֵΪ 63����λ����Ҳ������� long long ��Χ
// ��ʵ���� (c & 63) ���Ҳ���� 58���� ('z' % 64)��������λ�������
// �ܽ᣺(c & 63) �����Ψһӳ������⣬ͬʱ��λ������� 64 λ
// ����Ӧ������Ϊ�ַ� ��A�� �� ASCII ��Ϊ 65 > 64��65 % 64 = 1�������� 'z' % 64 = 58 < 64
// Ҳ���� (c % 64) �ܹ�ӳ�䵽 0 ~ 63 �ķ�Χ�ұ�֤Ψһӳ��
// ���԰� (c & 63) ���� (c - 64) �� (c - 'A') ��Ҳ�ǿ��Եģ�����λ�����Ч�ʸ��ߵ�
class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        long long mask = 0;
        for (char c : jewels) mask |= 1LL << (c & 63);
        int ans = 0;
        for (char c : stones) ans += mask >> (c & 63) & 1;
        return ans;
    }
};
