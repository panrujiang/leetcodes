/*
��Ŀ��Դ��
https://leetcode.cn/problems/rotate-string/description/
���
https://leetcode.cn/problems/rotate-string/solutions/61978/c-yi-xing-ti-jie-by-da-li-wang-4/
*/

/*
����ת����ַ�����������Ȼ����Ѱ��
find()��������Ҳ����ַ������ͻ᷵�� string::npos
*/
class Solution {
public:
    bool rotateString(string s, string goal) {
        return s.size() == goal.size() && (goal + goal).find(s) != string::npos;
    }
};

