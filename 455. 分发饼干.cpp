/*
��Ŀ��Դ��
https://leetcode.cn/problems/assign-cookies/description/
���
https://programmercarl.com/0455.%E5%88%86%E5%8F%91%E9%A5%BC%E5%B9%B2.html#%E6%80%9D%E8%B7%AF
*/

/*
̰���㷨 ,һ���Ǳ������ӵ�θ�� 
*/
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int index = s.size() - 1; // ����������±�
        int result = 0;
        for (int i = g.size() - 1; i >= 0; i--) { // ����θ��
            if (index >= 0 && s[index] >= g[i]) { // ��������
                result++;
                index--;
            }
        }
        return result;
    }
};

/*
̰���㷨���������ɣ��ռ临�ӶȺ�ʱ�临�ӶȲ�̫�� 
*/
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int result = 0;
        int g_index = g.size() - 1;
        int s_index = s.size() - 1;
        for(int i = s_index; i >= 0; i --){
            for(int j = g_index; j >= 0; j --){
                if(g[j] <= s[i]){
                    g_index = j - 1;
                    result ++;
                    break;
                }
            }
        }
    return result;
    }
};
