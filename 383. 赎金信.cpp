/*
������Դ��
https://leetcode.cn/problems/ransom-note/description/
�ⷨ��
https://programmercarl.com/0383.%E8%B5%8E%E9%87%91%E4%BF%A1.html#%E6%80%9D%E8%B7%AF
 
*/

/*
�ⷨ�������ǹ�ϣ������������ķ�ʽ����������need�����¼ransomNote�������ĸ���� 
*/
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
            int need[26] = {0};
            for(int i =0; i < ransomNote.size(); i ++){
                need[ransomNote[i] - 'a'] ++;
            }
            for(int i = 0; i < magazine.size(); i ++){
                need[magazine[i] - 'a'] --;
            }
            for(int i =0; i < 26; i ++){
                if(need[i] > 0){
                    return false;
                }
            }
            return true;
    }
};
/*
�����ⷨ����record�����¼magazine�����ṩ����ĸ���� 
*/
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int record[26] = {0};
        //add
        if (ransomNote.size() > magazine.size()) {
            return false;
        }
        for (int i = 0; i < magazine.length(); i++) {
            // ͨ��record���ݼ�¼ magazine������ַ����ִ���
            record[magazine[i]-'a'] ++;
        }
        for (int j = 0; j < ransomNote.length(); j++) {
            // ����ransomNote����record���Ӧ���ַ�������--����
            record[ransomNote[j]-'a']--;
            // ���С����˵��ransomNote����ֵ��ַ���magazineû��
            if(record[ransomNote[j]-'a'] < 0) {
                return false;
            }
        }
        return true;
    }
};
