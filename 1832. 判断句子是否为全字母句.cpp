/*
��Ŀ��Դ��
https://leetcode.cn/problems/check-if-the-sentence-is-pangram/description/ 
*/
/*
��һ����������¼������ĸ�Ĵ������ñ���differ����¼��δ���ֹ�����ĸ���������ĸ��һ�γ��ֵ�ʱ��differ--,����ж�differ�Ƿ����0 
*/
class Solution {
public:
    bool checkIfPangram(string sentence) {
        int differ = 26;
        int a[26] = {0};
        for(int i =0; i < sentence.size(); i ++){
            if(a[sentence[i] - 'a'] == 0){
                differ --;
            }
            a[sentence[i] - 'a'] ++;
        }
        if(differ == 0){
            return true;
        }
        return false;
    }
};
