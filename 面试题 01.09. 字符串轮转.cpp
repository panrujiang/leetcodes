/*
������Դ��
https://leetcode.cn/problems/string-rotation-lcci/description/
���

*/

/*
��������ת�����⣬һ����������·����һ�ֽ���ת���ַ������ӣ������ͻ����δ��ת֮ǰ���ַ�����Ȼ��ʹ��find������
�ڶ��ַ�����������ת����Ϊ�߽磬�ȷ�תǰһ���֣��ٷ�ת��һ���֣�Ȼ����ȫ����ת�������͵õ��˳�ʼ�ַ��� 
*/
class Solution {
public:
    bool isFlipedString(string s1, string s2) {
        if(s1.size() != s2.size()){
            return false;
        }
        s2 += s2;
        return s2.find(s1) != string::npos;

    }
};
